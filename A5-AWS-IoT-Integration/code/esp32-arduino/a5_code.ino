#include <Adafruit_MPU6050.h>
#include <Adafruit_Sensor.h>
#include <Wire.h>
#include <SD.h>
#include <SPI.h>
#include <MFRC522.h>
#include <Adafruit_SSD1306.h>
#include <WiFi.h>
#include <time.h>
#include <ESP32_AWS_MQTT_Manager.h>

const char* aws_endpoint = "mqtts://a1d7jhn4pw5by7-ats.iot.us-east-1.amazonaws.com:8883";

const char* PUB_TOPIC = "truck/1/telemetry";

// User: Paste the contents of your aws_root_ca.pem here
const char AWS_ROOT_CA[] = R"EOF(
-----BEGIN CERTIFICATE-----
MIIDQTCCAimgAwIBAgITBmyfz5m/jAo54vB4ikPmljZbyjANBgkqhkiG9w0BAQsF
ADA5MQswCQYDVQQGEwJVUzEPMA0GA1UEChMGQW1hem9uMRkwFwYDVQQDExBBbWF6
b24gUm9vdCBDQSAxMB4XDTE1MDUyNjAwMDAwMFoXDTM4MDExNzAwMDAwMFowOTEL
MAkGA1UEBhMCVVMxDzANBgNVBAoTBkFtYXpvbjEZMBcGA1UEAxMQQW1hem9uIFJv
b3QgQ0EgMTCCASIwDQYJKoZIhvcNAQEBBQADggEPADCCAQoCggEBALJ4gHHKeNXj
ca9HgFB0fW7Y14h29Jlo91ghYPl0hAEvrAIthtOgQ3pOsqTQNroBvo3bSMgHFzZM
9O6II8c+6zf1tRn4SWiw3te5djgdYZ6k/oI2peVKVuRF4fn9tBb6dNqcmzU5L/qw
IFAGbHrQgLKm+a/sRxmPUDgH3KKHOVj4utWp+UhnMJbulHheb4mjUcAwhmahRWa6
VOujw5H5SNz/0egwLX0tdHA114gk957EWW67c4cX8jJGKLhD+rcdqsq08p8kDi1L
93FcXmn/6pUCyziKrlA4b9v7LWIbxcceVOF34GfID5yHI9Y/QCB/IIDEgEw+OyQm
jgSubJrIqg0CAwEAAaNCMEAwDwYDVR0TAQH/BAUwAwEB/zAOBgNVHQ8BAf8EBAMC
AYYwHQYDVR0OBBYEFIQYzIU07LwMlJQuCFmcx7IQTgoIMA0GCSqGSIb3DQEBCwUA
A4IBAQCY8jdaQZChGsV2USggNiMOruYou6r4lK5IpDB/G/wkjUu0yKGX9rbxenDI
U5PMCCjjmCXPI6T53iHTfIUJrU6adTrCC2qJeHZERxhlbI1Bjjt/msv0tadQ1wUs
N+gDS63pYaACbvXy8MWy7Vu33PqUXHeeE6V/Uq2V8viTO96LXFvKWlJbYK8U90vv
o/ufQJVtMVT8QtPHRh8jrdkPSHCa2XV4cdFyQzR1bldZwgJcJmApzyMZFo6IQ6XU
5MsI+yMRQ+hDKXJioaldXgjUkK642M4UwtBV8ob2xJNDd2ZhwLnoQdeXeGADbkpy
rqXRfboQnoZsG4q5WTP468SQvvG5
-----END CERTIFICATE-----
)EOF";

// User: Paste the contents of your client.crt here
const char CLIENT_CERT[] = R"EOF(
-----BEGIN CERTIFICATE-----
MIIDWTCCAkGgAwIBAgIUXNCTmPCMwdG3I95lIqQnQN5jILAwDQYJKoZIhvcNAQEL
BQAwTTFLMEkGA1UECwxCQW1hem9uIFdlYiBTZXJ2aWNlcyBPPUFtYXpvbi5jb20g
SW5jLiBMPVNlYXR0bGUgU1Q9V2FzaGluZ3RvbiBDPVVTMB4XDTI2MDUyNTA2MzY1
NVoXDTQ5MTIzMTIzNTk1OVowHjEcMBoGA1UEAwwTQVdTIElvVCBDZXJ0aWZpY2F0
ZTCCASIwDQYJKoZIhvcNAQEBBQADggEPADCCAQoCggEBAKtr8s7PImYbhYZDm1TQ
3q1CCmARtm1JM9Spx1hnvxOJ+IhdIXdLsufCWvK5PJhjOxMHEUa/YVi2N58M9zC0
3Av9H5nwgwU03Zj7FVIIb4k0QwiUZOWd4dJRmeQzubby/EQ3v8vHCUQV7h4e12ms
Hub0F0GigshMD0q6EWctJE5NAFwEd/4sz/mAW7RZ1oEBksSRVbPc6f8i5u6Ew/ha
UN+VMyM8H0LDt4O4ANLQxWIKRsgta9hPYyZVMEHIq3J2+TQz74akpz3V0djBfIQW
z0zAZQYXkSMQDxuIY557FBlN90ZNfLdMWM9sm0iVyRXlEWeF5I3ZRkcYbjaa5Dur
uucCAwEAAaNgMF4wHwYDVR0jBBgwFoAUFaoPDyEWgD5cIFjEqI/QboIv/xwwHQYD
VR0OBBYEFHx6B4tU9Og+cBC61b0n9m+WRMQqMAwGA1UdEwEB/wQCMAAwDgYDVR0P
AQH/BAQDAgeAMA0GCSqGSIb3DQEBCwUAA4IBAQBfL1mCgCF7I3qeviw6mpwf4Iek
cF1B74Ntg9xqmoP090QC3Wp5S6ddGKYogO+SoBFxLChzX2jCXH265pQNo1dfDkUg
c/BCLPT7PBYgiKc6o6KM6RbvwJRxYaT49KJLNq7qR0TtIMTNdZkmkHdX0v8nmIUl
3qTGTw7EZVKEaH0YPMHox75ohmRauOu9NBJpyt9aIj10NT7G6MHRYXTIBSzjmklm
6Sa4RACuS8BeTp/5pRX9X2OtbH4bjfuj2/10kXkyTag2cELXmEywdEtmyYfw92nB
2kJyX+oNFwOux9s7SkjZLJq1lCX8wvzMDEc/JmEWJS6Jl/xdRi4kL2w2VmOC
-----END CERTIFICATE-----
)EOF";

// User: Paste the contents of your client.key here
const char CLIENT_PRIVATE_KEY[] = R"EOF(
-----BEGIN RSA PRIVATE KEY-----
MIIEogIBAAKCAQEAq2vyzs8iZhuFhkObVNDerUIKYBG2bUkz1KnHWGe/E4n4iF0h
d0uy58Ja8rk8mGM7EwcRRr9hWLY3nwz3MLTcC/0fmfCDBTTdmPsVUghviTRDCJRk
5Z3h0lGZ5DO5tvL8RDe/y8cJRBXuHh7Xaawe5vQXQaKCyEwPSroRZy0kTk0AXAR3
/izP+YBbtFnWgQGSxJFVs9zp/yLm7oTD+FpQ35UzIzwfQsO3g7gA0tDFYgpGyC1r
2E9jJlUwQcircnb5NDPvhqSnPdXR2MF8hBbPTMBlBheRIxAPG4hjnnsUGU33Rk18
t0xYz2ybSJXJFeURZ4XkjdlGRxhuNprkO6u65wIDAQABAoIBAFo+vFdQCOYEeykS
EoZ2Z6SC7f9hk865CQZeU0ohZCCfNC5mCSZKvebxFPxPtKztIL6Fq/y46EDRvTqI
kuIbdPUCz041pmRpTngpRzImqsFquBeeN/gCRE57Ey9mY9EC3vfy+ZAIOsKTYQaO
ag2BxcsEmfG94mgcUrieeGb/BuwJFQZHC9tb0rwwB6LRjh78v+uPTX5mjQk3C3Lp
xCDc8u3Ms2tKvT7tJEDiF2aO8F0TyrplBYh6Cs00r3CanVXGNtyfyg6EDED7R078
Jo9nBaO7XrMefvaEDQR6+bYeH2JuiTKrjz0A/V3Xu/Rcc3aBtDWZEq7Rlg9xlBsY
Z07M+XECgYEA2FC58xhHcULEtC2OAiwfxlxff4aWrAAICJbwl7QiDx2HWFhQdT3D
XWW3Mt+JscnAJrSFJfkpDmeFpcZxZM7XjUjm1nDxntPDg7UTxra5NJR+0fXF/Osn
E/2lb/C6KNGIm23SpE3gKyVpY3nZx+J0azYJh4CeV1ywgC6fBvmIkQUCgYEAyt7J
R23M7aKTM9/TYDi5gHwV7h2S2Vcl/k6i4t1T9tOkVdBhYjZt+qcxnDezeU5i9+tL
jg5IqSEsE570sjWaujypmo8d/eo+4bBRjxLoXORSl6kR4uQeFLYY+1uK82D0W+GV
+Rl6tCZ630Xov2yYDuSIRxb2i5nBOUdFfvkBT/sCgYBA//jwWFJXcVXEQpASjQm7
RFSZ8GpkItpHInwHSeSWICxkWp1KrZWAAimLiupIVzR7LPF5mKZCos7hIoE+Zn0V
AlwDAgtIy59Le2UG6C884oY9NxoYRt0GP8ivm2mFDHl9IwIRxyjeLi696oaLbrvG
34T7h6WM4NhUnC3DHcZwtQKBgAd2mLsK/A4F/Bpdcp5Il/J1Hi1rYxqhzSEE7ZMh
B1S+Rn5tsxd03yjoe7e+iNi+nH94ZYgtWFj4gnGaWHAx7qZJUwf/md/cfUG6RdXY
oTnBoJQ5wRGyyLSEWnjszjjT6Ul0DBtk55G3FLAgF0brjNCHccgDvUA3gNdFmvXn
3Td/AoGAWnBHKrPH45NCwojQwEK6pnVRZOSPH9UTklA2ZOpF2hPGFq3h+uprKQXe
QbgizNLRLbeXHN4THiDNtEekYevklPt6sevdU5GzNibZXHFKG2a9UsLTLYRhC2V2
QyQfy1RD9H+3sYAntEFj+N7EvSCiXoL1kx8b1R3Rl9QjMUFQnbQ=
-----END RSA PRIVATE KEY-----
)EOF";

const unsigned long PUBLISH_INTERVAL = 5000; 

#define SS_PIN 5
#define RST_PIN 0
#define CS_PIN 13
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET 4

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);
Adafruit_MPU6050 mpu;
File logFile;
MFRC522 rfid(SS_PIN, RST_PIN);

const int redLEDPin = 34;
const int greenLEDPin = 35;
const int buzzerPin = 32;

const int RGBLEDR = 25;
const int RGBLEDG = 26;
const int RGBLEDB = 27;

const int servo = 14;

void setup() {
  Serial.begin(115200);

  while(!Serial) {
    delay(10);
  };

   Serial.print("Connecting to Wi-Fi...");
  WiFi.begin("Wokwi-GUEST", "", 6);
  while (WiFi.status() != WL_CONNECTED) { 
    delay(500); 
    Serial.print("."); 
  }
  Serial.println("\nWi-Fi Connected!");

  Serial.print("Syncing time via NTP...");
  configTime(0, 0, "pool.ntp.org", "time.nist.gov");
  struct tm timeinfo;
  while (!getLocalTime(&timeinfo)) { 
    delay(1000); 
    Serial.print("."); 
  }
  Serial.println("\nTime synced!");

  esp_err_t init_status = mqtt_manager_init(aws_endpoint, AWS_ROOT_CA, CLIENT_CERT, CLIENT_PRIVATE_KEY);

  SPI.begin();
  rfid.PCD_Init();

  Serial.println("vibration sensing and anomaly detection, starting...");

  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println("failed to initialise oled display");
    while (true) {
      delay(10);
    }
  }

  if (!SD.begin(CS_PIN)) {
    Serial.println("failed to initialise sd card");
    while (true) {
      delay(10);
    }
  }

  Serial.println("successfully initialised sd card!");
  logFile = SD.open("/log.csv", FILE_WRITE);

  if (logFile) {
    Serial.println("log.csv file created!");
    logFile.close();
  }
  else {
    Serial.println("failed to create log.csv");
  }

  if (!mpu.begin()) {
    Serial.println("failed to initialise the mpu6050");
    while (true) {
      delay(10);
    }
  }

  Serial.println("found the mpu6050!");

  mpu.setAccelerometerRange(MPU6050_RANGE_8_G);
  mpu.setGyroRange(MPU6050_RANGE_500_DEG);
  mpu.setFilterBandwidth(MPU6050_BAND_21_HZ);

  pinMode(redLEDPin, OUTPUT);
  pinMode(greenLEDPin, OUTPUT);
  pinMode(buzzerPin, OUTPUT);

  pinMode(RGBLEDR, OUTPUT);
  pinMode(RGBLEDG, OUTPUT);
  pinMode(RGBLEDB, OUTPUT);

  pinMode(servo, INPUT);

  Serial.println("");
  delay(100);
}

float temperature = 0.0;

float rawAccelerationX = 0.0;
float rawAccelerationY = 0.0;
float rawAccelerationZ = 0.0;

float avgAccelerationX = 0.0;
float avgAccelerationY = 0.0;
float avgAccelerationZ = 0.0;

float minVibrationThreshold = -4.0;
float maxVibrationThreshold = 4.0;

int i = 0;

void loop() {
  // AdjustServo();
  VibrationMonitoring();
  TemperatureSensing();
  CheckRFID();
  UpdateDisplay();
  PublishData();
  delay(100);
}

void logAnomaly() {
  logFile = SD.open("/log.csv", FILE_WRITE);

  if (!logFile) {
    Serial.println("failed to open log.csv!");
    return;
  }

  logFile.println("rawAccelerationX,rawAccelerationY,rawAccelerationZ");
  logFile.print(rawAccelerationX);
  logFile.print(",");
  logFile.print(rawAccelerationY);
  logFile.print(",");
  logFile.print(rawAccelerationZ);
  logFile.println("");

  logFile.println("avgAccelerationX,avgAccelerationY,avgAccelerationZ");
  logFile.print(avgAccelerationX);
  logFile.print(",");
  logFile.print(avgAccelerationY);
  logFile.print(",");
  logFile.print(avgAccelerationZ);
  logFile.println("");

  logFile.close();
}

const float A = 0.00499541605663;
const float B = -0.000642369100009;
const float C = 0.00000769583096696;

void TemperatureSensing() {
  int analogValue = analogRead(33);

  float kelvin = 1 / (A + B * log(analogValue) + C * pow(log(analogValue), 3));
  float celsius = kelvin - 273.15;

  // testing code
  // Serial.println(analogValue);
  Serial.println(celsius);

  if (celsius < 60.0) {
    // rgb green
    analogWrite(RGBLEDR, 255);
    analogWrite(RGBLEDG, 0);
    analogWrite(RGBLEDB, 255);
  }
  else if (celsius >= 60.0 && celsius < 79.9) {
    // rgb yellow
    analogWrite(RGBLEDR, 0);
    analogWrite(RGBLEDG, 0);
    analogWrite(RGBLEDB, 255);
  }
  else if (celsius >= 79.9) {
    // rgb red
    analogWrite(RGBLEDR, 0);
    analogWrite(RGBLEDG, 255);
    analogWrite(RGBLEDB, 255);
  }

  temperature = celsius;
}

void VibrationMonitoring() {
  sensors_event_t a, g, temp;
  mpu.getEvent(&a, &g, &temp);

  rawAccelerationX = a.acceleration.x;
  rawAccelerationY = a.acceleration.y;
  rawAccelerationZ = a.acceleration.z;

  // "moving average filter"
  // takes 5 readings and then outputs the average

  if (i<=3) {
    avgAccelerationX += rawAccelerationX;
    avgAccelerationY += rawAccelerationY;
    avgAccelerationZ += rawAccelerationZ;

    i++;
  }
  else {
    avgAccelerationX /= i;
    avgAccelerationY /= i;
    avgAccelerationZ /= i;

    i = 0;

    Serial.println("rawAccelerationX,rawAccelerationY,rawAccelerationZ");
    Serial.print(rawAccelerationX);
    Serial.print(",");
    Serial.print(rawAccelerationY);
    Serial.print(",");
    Serial.print(rawAccelerationZ);
    Serial.println("");
    Serial.println("avgAccelerationX,avgAccelerationY,avgAccelerationZ");
    Serial.print(avgAccelerationX);
    Serial.print(",");
    Serial.print(avgAccelerationY);
    Serial.print(",");
    Serial.print(avgAccelerationZ);
    Serial.println("");
  }

  // because this is written for a wokwi simulation,
  // i dont have a good basis for comfortable vibration thresholds
  // so, i will just make up things that i think sound "reasonable"

  if ((avgAccelerationX > maxVibrationThreshold || avgAccelerationX < minVibrationThreshold)
   || (avgAccelerationY > maxVibrationThreshold || avgAccelerationY < minVibrationThreshold)
   || (avgAccelerationZ > maxVibrationThreshold || avgAccelerationZ < minVibrationThreshold)) {
    // Serial.println("high vibrations detected!!!");
    // logAnomaly();
  }
}

void CheckRFID() {
  if (!rfid.PICC_IsNewCardPresent()) {
    return;
  }
  if (!rfid.PICC_ReadCardSerial()) {
    return;
  }

  Serial.print("uid = ");

  String content = "";
  byte letter;
  for (byte i = 0; i < rfid.uid.size; i++) {
    Serial.print(rfid.uid.uidByte[i] < 0x10 ? "0" : " ");
    Serial.print(rfid.uid.uidByte[i], HEX);
    content.concat(String(rfid.uid.uidByte[i] < 0x10 ? "0" : " "));
    content.concat(String(rfid.uid.uidByte[i], HEX));
  }

  Serial.println();
  Serial.print("msg = ");
  content.toUpperCase();

  if (content.substring(1) == "11 22 33 44") {
    Serial.println("Authorised access!");
    Serial.println();

    digitalWrite(greenLEDPin, HIGH);

    DisplayAccess(true);
    tone(buzzerPin, 500);
    delay(250);
    tone(buzzerPin, 900);
    delay(250);
    noTone(buzzerPin);
    DisplayAccess(true);
    
    digitalWrite(greenLEDPin, LOW);
  }
  else {
    Serial.println("Access denied!!!");

    digitalWrite(redLEDPin, HIGH);
    
    DisplayAccess(false);
    tone(buzzerPin, 250);
    delay(500);
    noTone(buzzerPin);
    DisplayAccess(false);

    digitalWrite(redLEDPin, LOW);
  }

  UpdateDisplay();
}

bool isDumpBedOpen = false;

void AdjustServo() {
  
  if (isDumpBedOpen) {
    analogWrite(servo, 180);
  }
  else {
    analogWrite(servo, -180);
  }
  
  isDumpBedOpen = !isDumpBedOpen;
}

void DisplayAccess(bool isAuthorised) {
  display.clearDisplay();

  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(25, 25);
  display.cp437(true);

  display.clearDisplay();
  if (isAuthorised) {
    display.println("ACCESS GRANTED");
  }
  else {
    display.println("ACCESS DENIED");
  }

  display.display();
}

void UpdateDisplay() {
  display.clearDisplay();

  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(0, 0);
  display.cp437(true);

  display.print("temp: ");
  display.println(temperature);
  display.print("raw x: ");
  display.print(rawAccelerationX);
  display.print(", y: ");
  display.print(rawAccelerationY);
  display.print(", z: ");
  display.print(rawAccelerationZ);
  display.println("");

  isDumpBedOpen ? display.println("Bed is open") : display.println("Bed is closed");

  display.display();
}

void PublishData() {
  static unsigned long last_publish = 0;
  
  // Publish simulated telemetry data at the set interval
  if (millis() - last_publish >= PUBLISH_INTERVAL) {
    last_publish = millis();
    
    // Safety check: ensure Wi-Fi is still connected before trying to publish
    if (WiFi.status() != WL_CONNECTED) {
      Serial.println("ERROR: Wi-Fi disconnected. Cannot publish.");
      return;
    }
    
    String payload = "{\"temp\":\"" + String(temperature) + "\", \"accelerometer\":{\"rawX\":\"" + String(rawAccelerationX) + "\", \"rawY\":\"" + String(rawAccelerationY) + "\", \"rawZ\":\"" + String(rawAccelerationZ) + "\"}}";
    
    Serial.println("Attempting to publish: " + payload);
    
    // Send it to AWS
    esp_err_t err = mqtt_manager_action(MQTT_MANAGER_ACTION_PUBLISH, PUB_TOPIC, payload.c_str());
    
    // Check for queue overflows or errors
    if (err == ESP_OK) {
      Serial.println("Message queued successfully.\n");
    } 
    else if (err == ESP_ERR_NO_MEM) {
      Serial.println("ERROR: Queue is FULL! Check AWS connection/policy.\n");
    } 
    else {
      Serial.printf("ERROR: Publish failed with code: %d\n\n", err);
    }
  }
}

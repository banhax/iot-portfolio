#include <Adafruit_MPU6050.h>
#include <Adafruit_Sensor.h>
#include <Wire.h>
#include <SD.h>
#include <SPI.h>
#include <MFRC522.h>
#include <Adafruit_SSD1306.h>

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

float celsius = 0.0;

void TemperatureSensing() {
  int analogValue = analogRead(12);

  float kelvin = 1 / (A + B * log(analogValue) + C * pow(log(analogValue), 3));
  celsius = kelvin - 273.15;

  // testing code
  // Serial.println(analogValue);
  // Serial.println(celsius);

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
  display.println(celsius);
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

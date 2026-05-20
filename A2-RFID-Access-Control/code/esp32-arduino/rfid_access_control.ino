#include <SPI.h>
#include <MFRC522.h>

#define SS_PIN 5
#define RST_PIN 0

MFRC522 rfid(SS_PIN, RST_PIN);

const int redLEDPin = 34;
const int greenLEDPin = 35;
const int buzzerPin = 22;

void setup() {
  Serial.begin(115200);
  SPI.begin();
  rfid.PCD_Init();
  Serial.println("tap card fr");
  Serial.println();

  pinMode(redLEDPin, OUTPUT);
  pinMode(greenLEDPin, OUTPUT);
  pinMode(buzzerPin, OUTPUT);
}

void loop() {
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

    tone(buzzerPin, 500);
    delay(250);
    tone(buzzerPin, 900);
    delay(250);
    noTone(buzzerPin);

    digitalWrite(greenLEDPin, LOW);

    delay(3000);
  }
  else {
    Serial.println("Access denied!!!");

    digitalWrite(redLEDPin, HIGH);
    
    tone(buzzerPin, 250);
    delay(500);
    noTone(buzzerPin);

    digitalWrite(redLEDPin, LOW);

    delay(3000);
  }
}


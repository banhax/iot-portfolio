#include <Adafruit_MPU6050.h>
#include <Adafruit_Sensor.h>
#include <Wire.h>
#include <SD.h>

#define CS_PIN 5

Adafruit_MPU6050 mpu;
File logFile;

void setup() {
  Serial.begin(115200);

  while(!Serial) {
    delay(10);
  };

  Serial.println("vibration sensing and anomaly detection, starting...");

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
  Serial.print("accelerometer range set: ");

  switch (mpu.getAccelerometerRange()) {
    case MPU6050_RANGE_2_G:
      Serial.println("+-2G");
      break;
    case MPU6050_RANGE_4_G:
      Serial.println("+-4G");
      break;
    case MPU6050_RANGE_8_G:
      Serial.println("+-8G");
      break;
    case MPU6050_RANGE_16_G:
      Serial.println("+-16G");
      break;
  }

  mpu.setGyroRange(MPU6050_RANGE_500_DEG);
  Serial.print("gyro range set: ");

  switch (mpu.getGyroRange()) {
    case MPU6050_RANGE_250_DEG:
      Serial.println("+-250 deg/s");
      break;
    case MPU6050_RANGE_500_DEG:
      Serial.println("+-500 deg/s");
      break;
    case MPU6050_RANGE_1000_DEG:
      Serial.println("+-1000 deg/s");
      break;
    case MPU6050_RANGE_2000_DEG:
      Serial.println("+-2000 deg/s");
      break;
  }

  mpu.setFilterBandwidth(MPU6050_BAND_21_HZ);
  Serial.print("filter bandwidth set: ");

  switch (mpu.getFilterBandwidth()) {
    case MPU6050_BAND_260_HZ:
      Serial.println("260 Hz");
      break;
    case MPU6050_BAND_184_HZ:
      Serial.println("184 Hz");
      break;
    case MPU6050_BAND_94_HZ:
      Serial.println("94 Hz");
      break;
    case MPU6050_BAND_44_HZ:
      Serial.println("44 Hz");
      break;
    case MPU6050_BAND_21_HZ:
      Serial.println("21 Hz");
      break;
    case MPU6050_BAND_10_HZ:
      Serial.println("10 Hz");
      break;
    case MPU6050_BAND_5_HZ:
      Serial.println("5 Hz");
      break;
  }

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

    Serial.println("-= average acceleration =-");
    Serial.print("  x: ");
    Serial.println(avgAccelerationX);
    Serial.print("  y: ");
    Serial.println(avgAccelerationY);
    Serial.print("  z: ");
    Serial.println(avgAccelerationZ);

    Serial.println("");
  }

  // because this is written for a wokwi simulation,
  // i dont have a good basis for comfortable vibration thresholds
  // so, i will just make up things that i think sound "reasonable"

  if ((avgAccelerationX > maxVibrationThreshold || avgAccelerationX < minVibrationThreshold)
   || (avgAccelerationY > maxVibrationThreshold || avgAccelerationY < minVibrationThreshold)
   || (avgAccelerationZ > maxVibrationThreshold || avgAccelerationZ < minVibrationThreshold)) {
    Serial.println("high vibrations detected!!!");
    logAnomaly();
  }

  delay(500);
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

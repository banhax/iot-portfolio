const int pinR = 25;
const int pinG = 26;
const int pinB = 27;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);

  pinMode(pinR, OUTPUT);
  pinMode(pinG, OUTPUT);
  pinMode(pinB, OUTPUT);
}

const float A = 0.00499541605663;
const float B = -0.000642369100009;
const float C = 0.00000769583096696;

void loop() {
  int analogValue = analogRead(A6);

  float kelvin = 1 / (A + B * log(analogValue) + C * pow(log(analogValue), 3));
  float celsius = kelvin - 273.15;

  // testing code
  // Serial.println(analogValue);
  // Serial.println(celsius);

  if (celsius < 60.0) {
    // rgb green
    analogWrite(pinR, 255);
    analogWrite(pinG, 0);
    analogWrite(pinB, 255);
  }
  else if (celsius >= 60.0 && celsius < 79.9) {
    // rgb yellow
    analogWrite(pinR, 0);
    analogWrite(pinG, 0);
    analogWrite(pinB, 255);
  }
  else if (celsius >= 79.9) {
    // rgb red
    analogWrite(pinR, 0);
    analogWrite(pinG, 255);
    analogWrite(pinB, 255);
  }

  delay(500);
}

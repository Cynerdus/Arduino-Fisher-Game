#include <Servo.h>

const int SW_pin = 2;
const int X_pin = 0;
const int Y_pin = 1;

const int photocell = A2;
const int ledPin = 10;

Servo myservo;

int pos = 160;
int value;

void setup() {
  myservo.attach(9);

  pinMode(ledPin, OUTPUT);
  pinMode(photocell, INPUT);

  pinMode(SW_pin, INPUT);
  digitalWrite(SW_pin, HIGH);
  Serial.begin(9600);
}

void loop() {

  while(analogRead(X_pin) > 600) {
    if (pos > 0)
      pos--;
    myservo.write(pos);
    delay(15);
  }

  while(analogRead(X_pin) < 400) {
    if (pos < 160)
      pos++;
    myservo.write(pos);
    delay(15);
  }

  value = analogRead(photocell);
  if (value < 30) {
    digitalWrite(ledPin, LOW);
    Serial.println("X-axis: ");
    Serial.println(analogRead(X_pin));
  }
  else {
    digitalWrite(ledPin, HIGH);
    Serial.println("Caught a fish!");
  }

  delay(50);
}

/*
  Author: Atharv Koratkar
  RC Car Joystick Code
*/

#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

RF24 radio(8, 9);  // CE, CSN
int xPin = A8;
int yPin = A0;

int buttonPin = 6;

const byte address[6] = "00001";

struct Data_Package {
  int leftXValue = 0;
  int rightYValue = 0;
  int buttonValue = 0;

};

int middleXValue = 513;
int middleYValue = 512;
int maxServoAngle = 115;
int minServoAngle = 60;

Data_Package joyData;

void setup() {

  Serial.begin(9600);
  pinMode(xPin, INPUT);
  pinMode(yPin, INPUT);
  pinMode(buttonPin, INPUT);
  radio.begin();
  radio.openWritingPipe(address);
  radio.setPALevel(RF24_PA_MIN);
  radio.stopListening();
}

void loop() {

  int yValue = analogRead(yPin);
  int servoAngle = map(yValue, 0, 1023, maxServoAngle, minServoAngle);
  int butValue = digitalRead(buttonPin);

  joyData.leftXValue = analogRead(xPin);
  joyData.rightYValue = servoAngle;
  joyData.buttonValue = butValue;

 
  radio.write(&joyData, sizeof(Data_Package));

}

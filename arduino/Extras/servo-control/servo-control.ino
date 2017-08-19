/**************************************
 Controlling a Servo Motor
 
 Dependenices: servo library

 Servos can only move 0 - 180

  Misbehaving servo?
  https://learn.adafruit.com/adafruit-arduino-lesson-14-servo-motors/if-the-servo-misbehaves
  
**************************************/
#include <Servo.h>

Servo myservo;

int sensorPin = A0;     // analog pin because reading a voltage (range of numbers)
int sensorValue = 0;    // variable for reading the sensor

void setup() {
  
  // set up servo pin
  myservo.attach(10);

  // start serial communications at 9600 baud
  Serial.begin(9600);
  
}

void loop() {
  // main program goes here
  
  sensorValue = analogRead(sensorPin);
  Serial.print(sensorValue);      // print out the value
  sensorValue = map(sensorValue, 0, 600, 0, 180);
  Serial.print(", Mapped to: ");
  Serial.println(sensorValue);
  myservo.write(sensorValue); 
  delay(100);

}

/**************************************
 Controlling a Servo Motor
 
 Dependenices: servo library

 Servos can only move 0 - 180

 Misbehaving servo?
 https://learn.adafruit.com/adafruit-arduino-lesson-14-servo-motors/if-the-servo-misbehaves
  
**************************************/
#include <Servo.h>

Servo myservo;

int knobPin = A0;     // analog pin because reading a voltage (range of numbers)
int knobValue = 0;    // variable for reading the sensor

void setup() {
  
  // set up servo pin
  myservo.attach(10);

  // start serial communications at 9600 baud
  Serial.begin(9600);
  
}

void loop() {
  // main program goes here
  
  knobValue = analogRead(knobPin);
  Serial.print(knobValue);
  knobValue = map(knobValue, 0, 600, 0, 180); // maps values to range of servo
  Serial.print(", Mapped to: ");
  Serial.println(knobValue);
  myservo.write(knobValue); 
  delay(50);

}

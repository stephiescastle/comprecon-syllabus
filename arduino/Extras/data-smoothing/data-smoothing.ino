
#include "Smoother.h"
Smoother mySmoother = Smoother(40);

int rawData = 0;
int smoothData = 0;

int inputPin = A0;

void setup() {
  // initialize serial communication with computer:
  Serial.begin(9600);
}

void loop() {
 
  rawData = analogRead(inputPin);
  smoothData = mySmoother.average(rawData);
  // send it to the computer as ASCII digits
  Serial.println(smoothData);

// debug style
//  Serial.print("Raw:    ");
//  Serial.println(rawData);
//  Serial.print("Smooth: ");
//  Serial.println(smoothData);
//  Serial.println("----------------");

}







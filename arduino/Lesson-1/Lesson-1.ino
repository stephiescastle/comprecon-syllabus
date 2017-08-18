/**************************************
  Lesson 1: Turn on the built-in LED

  Materials
  - 1 arduino (uno)
  - 1 usb cable
  
**************************************/

int ledPin = LED_BUILTIN; // same as pin 13

void setup() { 
  // put your setup code here, which runs once
  
  // initialize digital outputs
  pinMode(ledPin, OUTPUT);

}

void loop() {
  // main program goes here

  digitalWrite(ledPin, HIGH);   // turn the ledPin on

}

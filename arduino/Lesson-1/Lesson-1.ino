/**************************************
  Lesson 1: Turn on the built-in LED

  Materials
  - 1 arduino (uno)
  - 1 usb cable
  
**************************************/

int ledPin = LED_BUILTIN; // same as pin 13

void setup() { 
  // put your setup code here, which runs once
  
  // set digital pin as output
  pinMode(ledPin, OUTPUT);

  // start serial communications at 9600 baud
  Serial.begin(9600);
  
}

void loop() {
  // main program goes here

  digitalWrite(ledPin, HIGH);   // turn the ledPin on
  Serial.println("On");

}

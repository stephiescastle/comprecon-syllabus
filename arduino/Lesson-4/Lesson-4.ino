/**************************************
 Lesson 4: Use a potentiometer (knob) to control the blink rate
  
 Additional Materials
  - 1 10K ohm resistors
  - 1 potentiometer (https://www.adafruit.com/product/356)

**************************************/

int ledPin = LED_BUILTIN; // same as pin 13

int knobPin = A0;     // analog pin because range of numbers
int knobValue = 0;    // variable for reading the knob

void setup() {
  // put your setup code here, which runs once
  
  // set digital pin as output
  pinMode(ledPin, OUTPUT);
  
  // pinMode does not need to be set for analog pins

  // start serial communications at 9600 baud
  Serial.begin(9600);
  
}

void loop() {
  // main program goes here
  
  knobValue = analogRead(knobPin);  // read the value of the knob and set it as <knobValue>
  
  digitalWrite(ledPin, HIGH);       // turn the ledPin on
  Serial.print("On, Knob=");
  Serial.println(knobValue);
  delay(knobValue);                 // stop the program for <knobValue> ms

  knobValue = analogRead(knobPin);
  
  digitalWrite(ledPin, LOW);        // turn the ledPin off
  Serial.print("Off, Knob=");
  Serial.println(knobValue);
  delay(knobValue);                 // stop the program for <knobValue> ms

}

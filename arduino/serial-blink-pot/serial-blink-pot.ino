/*
  Adaption of Arduino's "Blink" example

  - two switches
  - small potentiometer
  - LED
  - 1 resistor

  Process
  - LED on
  - blink the LED (to illustrate how it loops)
  - blink actual LED (not the builtin)
  - change blink rate w/ potentiometer
  - introduce conditional statements::::
  - if knob value is above a certain number
  - use switch to check for modes (will this require metro?)
  - use two switches to nest mode (will this require metro?)
*/

int knobPin = A0;
int ledPin = LED_BUILTIN;
int knobValue = 0;

void setup() {
  
  // put your setup code here, to run once
  
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(ledPin, OUTPUT);
  // start serial communications at 9600 baud
  Serial.begin(9600);
  
}

void loop() {
  // must read it repeatedly to repeatedly evaluate this conditional
  knobValue = analogRead(knobPin);
  
  if (knobValue < 200) {
    // read the value from the knob:
    Serial.println(knobValue);
    // turn the ledPin on
    digitalWrite(ledPin, HIGH);
    // stop the program for <knobValue> milliseconds:
    delay(knobValue);
    // turn the ledPin off:
    digitalWrite(ledPin, LOW);
    // stop the program for for <knobValue> milliseconds:
    delay(knobValue);    
  } else {
    digitalWrite(ledPin, LOW);
    Serial.print("Off, ");
    Serial.println(knobValue);
    delay(knobValue);
  }



}

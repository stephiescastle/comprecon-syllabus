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


int ledPin = LED_BUILTIN; // 13

int knobPin = A0;     // analog pin because range of numbers
int knobValue = 0;    // variable for reading the knob

int switchPin = 7;    // digital pin because binary (on/off)
int switchState = 0;  // variable for reading the switch

int buttonPin = 2;    // digital pin because binary  (on/off)
int buttonState = 0;  // variable for reading the button

void setup() {
  
  // put your setup code here, to run once
  
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(ledPin, OUTPUT);
  
  // initialize the switch pin as an input:
  pinMode(switchPin, INPUT);

  // initialize the button pin as an input:
  pinMode(buttonPin, INPUT);

  // start serial communications at 9600 baud
  Serial.begin(9600);
  
}

void loop() {
  
  // must read it repeatedly to repeatedly evaluate this conditional
  buttonState = digitalRead(buttonPin);
  

  if (buttonState == HIGH) {
    Serial.print("Button: ");
    Serial.println(buttonState);
    // just turn it on no matter what
    digitalWrite(ledPin, HIGH);
    buttonState = digitalRead(buttonPin);

    // debug. somehow can't escape this is switch is off and push button is pressed. it just stays on.
    
  } else {
    Serial.print("Button: ");
    Serial.println(buttonState);
    // do the complicated stuff
    switchState = digitalRead(switchPin);
    Serial.println(switchState);
    knobValue = analogRead(knobPin);
  
    if (switchState == 1) {
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
        delay(500);
      }    
    } else {
      // off
      digitalWrite(ledPin, LOW);
      Serial.print("Switch: ");
      Serial.println(switchState);
      delay(500);
      switchState = digitalRead(switchPin);
    } // end of switchState logic
    buttonState = digitalRead(buttonPin);
  } // end of buttonState logic

}

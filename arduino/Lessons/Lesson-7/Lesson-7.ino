/**************************************
  Lesson 7: Using Conditionals: Momentary Modes

  Additional materials
  - 1 10K ohm resistors
  - 1 momentary button (https://www.adafruit.com/product/1119)

**************************************/

int ledPin = LED_BUILTIN; // same as pin 13

int knobPin = A0;     // analog pin because range of numbers
int knobValue = 0;    // variable for reading the knob

int switchPin = 7;    // digital pin because binary (on/off)
int switchState = 0;  // variable for reading the switch

int buttonPin = 2;    // digital pin because binary  (on/off)
int buttonState = 0;  // variable for reading the button

void setup() {
  // put your setup code here, which runs once

  // set digital pin as output
  pinMode(ledPin, OUTPUT);

  // set digital pins as inputs:
  pinMode(switchPin, INPUT);
  pinMode(buttonPin, INPUT);

  // start serial communications at 9600 baud
  Serial.begin(9600);

}

void loop() {
  // main program goes here

  buttonState = digitalRead(buttonPin);   // check if button is pressed
  Serial.print("Button: ");
  Serial.println(buttonState);

  if (buttonState == HIGH) {
    // button pressed
    digitalWrite(ledPin, HIGH);           // turn the ledPin on

  } else {
    // button not pressed
    // so check if the switch is switched on
    switchState = digitalRead(switchPin);
    Serial.print("Switch: ");
    Serial.println(switchState);

    if (switchState == 1) {
      // switch is on so read the value of the knob
      knobValue = analogRead(knobPin);

      if (knobValue < 300) {
        // switch is on and knobValue is less than 300
        knobValue = analogRead(knobPin);

        digitalWrite(ledPin, HIGH);       // turn the ledPin on
        Serial.print("On, Knob=");
        Serial.println(knobValue);
        delay(knobValue);                 // stop the program for <knobValue> ms

        knobValue = analogRead(knobPin);

        digitalWrite(ledPin, LOW);        // turn the ledPin off
        Serial.print("Off, Knob=");
        Serial.println(knobValue);
        delay(knobValue);                 // stop the program for <knobValue> ms

      } else {
        // switch is on and knobValue is 300 or greater
        digitalWrite(ledPin, HIGH);       // turn the ledPin on
        Serial.print("On, Knob=");
        Serial.println(knobValue);

      } // end of knobValue if/else

    } else {
      // switch is off
      digitalWrite(ledPin, LOW);          // turn the ledPin off

    } // end of switchState if/else

  } // end of buttonState logic

}

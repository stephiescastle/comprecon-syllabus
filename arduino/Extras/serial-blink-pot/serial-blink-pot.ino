/**************************************
  Arduino Complete Lesson
  Computation Reconsidered
  Fall 2017, CalArts
  
  Full list of materials
  - 1 arduino (uno)
  - 1 usb cable
  - 1 solderless breadboard
  - 1 LED
  - 4 10K ohm resistors
  - 1 potentiometer (https://www.adafruit.com/product/356)
  - 1 bb switch (https://www.adafruit.com/product/805)
  - 1 bb momentary button (https://www.adafruit.com/product/1119)

  Process
  - LED on
  - blink the LED (to illustrate how it loops)
  - blink actual LED (not the builtin)
  - change blink rate w/ potentiometer
  - introduce conditional statements::::
  - if knob value is above a certain number
  - use switch to check for modes (will this require metro?)
  - use two switches to nest mode (will this require metro?)
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
  
  // must read it repeatedly to repeatedly evaluate this conditional
  buttonState = digitalRead(buttonPin);
  

  if (buttonState == HIGH) {
    // button pressed
    Serial.print("Button: ");
    Serial.println(buttonState);
    digitalWrite(ledPin, HIGH);       // turn the ledPin on
    
  } else { 
    // button not pressed
    Serial.print("Button: ");
    Serial.println(buttonState);
    
    // so check if the switch is switched on
    switchState = digitalRead(switchPin);
    Serial.println(switchState);

    if (switchState == 1) {
      // switch is on so read the value of the knob
      knobValue = analogRead(knobPin);
      Serial.println(knobValue);
      
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
        //knobValue is 300 or greater
        digitalWrite(ledPin, HIGH);       // turn the ledPin on
        Serial.print("On, Knob=");
        Serial.println(knobValue);
        
      } // end of knobValue if/else 
      
    } else {
      // switch is off
      digitalWrite(ledPin, LOW);      // turn the ledPin off
      Serial.print("Switch: ");
      Serial.println(switchState);
      
    } // end of switchState if/else
    
    //buttonState = digitalRead(buttonPin);
    
  } // end of buttonState logic

}

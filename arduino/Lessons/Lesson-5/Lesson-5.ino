/**************************************
 Lesson 5: Using Conditionals: Use knob range as a conditional
 
**************************************/

int ledPin = LED_BUILTIN; // same as pin 13

int knobPin = A0;     // analog pin because range of numbers
int knobValue = 0;    // variable for reading the knob

void setup() {
  // put your setup code here, which runs once
  
  // set digital pin as output
  pinMode(ledPin, OUTPUT);

  // start serial communications at 9600 baud
  Serial.begin(9600);
  
}

void loop() {
  // main program goes here

  knobValue = analogRead(knobPin);  // read the value of the knob and set it as <knobValue>

  if (knobValue < 300) { 
    // knobValue is less than 300
    
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

}

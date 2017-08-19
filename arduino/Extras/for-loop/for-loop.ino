/**************************************
  The for loop
  
  The for statement is used to repeat a block of statements 
  enclosed in curly braces. An increment counter is usually 
  used to increment and terminate the loop. 
  
  The for statement is useful for any repetitive operation, 
  and is often used in combination with arrays to operate on 
  collections of data/pins.

**************************************/

//Dim an LED using a PWM pin
int ledPin = LED_BUILTIN; // same as pin 13

// Dim an LED using a PWM pin
int ledPin = 10; // LED in series with 470 ohm resistor on pin 10

void setup()
{
  // no setup needed
}

void loop()
{
  
  // for (variable init; condition; increment) {}
  
  for (int i=0; i <= 255; i++){
    analogWrite(ledPin, i);
    delay(10);
  }
  
}


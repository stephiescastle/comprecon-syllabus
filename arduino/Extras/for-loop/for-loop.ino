/**************************************
  Example: Dim and LED using a for loop and a PWM pin 

--The for loop ------------------------
  
  The for loop repeats a block of statements. An increment 
  counter is usually used to increment and terminate the loop. 

  For loops begin with a statement that consists of
  - variable initialization (int i = x)
  - condition to check against (i <, <=, >, >= y)
  - increment rule (i++/i--)

  for (variable init; condition; increment) {}

--PWM Pins ----------------------------
  
  Pulse Width Modulation, or PWM, is a technique for getting 
  analog results with a digital pin and can output a range of
  0-255 instead of just 0 or 1.

  Technical details: https://www.arduino.cc/en/Tutorial/PWM

**************************************/

// Dim an LED using a PWM pin
int ledPin = 10; // LED in series with 470 ohm resistor on pin 10

void setup()
{
  // not necessary, but doesn't hurt
  pinMode(ledPin,INPUT);

}

void loop()
{
  
//for (variable init; condition; increment) {}  
  for (int i=0; i <= 255; i++){
    analogWrite(ledPin, i);
    delay(10);
  }

  // how to make it do the reverse?
  
}


/**************************************
  Example: Dim an LED using a while loop and a PWM pin 

--The while loop ------------------------
  
  The for loop repeats a block of statements. An increment 
  counter is usually used to increment and terminate the loop. 

  For loops begin with a statement that consists of
  - variable initialization (int i = x)
  - condition to check against (i <, <=, >, >= y)
  - increment rule (i++/i--)

  for (variable init; condition; increment) {}

  for loop vs while loop
  - fwhile loops can usually always replace a for loop, but consider the following
  - for loop's structure implies you only need that variable for that increment.
  - while loop can use another variable 
  - if all you truly want is a for loop, then might as well use it because it's 
  simpler to write, cleaner. 
  - while loops can have more complex ways to increment/ change the value of the 
  variable being evaluated.

  if only evaluates at hte beginning
  and while evaluates at the beginning and the end

  If not careful, while can freeze or block your code from doing other things
  so I tend to use if statements. It ultimately just depends on what you want
  your program to do in the end.
  

**************************************/

int ledPin = 10; // LED in series with 470 ohm resistor on pin 10

void setup()
{
  // not necessary, but doesn't hurt
  pinMode(ledPin,INPUT);

}

void loop()
{
  
  int i = 0;
  
  while (i <= 255){
    analogWrite(ledPin, i);
    delay(10);
    i++;
  }

  // how to make it do the reverse?
  
}


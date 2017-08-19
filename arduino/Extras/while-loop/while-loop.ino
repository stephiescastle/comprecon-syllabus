/**************************************
  Example: Dim an LED using a while loop and a PWM pin 

--The while loop ------------------------
  
  while loops will loop continuously, and infinitely, until the 
  expression inside the parenthesis, () becomes false. Something 
  must change the tested variable, or the while loop will never exit. 
  This could be in your code, such as an incremented variable, or an 
  external condition, such as testing a sensor.

  for loops can usually replaced by a while loop, but the structure
  of a for loop is usually easier to write and keep track of.

  If you aren't careful, a while loop can freeze or block your code 
  from doing other things so I tend to use if statements. It ultimately 
  just depends on what you want your program to do in the end.
  
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


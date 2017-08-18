/**************************************
  Lesson 2: Make built-in LED blink
  
 Materials
  - 1 solderless breadboard
  - 1 LED
  - 1 10K ohm resistors

**************************************/

int ledPin = LED_BUILTIN; // same as pin 13

void setup() {
  // put your setup code here, which runs once
  
  // initialize digital outputs
  pinMode(ledPin, OUTPUT);

  // start serial communications at 9600 baud
  Serial.begin(9600);
  
}

void loop() {
  // main program goes here
  
  digitalWrite(ledPin, HIGH);   // turn the ledPin on
  Serial.println("On");
  delay(500);                   // stop the program for 500 ms
  
  digitalWrite(ledPin, LOW);    // turn the ledPin off
  Serial.println("Off");
  delay(500);                   // stop the program for 500 ms

}

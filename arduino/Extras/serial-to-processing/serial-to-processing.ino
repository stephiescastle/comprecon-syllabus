/**************************************
 Read a sensor and sent to to Processing over serial communication
 
**************************************/

int sensorPin = A0;     // analog pin because reading a voltage (range of numbers)
int sensorValue = 0;    // variable for reading the sensor

void setup() {
  
  // start serial communications at 9600 baud
  Serial.begin(9600);
  
}

void loop() {
  // main program goes here
  
  sensorValue = analogRead(sensorPin);
  Serial.println(sensorValue);      // print out the value
  
}

import processing.serial.*;
import cc.arduino.*;

// call arduino and smoother objects
Arduino myArduino;
Smoother mySmoother;

// sensor variables
int rawData;
int smoothedData;

void setup() {
  
  // Prints out the available serial ports.
  println(Arduino.list());
  
  // initialize arduino object and set port and baudrate
  myArduino = new Arduino(this, Arduino.list()[7], 57600);
    
  // initialize smoother object and set resolution
  mySmoother = new Smoother(40);  
  
}

void draw() {
  // read from arduino pin
  rawData = myArduino.analogRead(0);
  
  // smooth the data
  smoothedData = mySmoother.average(rawData);    // smooth the raw data
  println(smoothedData);                         // print value to console

}
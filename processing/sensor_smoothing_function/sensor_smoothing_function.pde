import processing.serial.*;
import cc.arduino.*;

// variable for final sensor value
int sensorValue;

Smoother mySmoother;

// initialize arduino class
Arduino myArduino;

void setup() {
  
  // ARDUINO STUFF ------------------------------------------------------
  // Prints out the available serial ports.
  println(Arduino.list());
  
  // Modify this line, by changing the "0" to the index of the serial
  // port corresponding to your Arduino board (as it appears in the list
  // printed by the line above).
  myArduino = new Arduino(this, Arduino.list()[7], 57600);
  
  // Alternatively, use the name of the serial port corresponding to your
  // Arduino (in double-quotes), as in the following line.
  //arduino = new Arduino(this, "/dev/tty.usbmodem621", 57600);
  
  // Set the Arduino digital pins as inputs.
  //for (int i = 0; i <= 13; i++)
  //  arduino.pinMode(i, Arduino.INPUT);
  
  // SMOOTHING STUFF -----------------------------------------------------
  // initialize all the readings to 0:
  mySmoother = new Smoother();
  mySmoother.init();
  
}

void draw() {
  mySmoother.average();
  //sensorValue = smoother();               // use smoothed value
  //println(sensorValue);                // print value to console

}

class Smoother {
  
  //if (x == null) {                          // smoothing resolution
  //  int numReadings = x;
  //} else {
  //  int numReadings = 30;
  //}  
  int numReadings = 30;              
  int[] readings = new int[numReadings];  // the readings from the analog input (Array)
  int readIndex = 0;                      // the index of the current reading
  int total = 0;                          // the running total
  int average = 0;                        // the average  
  
  // run this during setup
  void init() {
    for (int thisReading = 0; thisReading < numReadings; thisReading++) {
      readings[thisReading] = 0;
    }  
  }
 
  int average() {
    total = total - readings[readIndex];          // subtract the last reading
    readings[readIndex] = myArduino.analogRead(0);  // read from the sensor
    total = total + readings[readIndex];          // add the reading to the total
    readIndex = readIndex + 1;                    // advance to the next position in the array
    
    // if we're at the end of the array...
    if (readIndex >= numReadings) {
      // ...wrap around to the beginning:
      readIndex = 0;
    }
  
    average = total / numReadings;       // calculate the average
    delay(1);                            // delay in between reads for stability
    println(average);                    // print to console
    
    return average;                    
  }  
}

//int smoother() {
  

// // delay(500);
//  // smoothing vars
//  //if (x == null) {                          // smoothing resolution
//  //  int numReadings = x;
//  //} else {
//  //  int numReadings = 30;
//  //}



//  total = total - readings[readIndex];          // subtract the last reading
//  readings[readIndex] = arduino.analogRead(0);  // read from the sensor
//  total = total + readings[readIndex];          // add the reading to the total
//  readIndex = readIndex + 1;                    // advance to the next position in the array
  
//  // if we're at the end of the array...
//  if (readIndex >= numReadings) {
//    // ...wrap around to the beginning:
//    readIndex = 0;
//  }

//  average = total / numReadings;       // calculate the average
//  //delay(1);                            // delay in between reads for stability
//  println(average);                    // print to console
  
//  return average;                    
//}
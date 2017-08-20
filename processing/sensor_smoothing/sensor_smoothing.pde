import processing.serial.*;
import cc.arduino.*;

// smoothing vars
int numReadings = 30;                   // smoothing resolution
int[] readings = new int[numReadings];  // the readings from the analog input (Array)
int readIndex = 0;                      // the index of the current reading
int total = 0;                          // the running total
int average = 0;                        // the average

// variable for final sensor value
int sensorValue;

// initialize arduino object
Arduino arduino;

void setup() {
  
  // ARDUINO STUFF ------------------------------------------------------
  // Prints out the available serial ports.
  println(Arduino.list());
  
  // Modify this line, by changing the "0" to the index of the serial
  // port corresponding to your Arduino board (as it appears in the list
  // printed by the line above).
  arduino = new Arduino(this, Arduino.list()[7], 57600);
  
  // Alternatively, use the name of the serial port corresponding to your
  // Arduino (in double-quotes), as in the following line.
  //arduino = new Arduino(this, "/dev/tty.usbmodem621", 57600);
  
  // Set the Arduino digital pins as inputs.
  //for (int i = 0; i <= 13; i++)
  //  arduino.pinMode(i, Arduino.INPUT);
  
  // SMOOTHING STUFF -----------------------------------------------------
  // initialize all the readings to 0:
  for (int thisReading = 0; thisReading < numReadings; thisReading++) {
    readings[thisReading] = 0;
  }
}

void draw() {

  total = total - readings[readIndex];          // subtract the last reading
  readings[readIndex] = arduino.analogRead(0);  // read from the sensor
  total = total + readings[readIndex];          // add the reading to the total
  readIndex = readIndex + 1;                    // advance to the next position in the array

  // if we're at the end of the array...
  if (readIndex >= numReadings) {
    // ...wrap around to the beginning:
    readIndex = 0;
  }

  average = total / numReadings;       // calculate the average
  println(average);                    // print to console
  delay(1);                            // delay in between reads for stability
  
  sensorValue = average;               // use smoothed value
  println(sensorValue);                // print value to console

}
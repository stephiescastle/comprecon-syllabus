import processing.serial.*;
import cc.arduino.*;

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

}

void draw() {
  
  sensorValue = arduino.analogRead(0); // read from the sensor
  println(sensorValue);                // print value to console
  delay(1);                            // slight delay for stability

}
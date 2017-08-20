import processing.serial.*;
import cc.arduino.*;

float sensorValue;

Arduino arduino;

void setup() {
  size(500, 400);
  background(10, 80, 100);

  // Prints out the available serial ports.
  //println(Arduino.list());
  
  // Modify this line, by changing the "0" to the index of the serial
  // port corresponding to your Arduino board (as it appears in the list
  // printed by the line above).
  arduino = new Arduino(this, Arduino.list()[3], 57600);
  
  // Alternatively, use the name of the serial port corresponding to your
  // Arduino (in double-quotes), as in the following line.
  //arduino = new Arduino(this, "/dev/tty.usbmodem621", 57600);
  
  // Set the Arduino digital pins as inputs.
  //for (int i = 0; i <= 13; i++)
  //  arduino.pinMode(i, Arduino.INPUT);
}

void draw() {
   
  sensorValue = arduino.analogRead(0); // read pin 0 on the arduino
  println(sensorValue);
  
  if (mousePressed) {
    background(10, 80, 100);
    arduino.digitalWrite(13, Arduino.HIGH);
  } else {
    arduino.digitalWrite(13, Arduino.LOW);
  }
  stroke(255, 255, 255);
  fill(160, 220, 90);
  ellipse(sensorValue, 200, 300, 300);

  fill(160, 210, 230);
  rect(245, sensorValue, 10, 240);

  fill(255, 255, 255);
  ellipse(sensorValue, sensorValue, 70, 70);      

}
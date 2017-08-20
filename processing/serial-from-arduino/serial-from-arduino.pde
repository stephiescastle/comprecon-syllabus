import processing.serial.*;

/*Arduino <--> Processing
    
  Adapted from https://learn.sparkfun.com/tutorials/connecting-arduino-to-processing
  
  In order to listen to any serial communication we have 
  to get a Serial object (we call it myPort but you can it 
  whatever you like), which lets us listen in on a serial port 
  on our computer for any incoming data. We also need a variable 
  to recieve the actual data coming in.
*/

Serial myPort;  // Create object from Serial class

String val;     // Data received from the serial port

void setup() {
  // On Macs, the serial port is usually Serial.list()[0].
  // Open whatever port is the one you're using.
  String portName = Serial.list()[3]; //change the 0 to a 1 or 2 etc. to match your port
  myPort = new Serial(this, portName, 9600); // match baudrate to arduino code
}


void draw() {
  if ( myPort.available() > 0) 
  {  // If data is available,
  val = myPort.readStringUntil('\n');         // read it and store it in val
  } 
println(val); //print it out in the console
}
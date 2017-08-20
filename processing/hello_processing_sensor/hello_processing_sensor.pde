import processing.serial.*;

Serial myPort;  // Create object from Serial class
String sensorValue;     // Data received from the serial port
float sensorFloat;

void setup() {
  size(500, 400);
  background(10, 80, 100);

  String portName = Serial.list()[3]; //change the 0 to a 1 or 2 etc. to match your port
  myPort = new Serial(this, portName, 9600); // match baudrate to arduino code
}

void draw() {
  if (mousePressed) {
    background(10, 80, 100);
  } 
    stroke(255, 255, 255);
    fill(160, 220, 90);
    ellipse(sensorFloat, 200, 300, 300);
  
    fill(160, 210, 230);
    rect(245, mouseY, 10, 240);
  
    fill(255, 255, 255);
    ellipse(sensorFloat, mouseY, 70, 70);    
    
    
    if ( myPort.available() > 0) {
      serialEvent(myPort);
    }
    println(sensorFloat);
}
void serialEvent(Serial myPort) {
  if ( myPort.available() > 0) {  // If data is available,
    sensorValue = myPort.readStringUntil('\n'); 
    sensorFloat = float(sensorValue);
  }
  
}
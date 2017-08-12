
/**
    Processing Arduino to OSC example sketch - written by Liam Lacey (http://liamtmlacey.tumblr.com)

    This processing sketch allows communication to and from the Arduino (using the processing arduino library), 
    and then converts the data into/from OSC (using the oscP5 library) to communicate to/from other OSC compatible software/hardware, e.g. Max/MSP.
    
    In this example sketch, all analog pins are being read, as well as digital pins 2, 4 and 7.
    Digital pins 3, 5 and 6 are used as PWM pins, and the rest of the digital pins (8-13) are set to regular output pins.
    

 * In order for this sketch to communicate with the Arduino board, the StandardFirmata Arduino sketch must be uploaded onto the board
   (Examples > Firmata > StandardFirmata)

 * OSC code adapted from 'oscP5sendreceive' by andreas schlegel
 * Arduino code taken from the tutorial at http://www.arduino.cc/playground/Interfacing/Processing
  
 * Source: http://liamtmlacey.blogspot.com/2011/03/arduino-to-maxmsp-via-osc-guide-and.html 

 */
 
 
//libraries needed for arduino communication
import processing.serial.*;
import cc.arduino.*;

//libraries needed for osc
import oscP5.*;
import netP5.*;

//variables needed for arduino communication
Arduino arduino;

//variables needed for osc
OscP5 oscP5;
NetAddress myRemoteLocation;

//set/change port numbers here
int incomingPort = 12000;
int outgoingPort = 12001;

//set/change the IP address that the OSC data is being sent to
//127.0.0.1 is the local address (for sending osc to an application on the same computer)
String ipAddress = "127.0.0.1";





//---------------setup code goes in the following function---------------------
void setup() 
{
  size(400,400);
  frameRate(25);
  
  /* start oscP5, listening for incoming messages at port ##### */
  //for INCOMING osc messages (e.g. from Max/MSP)
  oscP5 = new OscP5(this,incomingPort); //port number set above
  
  /* myRemoteLocation is a NetAddress. a NetAddress takes 2 parameters,
   * an ip address and a port number. myRemoteLocation is used as parameter in
   * oscP5.send() when sending osc packets to another computer, device, 
   * application. usage see below. 
   */
  //for OUTGOING osc messages (to another device/application)
  myRemoteLocation = new NetAddress(ipAddress, outgoingPort); //ip address set above
 
  
  //----for Arduino communication----
  arduino = new Arduino(this, Arduino.list()[0], 57600); //creates an Arduino object
  
  //set digital pins on arduino to input mode or output mode
   arduino.pinMode(2, Arduino.INPUT);
   arduino.pinMode(4, Arduino.INPUT);
   arduino.pinMode(7, Arduino.INPUT);
   //digital pins are set to output by default, so only the rest of the pins don't need to be manually set to OUTPUT
}





//----------the following function runs continuously as the app is open------------
//In here you should enter the code that reads any arduino pin data, and sends the data out as OSC
void draw() 
{
  int i;

  //read data from all the analog pins and send them out as osc data
  for (i = 0; i <= 5; i++)
  {
    int analogInputData = arduino.analogRead(i); //analog pin i is read and put into the analogInputData variable
    OscMessage analogInputMessage = new OscMessage("/analog/"+i); //an OSC message in created in the form 'analog/i'
    analogInputMessage.add(analogInputData); //the analog data from pin i is added to the osc message
    oscP5.send(analogInputMessage, myRemoteLocation); //the OSC message is sent to the set outgoing port and IP address
  }
  
  //read data from the digitalinput pins (pins 2, 4 and 7 in this example) and send them out as osc data
  for (i = 2; i <= 7; i++)
  {
    if(i == 2 || i == 4 || i == 7)
   { 
      int digitalInputData = arduino.digitalRead(i); //digital pin i is read and put into the digitalInputData variable
      OscMessage digitalInputMessage = new OscMessage("/digital/"+i); //an OSC message in created in the form 'digital/i'
      digitalInputMessage.add(digitalInputData); //the digital data from pin i is added to the osc message
      oscP5.send(digitalInputMessage, myRemoteLocation); //the OSC message is sent to the set outgoing port and IP address
   }


  background(0);
  
  } 
}




//--------incoming osc message are forwarded to the following oscEvent method. Write to the arduino pins here--------
//----------------------------------This method is called for each OSC message recieved------------------------------
void oscEvent(OscMessage theOscMessage) 
{
  /* print the address pattern and the typetag of the received OscMessage */
  print("### received an osc message.");
  print(" addrpattern: "+theOscMessage.addrPattern());
  print(" typetag: "+theOscMessage.typetag());
  print(" value: "+theOscMessage.get(0).intValue() +"\n");
  //-----------------------------------------------------------------------
  
  int i;
  int oscValue = theOscMessage.get(0).intValue(); //sets the incoming value of the OSC message to the oscValue variable
  
  
  
  
  //write data to the selected digital output pins (pins 8-13)
  for(i = 8; i <= 13; i++)
  {
    if(theOscMessage.addrPattern().equals("/digital/"+i) == true) //if the osc message = /digital/i/ (i represents the pin number)
    {
      if(oscValue == 0)
      {
      arduino.digitalWrite(i, Arduino.LOW); //turn pin OFF
      print("pin turned off\n");
      }
      else
      {
        arduino.digitalWrite(i, Arduino.HIGH); //turn pin ON
        print("pin turned on\n");
      }
    }
  }
  
  
  
  
  //write data to the selected PWN output pins (digital pins 3, 5 and 6 in this example)
  for(i = 3; i <= 6; i++)
  {
    if (i == 3 || i == 5 || i == 6)
    {
      if(theOscMessage.addrPattern().equals("/pwm/"+i) == true) //if the osc message = /pwm/i/ (i represents the pin number)
      {
        arduino.analogWrite(i, oscValue); //sets the pin to the incoming osc data
      } 
    }
  }
}
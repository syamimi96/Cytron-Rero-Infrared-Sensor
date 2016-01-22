#include "reroSensor_IR.h"                                        //Libary Of Infrared Sensor
#include <SoftwareSerial.h>
reroSensor_IR IR(2, 3, 8);                                        //define class of reroSensor_IR=IR (rxpin,txpin,ctrlpin)                                    


void setup() {
  Serial.begin(9600);               
  IR.begin(19200);                                                //Standard baudrate 19200.
  pinMode(8, OUTPUT);                                             //Set Pin Mode
  delay(1000);
}


void loop() {

  byte ledRead=IR.readLED(1);                                   //define ledRead as a function to get the LED mode
  Serial.print("Check Infrared Read LED Error:");
  Serial.println(IR.errStatus);                                  //the standart of the value is 0, if got error the value will be 255.
  
  if( IR.errStatus>0){
    Serial.println("Read LED ERROR!");
  }
  else
  {
    Serial.print("LED Status:");  
    Serial.println(ledRead);                                    //0=led off, 1=led on ,2=led trigger
  }
  delay(1000);
}

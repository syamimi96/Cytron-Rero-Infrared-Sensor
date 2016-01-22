#include "reroSensor_IR.h"                                        //Libary Of Infrared Sensor
#include <SoftwareSerial.h>
reroSensor_IR IR(2, 3, 8);                                        //define class of reroSensor_IR=IR (rxpin,txpin,ctrlpin)
char type[3] = {0, 0, 0};                                         //String terminal


void setup() {
  Serial.begin(9600);               
  IR.begin(19200);                                                //Standard baudrate 19200.
  pinMode(8, OUTPUT);                                             //Set Pin Mode
  delay(1000);
}


void loop() {
  
  byte ledWrite=IR.writeLED(1,2);                               //define ledWrite as a function to control the LED mode.(0=off,1=on,2=trigger)   
  Serial.print("Check LED Error:");
  Serial.println(IR.errStatus);                                   //the standart of the value is 0, if got error the value will be 255.
  
  if(IR.errStatus>0){
    Serial.println("Write LED ERROR!");
  }
  else
  {
    Serial.println("Write LED PASS!");
  }


  delay(1000);
 
}

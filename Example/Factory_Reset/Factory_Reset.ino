#include "reroSensor_IR.h"                                        //Library Of Infrared Sensor
#include <SoftwareSerial.h>
reroSensor_IR IR(2, 3, 8);                                        //define class of reroSensor_IR=IR (rxpin,txpin,ctrlpin)


void setup() {
  Serial.begin(9600);               
  IR.begin(19200);                                                //Standard baudrate 19200.
  pinMode(8, OUTPUT);                                             //Set Pin Mode
  delay(1000);
}


void loop() {
  
  byte reset=IR.factoryReset(1);                                  //define "reset" as a function for reset the memory of the sensor by using factory reset
  Serial.print("Check Infrared Factory Reset Error:");                           
  Serial.println(IR.errStatus);                                   //the standart of the value is 0, if got error the value will be 255.
  
  if(IR.errStatus>0){
    Serial.println("Factory Reset ERROR");
  }
  else
  {
    Serial.println("Factory Reset PASS!");
  }
  delay(1000);
}

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
 byte IdWrite=IR.writeID(1,2);                                //define IdWrite as a function to write the new id to the sensor.
 Serial.print("Check Infrared Write ID Error :");
 Serial.println(IR.errStatus);                                    //the standart of the value is 0, if got error the value will be 255.
 
 if(IR.errStatus>0){
  Serial.println("Write ID ERROR!");
 }
 else
 {
  Serial.println("Write ID PASS!");
 }
  delay(1000);
}

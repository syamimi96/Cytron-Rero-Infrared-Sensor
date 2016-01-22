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
 word baudrateWrite=IR.writeBaudrate(1,103);
 Serial.print("Check Infrared Write Baudrate:");
 Serial.println(IR.errStatus);                                    //the standart of the value is 0, if got error the value will be 255.
 
 if(IR.errStatus>0){
  Serial.println("Write Baudrate ERROR");
 }
 else
 {
  Serial.println("Write Baudrate PASS!");
 }
 delay(1000);
}

#include "reroSensor_IR.h"
#include <SoftwareSerial.h>
reroSensor_IR IR(2, 3, 8);


void setup() {
Serial.begin(9600);
IR.begin(19200);  
pinMode(8, OUTPUT);
delay(1000);
}
void loop() {

 IR.writeIrThreshold(1,126);
 Serial.print("Check Infrared Write IrThreshold:");
 Serial.println(IR.errStatus);                                    //the standart of the value is 0, if got error the value will be 255.
 
 if(IR.errStatus>0){
  Serial.println("Write IrThreshold ERROR");
 }
 else
 {
  Serial.println("Write IrThreshold PASS!");
 }
 delay(1000);
}

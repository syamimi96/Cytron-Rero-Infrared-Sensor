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
  byte Val=IR.readIrThreshold(1);
  Serial.print ("Check Infrared Read Threshold:");
  Serial.println (IR.errStatus);
  
   if (IR.errStatus>0) { 
    Serial.println("IR Reading Error!");
  }
  else
  {
    Serial.print(" Threshold VALUE:");
    Serial.println(Val);
  }
  delay(1000);
  
}

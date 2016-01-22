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
  word model = IR.readModel(1);                                //define model as a function to get the model of the sensor,because the model is 16 bit so need to use word
  type[0] = (char)model & 0x00FF;                                //}combination of lower bit n upper bit
  type[1] = (char)(model >> 8);                                  //}
  Serial.print("Check Infrared Read Model Error:");
  Serial.println(IR.errStatus);                                  //the standart of the value is 0, if got error the value will be 255.
  
  if(IR.errStatus>0){
    Serial.println("Read Model Error!!!");
  }
  else
  {
    Serial.print("Sensor Model:");
    Serial.println(type);
  }

  delay(1000);
}

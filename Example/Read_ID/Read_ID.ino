#include "reroSensor_IR.h"                                        //Libary Of Infrared Sensor
#include <SoftwareSerial.h>
reroSensor_IR IR(2, 3, 8);                                        //define class of reroSensor_IR=IR (rxpin,txpin,ctrlpin)


void setup() {
  Serial.begin(9600);               
  IR.begin(19200);                                                //Standard baudrate 19200.
  pinMode(8, OUTPUT);                                             //Set Output Pin Mode
  delay(1000);
}


void loop() {
  byte id=IR.ping();                                              //define id as the function to read the id of the sensor.
  Serial.print("Ping Sensor Status:");
  Serial.println(IR.errStatus);                                   //the standart of the value is 0, if got error the value will be 255.

  if(IR.errStatus>0){
    Serial.println("Infrared Sensor Not Detected!");
  }
  else
  {
    Serial.println("Infrared Sensor Detected!");
    Serial.print("Infrared ID:");
    Serial.println(id);
  }
  
  delay(1000);
}

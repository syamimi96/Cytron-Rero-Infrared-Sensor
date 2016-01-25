# WriteLED() #

## Description ##
This function will read the identity of the Infrared Sensor. 

## Include ##
reroSensor_IR.h

## Prototype ##
byte ping(byte ID);

## Parameters ##
byte ID; //byte ID is INFRARED SENSOR unique ID

## Returns ##
 return packet from sensor
 
if errStatus=255 ,serial monitor print out "Read ID ERROR!".

if errStatus=0,serial monitor print out identity of sensor.

## Example ##
reroSensor_IR IR(2,3,8);

byte ledWrite;

ledWrite= IR.writeLED(1,2); // read ID 1 control register LED.

## See Also ##

[errStatus](https://github.com/syamimi96/Library-for-Rero-infrared-sensor-/blob/wiki/Example/errStatus.md)


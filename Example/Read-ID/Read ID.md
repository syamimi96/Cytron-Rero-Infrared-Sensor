# ReadID() #

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
 
if errStatus more than 0 , ping fail.

if errStatus=0,ping success.

## Example ##
reroSensor_IR IR(2,3,8);

byte id;

id= IR.ping(); //call out the function of ping.

## See Also ##

[errStatus](https://github.com/syamimi96/Cytron-Rero-Infrared-Sensor/blob/wiki/Example/errorStatus.md)


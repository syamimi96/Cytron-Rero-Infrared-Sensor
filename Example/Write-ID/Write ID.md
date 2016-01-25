# WriteID() #

## Description ##
This function call out the ID of rero Infrared Sensor. 

## Include ##
reroSensor_IR.h

## Prototype ##
byte writeID(byte ID,byte newID);

## Parameters ##
byte ID; //byte ID is INFRARED SENSOR unique ID

byte newID;//rero Infrared Sensor new ID
## Returns ##
 return packet from sensor
 
if errStatus more than 0,read write ID fail.

if errStatus=0,read write ID success.

## Example ##
reroSensor_IR IR(2,3,8);

byte idWrite;

idWrite= IR.writeID(1,2);// call out the function of write ID with ID = 1(rero Infrared Sensor default ID),2=rero Infrared sensor new ID.

## See Also ##

[errStatus](https://github.com/syamimi96/Cytron-Rero-Infrared-Sensor/blob/wiki/Example/errorStatus.md)


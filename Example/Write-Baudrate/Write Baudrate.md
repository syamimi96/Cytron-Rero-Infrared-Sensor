# WriteBaudrate() #

## Description ##
This function will read the identity of the Infrared Sensor. 

## Include ##
reroSensor_IR.h

## Prototype ##
byte writeBaudrate(byte ID,byte newBaudrate);

## Parameters ##
byte ID; //byte ID is INFRARED SENSOR unique ID.

byte newBaudrate;//rero Infrared Sensor new baudrate.

## Returns ##
 Return packet of baudrate register:
 
if errStatus more than 0,write baudrate fail.

if errStatus=0,write baudrate success.

## Example ##
reroSensor_IR IR(2,3,8);

byte baudrateWrite;

baudrateWrite= IR.ping(1,103);// call out the function of write baudrate with ID = 1(rero Infrared Sensor default ID), Standard value of baudrate =103(19200).

## See Also ##

[errStatus](https://github.com/syamimi96/Cytron-Rero-Infrared-Sensor/blob/wiki/Example/errorStatus)

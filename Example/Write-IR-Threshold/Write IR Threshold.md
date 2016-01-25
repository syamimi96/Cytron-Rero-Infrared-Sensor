# WRITE IR THRESHOLD SENSOR() #

## Description ##
This function sets infrared control registers IR threshold value . 

## Include ##
reroSensor_IR.h

## Prototype ##
byte writeIrThreshold(byte ID,byte Ir);

## Parameters ##
byte ID; //byte ID is INFRARED SENSOR unique ID

byte Ir; //byte Ir is INFRARED SENSOR NEW Ir Threshold value

## Returns ##
Frist time Return Ramdom Value

Then Return IR Sensor Reading Error

## Example ##
reroSensor_IR IR(2,3,8);

byte Ir

IR.writeIrThreshold(1,126); // set ID 1 Infrared Senor to 126 New Ir Threshold value

## See Also ##

[errStatus](https://github.com/syamimi96/Library-for-Rero-infrared-sensor-/blob/wiki/Example/errStatus.md)

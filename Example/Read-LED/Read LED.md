# ReadLED() #

## Description ##
This function call out mode of the Infrared Sensor LED. 

## Include ##
reroSensor_IR.h

## Prototype ##
byte readLED(byte ID);

## Parameters ##
byte ID; //byte ID is INFRARED SENSOR unique ID

## Returns ##
 Return packet from LED register:
 
if errStatus more than 0 ,read ID fail.

if errStatus=0,LED register will return the mode of sensor LED.

## Example ##
reroSensor_IR IR(2,3,8);

byte LED;

LED= IR.readLED(1); // call out the function of readLED with ID = 1(rero Infrared Sensor default ID).

## See Also ##

[errStatus](https://github.com/syamimi96/Library-for-Rero-infrared-sensor-/blob/wiki/Example/errStatus.md)


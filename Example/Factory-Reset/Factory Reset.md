#FactoryReset() #

## Description ##
This function will reset all the control registers's Infrared Sensor values to default value.

## Include ##
reroSensor_IR.h

## Prototype ##
byte factoryReset(byte ID);

## Parameters ##
byte ID; //byte ID is INFRARED SENSOR unique ID

## Returns ##
 return packet from Infrared Sensor factory reset register.
 
if return 0 ,Factory Reset Fail.

if return 1, Factory Reset Success.

## Example ##
reroSensor_IR IR(2,3,8);

byte reset;

reset= IR.factoryReset(1); // call out the function of factory reset with ID = 1(rero Infrared Sensor default ID).

## Find Out ##

[errStatus](https://github.com/syamimi96/Cytron-Rero-Infrared-Sensor/blob/wiki/Example/errorStatus)


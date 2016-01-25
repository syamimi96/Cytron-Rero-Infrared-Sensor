# READ IR TRG SENSOR() #

## Description ##
This register is set to 1 when the IR VAL is greater than the IR Threshold else it is 0. 

## Include ##
reroSensor_IR.h

## Prototype ##
byte readIrTRG(byte ID);

## Parameters ##
byte ID; //byte ID is INFRARED SENSOR unique ID

## Returns ##
return Ir TRG defualt value 

## Example ##
reroSensor_IR IR(2,3,8);

byte IrTRG

TRG=IR.readIRTRG(1); //reading Ir TRG value form ID 1 Infrared Sensor

## See Also ##

[errStatus](https://github.com/syamimi96/Cytron-Rero-Infrared-Sensor/blob/wiki/Example/errorStatus)

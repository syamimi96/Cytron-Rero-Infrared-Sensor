# READ IR THRESHOLD SENSOR() #

## Description ##
IR threshold determines the threshold value of head IR sensor to trigger.

## Include ##
reroSensor_IR.h

## Prototype ##
byte readIrThreshold(byte ID);

## Parameters ##
byte ID; //byte ID is INFRARED SENSOR unique ID

## Returns ##
return IR Threshold Value

## Example ##
byte Ir
Ir=readIrThreshold (1); //reading ID 1 Infrared Sensor Ir Threshold Value

## See Also ##

[errStatus](https://github.com/syamimi96/Library-for-Rero-infrared-sensor-/blob/wiki/Example/errStatus.md
)

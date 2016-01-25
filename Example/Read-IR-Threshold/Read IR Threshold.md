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
Val=IR.readIrThreshold (1); //reading ID 1 Infrared Sensor Ir Threshold Value

## See Also ##

[errStatus](https://github.com/syamimi96/Cytron-Rero-Infrared-Sensor/blob/wiki/Example/errorStatus
)

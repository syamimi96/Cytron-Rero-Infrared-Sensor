#ReadBaudrate() #

## Description ##
This function rero Infrared Sensor's read baudrate.

## Include ##
reroSensor_IR.h

## Prototype ##
byte readBaudrate(byte ID);

## Parameters ##

byte ID;            //byte ID is INFRARED SENSOR unique ID

## Returns ##
Return Baudrate Buffer Data:

|RegisterValue(Hex)|BaudRate(bps)|
|:-----------------|:------------|
|3   (0x03)|500,000       |
|4   (0x04)|400,000       |
|7   (0x07)|250,000       |
|9   (0x09)|200,000       |
|16  (0x10)|115,200       |
|34  (0x22)|57,600        |
|103 (0x67)|19,200        |
|207 (0xCF)|9600          |


## Example ##
reroSensor_IR IR(2,3,8);

byte baud;

baud = IR.readBaudrate(1);  // call out the function of Read Baudrate with ID = 1(rero Infrared Sensor default ID).

## See Also ##

[errStatus](https://github.com/syamimi96/Library-for-Rero-infrared-sensor-/blob/wiki/Example/errStatus.md)




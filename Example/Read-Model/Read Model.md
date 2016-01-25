# ReadModel() #

## Description ##
The two byte register contains ASCII character to recognize the sensor type. ‘I’,’R’ in this case denotes the INFRARED SENSOR.

## Include ##
reroSensor_IR.h

## Prototype ##
word readModel(ID);
  
## Parameters ##
word ID; //byte ID is INFRARED SENSOR unique ID

## Returns ##
return model L and model H default value in 16bit.

model L return R

model H return I

## Example ##
reroSensor_IR IR(2,3,8);

char modelHM[3]={0,0,0}; //null terminated string 

word model

model=IR.readModel(1);// call out the function of read model with ID = 1(rero Infrared Sensor default ID).

type[1]=(char)model&0x00FF;
  
type[0]=(char)(model>>8);

Serial.println(type);
  
## See Also ##
[errStatus](https://github.com/syamimi96/Library-for-Rero-infrared-sensor-/blob/wiki/Example/errStatus.md)


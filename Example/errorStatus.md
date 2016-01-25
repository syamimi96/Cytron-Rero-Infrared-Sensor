# Error Status Table #

## Description ##
|bit 7|bit 6|bit 5|bit 4|bit 3|bit 2|bit 1|bit 0|
|:----|:----|:----|:----|:----|:----|:----|:----|
|     |     |     |     |     |Instruction     |Checksum     |Range  |


If IR.errStatus more than 0,error buff will state error.

If IR.errStatus = 0,error buff will state success.

|Value| Error Status|
|:----|:------------|
|0    |No Error|
|1    |Range Error|
|2    |Checksum Error|
|3    |Range and Checksum Error|
|4    |Instruction Error|
|5    |Instruction and Range Error|
|6    |Instruction and Checksum Error|
|7    |Instruction,Checksum,Range Error|

##Example##
if(IR.errStatus>0)<br/>
{<br/>
Serial.print("Status Fail:");<br/>
Serial.println(IR.errStatus);        //print out the value of error buff of return packet<br/>
}<br/>
else<br/>
{<br/>
Serial.print("Status Success:");<br/>
Serial.print(IR.errStatus);         //print out the value of error buff of return packet<br/>
}<br/>

#include"Arduino.h"
#include <SoftwareSerial.h>
#ifndef reroSensor_IR_h
#define reroSensor_IR_h


//***********************************************
//*Instuction
//***********************************************
#define pingInst 0x01 //Ping Instruction
#define readInst 0x02 //Read Instruction
#define writeInst 0x03 //Write Instruction
#define factoryResetInst 0x06//Factory Reset Instruction
#define pingIRInst  0x07//Ping Infrared Sensor Instruction
#define LEDAddress  0x09//LED Instruction
#define IRInst 0x0A//IR instruction
#define modelInst (byte)0x00//Sensor Model Instruction
#define IDAddress  0x03//ID Address
#define IRTRG 0x0B //IR TRG Instruction
#define IrThreshold 0x07 // IR Thres Instruction

#define TxMode LOW
#define RxMode HIGH

class reroSensor_IR
{
  public:
    byte errStatus;
    byte _rxpin;
    byte _txpin;
    byte _ctrlpin;

    reroSensor_IR (byte rxpin, byte txpin, byte ctrlpin);
    void begin(long baudrate);
    
    //*****************************
    //*===========Ping==============
    //******************************
    byte ping(void);


    //******************************
    //*========Factory Reset========
    //******************************
    byte factoryReset(byte ID);


    //*****************************
    //*=======Read Baudrate=======
    //*****************************
    byte readBaudrate(byte ID);


    //*****************************
    //*=======Write Baudrate=======
    //*****************************
    byte writeBaudrate(byte ID, byte Baudrate);

    
    //*****************************
    //*******Read LED**************
    //*****************************
    byte readLED (byte ID);

    
    //*****************************
    //*******Write LED**************
    //*****************************
    byte writeLED(byte ID, byte LED);


    //********************************
    //*******Read Model**************
    //********************************
    word readModel(byte ID);

 
    //********************************
    //*******Read ID**************
    //********************************
    byte readIR(byte ID);


    //********************************
    //*******Write ID**************
    //********************************
    byte writeID(byte ID,byte newID);


    //********************************
    //*******Read TRG**************
    //********************************
    byte readIRTRG(byte ID);



    //********************************
    //*******Read Threshold**************
    //********************************
    byte readIrThreshold(byte ID);



   //********************************
    //*******Write Threshold**************
    //********************************
    byte writeIrThreshold(byte ID,byte IR);

};
#endif




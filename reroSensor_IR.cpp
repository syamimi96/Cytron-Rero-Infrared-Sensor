#include "reroSensor_IR.h"
SoftwareSerial* reroIRSerial;

reroSensor_IR::reroSensor_IR(byte rxpin, byte txpin, byte ctrlpin)
{
  _rxpin = rxpin;
  _txpin = txpin;
  _ctrlpin = ctrlpin;
}


void reroSensor_IR::begin(long baudrate)
{
  byte hardwareSerial;
  if (_rxpin == 0 && _txpin == 1)
  {
    hardwareSerial = true;
    Serial.begin(baudrate);
    while (!Serial);
    Serial.setTimeout(1000);
  }
  else
  {
    hardwareSerial = false;
    pinMode(_rxpin, INPUT);
    pinMode(_txpin, OUTPUT);
    reroIRSerial = new SoftwareSerial(_rxpin, _txpin);
    reroIRSerial->begin(baudrate);
    reroIRSerial->setTimeout(1000);
  }
  pinMode(_ctrlpin, OUTPUT);
  digitalWrite(_ctrlpin, TxMode);
}

byte reroSensor_IR::ping(void) {
  byte buff[6];
  while (reroIRSerial->available()) {
    reroIRSerial->read();
  }

  digitalWrite(_ctrlpin, TxMode);

  reroIRSerial->write(0xFF);
  reroIRSerial->write(0xFF);
  reroIRSerial->write(0xFE);
  reroIRSerial->write(0x02);
  reroIRSerial->write(pingInst);//ping instruction
  byte checksum = (0xFF - 0xFE - 0x02 - pingInst);
  reroIRSerial->write(checksum);

  digitalWrite(_ctrlpin, RxMode);

  int nbyte = reroIRSerial->readBytes(buff, 6);

  if (nbyte < 6) {
    errStatus = 0xFF;
    return (0);
  }
  else
  {
    errStatus = buff[4];
    return (buff[2]);
  }
}



byte reroSensor_IR::factoryReset(byte ID) {
  byte buff[6];
  while (reroIRSerial->available()) {
    reroIRSerial->read();
  }
  //send intruction
  digitalWrite(_ctrlpin, TxMode);
  reroIRSerial->write(0xFF);
  reroIRSerial->write(0xFF);
  reroIRSerial->write(ID);
  reroIRSerial->write(0x02);
  reroIRSerial->write(factoryResetInst);//factory reset instruction
  byte checksum = (0xFF - ID - 0x02 - factoryResetInst);
  reroIRSerial->write(checksum);
  //receive return statIR
  digitalWrite(_ctrlpin, RxMode);

  int nbyte = reroIRSerial->readBytes(buff, 6);

  if (nbyte < 6) {
    errStatus = (0xFF);
    return (0);
  }
  else
  {
    errStatus = buff[4];
    return (1);
  }
}



byte reroSensor_IR::readLED(byte ID) {
  byte buff[7];
  while (reroIRSerial->available()) {
    reroIRSerial->read();
  }

  digitalWrite(_ctrlpin, TxMode);
  reroIRSerial->write(0xFF);
  reroIRSerial->write(0xFF);
  reroIRSerial->write(ID);
  reroIRSerial->write(0x04);
  reroIRSerial->write(readInst);
  reroIRSerial->write(LEDAddress);
  reroIRSerial->write(0x01);
  byte checksum = (0xFF - ID - 0x04 - readInst - LEDAddress - 0x01);
  reroIRSerial->write(checksum);

  digitalWrite(_ctrlpin, RxMode);
  byte nbyte = reroIRSerial->readBytes(buff, 6);

  if (nbyte < 6) {
    errStatus = 0xFF;
    return (0xFF);
  }
  else {
    errStatus = buff[4];
    return buff[5];
  }
}



byte reroSensor_IR::writeLED(byte ID, byte LED) {
  byte buff[7];
  while (reroIRSerial->available()) {
    reroIRSerial->read();
  }

  digitalWrite(_ctrlpin, TxMode);
  reroIRSerial->write(0xFF);
  reroIRSerial->write(0xFF);
  reroIRSerial->write(ID);
  reroIRSerial->write(0x04);
  reroIRSerial->write(writeInst);
  reroIRSerial->write(LEDAddress);
  reroIRSerial->write(LED);
  byte checksum = (0xFF - ID - 0x04 - writeInst - LEDAddress - LED);
  reroIRSerial->write(checksum);

  digitalWrite(_ctrlpin, RxMode);
  byte nbyte = reroIRSerial->readBytes(buff, 6);

  if (nbyte < 6) {
    errStatus = (0xFF);
    return (0);
  }
  else {
    errStatus = buff [4];
    return buff[4];
  }
}



byte reroSensor_IR::readIR(byte ID){
    byte buff[7];
    
    
    while(reroIRSerial->available()){
     reroIRSerial->read();
    }
    
    digitalWrite(_ctrlpin,TxMode);
    reroIRSerial->write(0xFF);
    reroIRSerial->write(0xFF);
   reroIRSerial->write(ID);
    reroIRSerial->write(0x04);
    reroIRSerial->write(readInst);
   reroIRSerial->write(IRInst);
    reroIRSerial->write(0x01);
   byte checksum=(0xFF-ID-0x04-readInst-IRInst-0x01);
   reroIRSerial->write(checksum);

    
   digitalWrite(_ctrlpin,RxMode);
   byte nbyte=reroIRSerial->readBytes(buff,7);
   
   if(nbyte<7){
    return (0xFF);
   }
   else{
   errStatus=buff[4];
   return buff[5]; 
  }
}



byte reroSensor_IR::writeID(byte ID, byte newID) {
  byte buff[7];
  while (reroIRSerial->available()) {
    reroIRSerial->read();
  }

  digitalWrite(_ctrlpin, TxMode);
  reroIRSerial->write(0xFF);
  reroIRSerial->write(0xFF);
  reroIRSerial->write(ID);
  reroIRSerial->write(0x04);
  reroIRSerial->write(writeInst);
  reroIRSerial->write(0x03);
  reroIRSerial->write(newID);
  byte checksum = (0xFF - ID - 0x04 - writeInst - 0x03 - newID);
  reroIRSerial->write(checksum);

  digitalWrite(_ctrlpin, RxMode);
  byte nbyte = reroIRSerial->readBytes(buff, 6);

  if (nbyte < 6) {
    errStatus = (0xFF);
    return (0);
  }
  else {
    errStatus = buff [4];
    return buff[4];
  }
}



byte reroSensor_IR::readBaudrate(byte ID) {
  byte buff[7];
  while (reroIRSerial->available()) {
    reroIRSerial->read();
  }

  digitalWrite(_ctrlpin, TxMode);
  reroIRSerial->write(0xFF);
  reroIRSerial->write(0xFF);
  reroIRSerial->write(ID);
  reroIRSerial->write(0x04);
  reroIRSerial->write(readInst);
  reroIRSerial->write(0x04);
  reroIRSerial->write(0x01);
  byte checksum = (0xFF - ID - 0x04 - readInst - 0x04 - 0x01);
  reroIRSerial->write(checksum);

  digitalWrite(_ctrlpin, RxMode);
  byte nbyte = reroIRSerial->readBytes(buff, 6);

  if (nbyte < 6) {
    errStatus = 0xFF;
    return (0xFF);
  }
  else {
    errStatus = buff[4];
    return buff[5];
  }
}




byte reroSensor_IR::writeBaudrate(byte ID, byte Baudrate) {
  byte buff[7];
  while (reroIRSerial->available()) {
    reroIRSerial->read();
  }

  digitalWrite(_ctrlpin, TxMode);
  reroIRSerial->write(0xFF);
  reroIRSerial->write(0xFF);
  reroIRSerial->write(ID);
  reroIRSerial->write(0x04);
  reroIRSerial->write(writeInst);
  reroIRSerial->write(0x04);
  reroIRSerial->write(Baudrate);
  byte checksum = (0xFF - ID - 0x04 - writeInst - 0x04 - Baudrate);
  reroIRSerial->write(checksum);

  digitalWrite(_ctrlpin, RxMode);
  byte nbyte = reroIRSerial->readBytes(buff, 6);

  if (nbyte < 6) {
    errStatus = (0xFF);
    return (0);
  }
  else {
    errStatus = buff [4];
    return buff[4];
  }
}



word reroSensor_IR::readModel(byte ID) {
  byte buff[7];
  word mode;
  while (reroIRSerial->available()) {
    reroIRSerial->read();
  }

  digitalWrite(_ctrlpin, TxMode);
  reroIRSerial->write(0xFF);
  reroIRSerial->write(0xFF);
  reroIRSerial->write(ID);
  reroIRSerial->write(0x04);
  reroIRSerial->write(readInst);
  reroIRSerial->write(modelInst);
  reroIRSerial->write(0x02);
  byte checksum = (0xFF - ID - 0x04 - readInst - modelInst - 0x02);
  reroIRSerial->write(checksum);

  digitalWrite(_ctrlpin, RxMode);
  byte nbyte = reroIRSerial->readBytes(buff, 7);

  if (nbyte < 7) {
    errStatus = 0xFF;
    return (0xFF);
  }
  else {
    mode = buff[5];
    mode <<= 8;
    mode |= buff[6];
    return (mode);
    errStatus = buff[4];
  }
}



byte reroSensor_IR::readIRTRG(byte ID) {
  byte buff[7];
  while (reroIRSerial->available()) {
    reroIRSerial->read();
  }

  digitalWrite(_ctrlpin, TxMode);
  reroIRSerial->write(0xFF);
  reroIRSerial->write(0xFF);
  reroIRSerial->write(ID);
  reroIRSerial->write(0x04);
  reroIRSerial->write(readInst);
  reroIRSerial->write(0x0B);
  reroIRSerial->write(0x01);
  byte checksum = (0xFF - ID - 0x04 - readInst - 0x0B - 0x01);
  reroIRSerial->write(checksum);

  digitalWrite(_ctrlpin, RxMode);
  byte nbyte = reroIRSerial->readBytes(buff, 6);

  if (nbyte < 6) {
    errStatus = 0xFF;
    return (0xFF);
  }
  else {
    errStatus = buff[4];
    return buff[5];

  }
}



byte reroSensor_IR::readIrThreshold(byte ID) {
  byte buff[7];
  while (reroIRSerial->available()) {
    reroIRSerial->read();
  }

  digitalWrite(_ctrlpin, TxMode);
  reroIRSerial->write(0xFF);
  reroIRSerial->write(0xFF);
  reroIRSerial->write(ID);
  reroIRSerial->write(0x04);
  reroIRSerial->write(readInst);
  reroIRSerial->write(IrThreshold);
  reroIRSerial->write(0x01);
  byte checksum = (0xFF - ID - 0x04 - readInst - IrThreshold - 0x01);
  reroIRSerial->write(checksum);

  digitalWrite(_ctrlpin, RxMode);
  byte nbyte = reroIRSerial->readBytes(buff, 6);

  if (nbyte < 6) {
    errStatus = 0xFF;
    return (0);
  }
  else {
    errStatus = buff[4];
    return buff[5];
  }
}


byte reroSensor_IR::writeIrThreshold(byte ID,byte IR) {
  byte buff[7];
  while (reroIRSerial->available()) {
    reroIRSerial->read();
  }

  digitalWrite(_ctrlpin, TxMode);
  reroIRSerial->write(0xFF);
  reroIRSerial->write(0xFF);
  reroIRSerial->write(ID);
  reroIRSerial->write(0x04);
  reroIRSerial->write(writeInst);
  reroIRSerial->write(IrThreshold);
  reroIRSerial->write(IR);
  byte checksum = (0xFF - ID - 0x04 - writeInst - IrThreshold - IR);
  reroIRSerial->write(checksum);

  digitalWrite(_ctrlpin, RxMode);
  byte nbyte = reroIRSerial->readBytes(buff, 6);

  if (nbyte < 6) {
    errStatus = 0xFF;
    return (0xFF);
  }
  else {
    errStatus = buff[4];
    return buff[5];
  }
}

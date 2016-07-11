#include <Wire.h>
#include "RTClib.h"
#include <Ethernet.h>
#include <OneWire.h>
#include <EEPROM.h>
#include <SPI.h>
RTC_DS1307  _RTC1;
DateTime  _tRTC1;

byte _d18x2x2Addr[8]={0x28, 0xFF, 0x83, 0x1D, 0x61, 0x15, 0x3, 0x97};

byte _d18x2x1Addr[8]={0x28, 0xFF, 0x8B, 0x12, 0x2B, 0x4, 0x0, 0xA2};

struct UB_93993507
{
String ubo_98898145 = "";
String ubo_190631320 = "";
String ubo_242595348 = "";
String ubo_2845936 = "";
String ubo_221470420 = "";
int _gtv6 = 0;
int _gtv7 = 0;
int _gtv8 = 0;
int _gtv9 = 0;
int _gtv10 = 0;
String _gtv1 = "";
String _gtv2 = "";
String _gtv3 = "";
String _gtv4 = "";
String _gtv5 = "";
String _swi1 = "";
String _swi2 = "";
String _swi3 = "";
String _swi4 = "";
String _swi5 = "";
};
UB_93993507 UB_93993507_Instance1;
int UB_93993507_ubi_200586030 = 0;
int UB_93993507_ubi_679972 = 0;
int UB_93993507_ubi_251662263 = 0;
int UB_93993507_ubi_149551738 = 0;
int UB_93993507_ubi_235635076 = 0;
int _modbusSlaveDataTable_4[17];
int _modbusSlaveAddresTable_4[17] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16};
byte _modbusSlaveBufferSize = 0;
byte _modbusSlaveBuffer[64];
const unsigned char _modbusSlave_fctsupported[] = {3, 6, 16};
EthernetServer _modbusSlaveTCPServer(502);
EthernetClient _modbusSlaveTCPClient;
byte _modbusSlaveMBAPBuffer[6];
OneWire  _ow7(7);
byte ethernet_mac [] = {0x78, 0xAC, 0xC0, 0xE4, 0x18, 0x5B};
IPAddress ethernet_ip(192, 168, 0, 19);
byte ethernet_dns [] = {192, 168, 0, 1};
byte ethernet_gateway [] = {192, 168, 0, 1};
byte ethernet_subnet [] = {255, 255, 255, 0};
int _PWDC = 0;
int _gtv2 = 3;
int _gtv1 = 5;
int _gtv4 = 10;
String _gtv3;
bool _gtv6 = 0;
int _gtv5 = 12;
int _gtv7 = 11;
int _gtv9;
bool _gtv10 = 0;
bool _gtv11 = 0;
bool _gtv12 = 0;
bool _gtv13 = 0;
int _gtv15 = 1;
int _gtv16 = 10;
int _gtv17;
int _gtv23;
int _gtv26;
int _gtv27 = 1;
bool _gtv28 = 0;
bool _gtv30 = 0;
bool _gtv31 = 0;
int _gtv32 = 5;
int _gtv18 = 10;
bool _gtv35 = 0;
bool _count3I = 0;
int _count3P = 0;
bool _SEEPR2OSN = 0;
bool _tim7I = 0;
bool _tim7O = 0;
unsigned long _tim7P = 0UL;
int _swi9;
bool _tim2I = 0;
bool _tim2O = 0;
unsigned long _tim2P = 0UL;
bool _tim9I = 0;
bool _tim9O = 0;
unsigned long _tim9P = 0UL;
bool _bounse2S = 0;
bool _bounse2O = 0;
unsigned long _bounse2P = 0UL;
bool _swi6;
unsigned long _d18x2x2Tti = 0UL;
float _d18x2x2O = 0.00;
bool _bounseInputD8S = 0;
bool _bounseInputD8O = 0;
unsigned long _bounseInputD8P = 0UL;
int _swi8;
int _swi2;
bool _tim10I = 0;
bool _tim10O = 0;
unsigned long _tim10P = 0UL;
bool _tim1I = 0;
bool _tim1O = 0;
unsigned long _tim1P = 0UL;
bool _count4I = 0;
int _count4P = 0;
byte _modbuseSetSlId2_SlId = 1;
bool _count5I = 0;
int _count5P = 0;
unsigned long _d18x2x1Tti = 0UL;
float _d18x2x1O = 0.00;
int _swi5;
bool _tim6I = 0;
bool _tim6O = 0;
unsigned long _tim6P = 0UL;
bool _tim5I = 0;
bool _tim5O = 0;
unsigned long _tim5P = 0UL;
bool _swi7;
bool _tim4I = 0;
bool _tim4O = 0;
unsigned long _tim4P = 0UL;
bool _gen1I = 0;
bool _gen1O = 0;
unsigned long _gen1P = 0UL;
bool _count1I = 0;
int _count1P = 0;
bool _gen2I = 0;
bool _gen2O = 0;
unsigned long _gen2P = 0UL;
bool _RTCAlO1 = 0;
bool _RTCAlO2 = 0;
bool _tim8I = 0;
bool _tim8O = 0;
unsigned long _tim8P = 0UL;
bool _tim3I = 0;
bool _tim3O = 0;
unsigned long _tim3P = 0UL;
bool _tim11I = 0;
bool _tim11O = 0;
unsigned long _tim11P = 0UL;
void setup()
{
  Ethernet.begin(ethernet_mac, ethernet_ip, ethernet_dns, ethernet_gateway, ethernet_subnet);
delay(1000);
_modbusSlaveTCPServer.begin();
TCCR2A = 0x00;
TCCR2B =  0x07;
TIMSK2=0x01;
TCNT2=100;
Wire.begin();
_RTC1.begin();
pinMode(8, INPUT);
pinMode(9, OUTPUT);
pinMode(6, OUTPUT);

_bounseInputD8O =  digitalRead(8);
}
void loop()
{_modbusSlavePoll();
_PWDC = 0;
_tRTC1 = _RTC1.now();

bool  _bounceInputTmpD8 =  (digitalRead (8));

if (_bounseInputD8S) 
    {
     if (millis() >= (_bounseInputD8P + 40)) 
         {_bounseInputD8O= _bounceInputTmpD8; _bounseInputD8S=0;}
     }
else
    {
     if (_bounceInputTmpD8 != _bounseInputD8O )
         {_bounseInputD8S=1; _bounseInputD8P = millis();} 
      } 



UB_93993507_ubi_200586030 = _gtv2;
UB_93993507_ubi_679972 = _gtv1;
UB_93993507_ubi_251662263 = _gtv4;
UB_93993507_ubi_149551738 = 0;
UB_93993507_ubi_235635076 = 0;
UB_93993507_Instance1 = _func_UB_93993507(UB_93993507_Instance1, UB_93993507_ubi_200586030, UB_93993507_ubi_679972, UB_93993507_ubi_251662263, UB_93993507_ubi_149551738, UB_93993507_ubi_235635076);
if(_gtv28){ if(!_SEEPR2OSN){ EEPROMWriteInt(0, _gtv23); _SEEPR2OSN=1;} }else{ if(_SEEPR2OSN){_SEEPR2OSN=0;}}
_gtv2 = (_tRTC1.hour());
_gtv1 = (_tRTC1.minute());
_gtv4 = (_tRTC1.second());
_gtv3 = ((UB_93993507_Instance1.ubo_98898145) + (String(":")) + (UB_93993507_Instance1.ubo_190631320) + (String(":")) + (UB_93993507_Instance1.ubo_242595348));
_gtv15 = _gtv27;
_gtv27 = (EEPROMReadInt(0));
bool   _bounceTmpD2 = _bounseInputD8O;

if (_bounse2S) 
    {
     if (millis() >= (_bounse2P + 40)) 
         {_bounse2O=  _bounceTmpD2; _bounse2S=0;}
     }
else
    {
     if ( _bounceTmpD2 != _bounse2O )
         {_bounse2S=1; _bounse2P = millis();} 
      } 
if(_isTimer(_d18x2x1Tti, 5000)) {
_d18x2x1Tti = millis(); 
_d18x2x1O=  _readDS18_ow7(_d18x2x1Addr, 0);}
if(_isTimer(_d18x2x2Tti, 6000)) {
_d18x2x2Tti = millis(); 
_d18x2x2O=  _readDS18_ow7(_d18x2x2Addr, 0);}
if (1) {
_gtv6 = _bounse2O;
}
if (((_d18x2x1O)) < (60.00)) {
_gtv7 = (_d18x2x1O);
}
if (((_d18x2x2O)) < (60.00)) {
_gtv5 = (_d18x2x2O);
}
if(_gtv35) {_tim9O = 1; _tim9I = 1;} else { if(_tim9I) {_tim9I = 0; _tim9P = millis();} else { if (_tim9O) {if ( _isTimer(_tim9P, 900000)) _tim9O = 0;}}}
if(_gtv6) {_tim10O = 1; _tim10I = 1;} else { if(_tim10I) {_tim10I = 0; _tim10P = millis();} else { if (_tim10O) {if ( _isTimer(_tim10P, 180000)) _tim10O = 0;}}}
if(( (_tim9O) || (( (( (( (((_tRTC1.hour())) >= (0)) && (((_tRTC1.hour())) <= (8)) )) || (_tim10O) )) || (_gen1O) )) ))
{_swi6=1;}
else
{_swi6=0;}
if (( (((_tRTC1.hour())) >= (9)) && (((_tRTC1.hour())) <= (23)) )) { if (! _gen1I) { _gen1I = 1; _gen1O = 1; _gen1P = millis(); } } else { _gen1I = 0 ; _gen1O= 0;}
 if (_gen1I) {  if ( _isTimer ( _gen1P , 1800000 )) { _gen1P = millis(); _gen1O = ! _gen1O;}}
digitalWrite(9, !(_swi6));
_gtv11 = _swi6;
if(_gtv13) {_tim4O = 1; _tim4I = 1;} else { if(_tim4I) {_tim4I = 0; _tim4P = millis();} else { if (_tim4O) {if ( _isTimer(_tim4P, 600000)) _tim4O = 0;}}}
if(( ((_gtv15) == (1)) && (_RTCAlO1) )) {_tim11O = 1; _tim11I = 1;} else { if(_tim11I) {_tim11I = 0; _tim11P = millis();} else { if (_tim11O) {if ( _isTimer(_tim11P, 25000)) _tim11O = 0;}}}
if(( ((_gtv15) == (2)) && (_RTCAlO1) )) {_tim1O = 1; _tim1I = 1;} else { if(_tim1I) {_tim1I = 0; _tim1P = millis();} else { if (_tim1O) {if ( _isTimer(_tim1P, 50000)) _tim1O = 0;}}}
if(( ((_gtv15) == (3)) && (_RTCAlO1) )) {_tim2O = 1; _tim2I = 1;} else { if(_tim2I) {_tim2I = 0; _tim2P = millis();} else { if (_tim2O) {if ( _isTimer(_tim2P, 75000)) _tim2O = 0;}}}
if(( (( (_tim4O) ^ (( (( (_tim11O) ^ (_tim1O) )) ^ (( (_tim2O) ^ (_tim3O) )) )) )) ^ (( (( (_tim5O) ^ (_tim7O) )) ^ (( (_tim8O) ^ (_tim6O) )) )) ))
{_swi7=1;}
else
{_swi7=0;}
if(( ((_gtv15) == (4)) && (_RTCAlO1) )) {_tim3O = 1; _tim3I = 1;} else { if(_tim3I) {_tim3I = 0; _tim3P = millis();} else { if (_tim3O) {if ( _isTimer(_tim3P, 100000)) _tim3O = 0;}}}
if(( ((_gtv15) == (5)) && (_RTCAlO1) )) {_tim5O = 1; _tim5I = 1;} else { if(_tim5I) {_tim5I = 0; _tim5P = millis();} else { if (_tim5O) {if ( _isTimer(_tim5P, 125000)) _tim5O = 0;}}}
if(( ((_gtv15) == (6)) && (_RTCAlO1) )) {_tim7O = 1; _tim7I = 1;} else { if(_tim7I) {_tim7I = 0; _tim7P = millis();} else { if (_tim7O) {if ( _isTimer(_tim7P, 150000)) _tim7O = 0;}}}
if(( ((_gtv15) == (7)) && (_RTCAlO1) )) {_tim8O = 1; _tim8I = 1;} else { if(_tim8I) {_tim8I = 0; _tim8P = millis();} else { if (_tim8O) {if ( _isTimer(_tim8P, 175000)) _tim8O = 0;}}}
if(( ((_gtv15) == (8)) && (_RTCAlO1) )) {_tim6O = 1; _tim6I = 1;} else { if(_tim6I) {_tim6I = 0; _tim6P = millis();} else { if (_tim6O) {if ( _isTimer(_tim6P, 200000)) _tim6O = 0;}}}
 if (1)
{ _RTCAlO1 = (((_tRTC1.minute()) == 0) && ((_tRTC1.second()) == 0));}
    else
{_RTCAlO1 = 0;}
_gtv12 = _swi7;
digitalWrite(6, !(_swi7));
if (1) { if (! _gen2I) { _gen2I = 1; _gen2O = 1; _gen2P = millis(); } } else { _gen2I = 0 ; _gen2O= 0;}
 if (_gen2I) {  if ( _isTimer ( _gen2P , 500 )) { _gen2P = millis(); _gen2O = ! _gen2O;}}

if (_gen2O) 
   { 
   if (! _count3I)  
      {
       _count3P = _count3P+1;
       _count3I = 1;
      }
   }
else
   {
   _count3I=0;
   }
if (_gtv10) _count3P = 0;

if ((_gtv26) == (60)) 
   { 
   if (! _count4I)  
      {
       _count4P = _count4P+1;
       _count4I = 1;
      }
   }
else
   {
   _count4I=0;
   }
if (_gtv30) _count4P = 0;
if(0)
{_swi8=0;}
else
{_swi8=0;}

if ((_gtv17) == (60)) 
   { 
   if (! _count5I)  
      {
       _count5P = _count5P+1;
       _count5I = 1;
      }
   }
else
   {
   _count5I=0;
   }
if (_gtv31) _count5P = 0;

if ((_gtv9) == (24)) 
   { 
   if (! _count1I)  
      {
       _count1P = _count1P+1;
       _count1I = 1;
      }
   }
else
   {
   _count1I=0;
   }
_gtv26 = _count3P;
_gtv10 =  _count3P  >=  60;
_gtv17 = _count4P;
_gtv30 =  _count4P  >=  60;
_gtv9 = _count5P;
_gtv32 = _count1P;
_gtv31 =  _count5P  >=  24;
if(_gtv6)
{_swi9=1;}
else
{_swi9=0;}
if(_gtv11)
{_swi2=1;}
else
{_swi2=0;}
if(_gtv12)
{_swi5=1;}
else
{_swi5=0;}
_modbusSlaveDataTable_4[0] = _gtv7;
_modbusSlaveDataTable_4[1] = _gtv5;
_modbuseSetSlId2_SlId = 1;
_modbusSlaveDataTable_4[2] = _gtv27;
_modbusSlaveDataTable_4[3] = _gtv15;
_gtv23 = (_modbusSlaveDataTable_4[4]);
_modbusSlaveDataTable_4[5] = _gtv4;
_modbusSlaveDataTable_4[6] = _gtv1;
_modbusSlaveDataTable_4[7] = _gtv2;
_modbusSlaveDataTable_4[8] = _gtv32;
_modbusSlaveDataTable_4[9] = _swi9;
_modbusSlaveDataTable_4[10] = _swi2;
_modbusSlaveDataTable_4[11] = _swi5;
_gtv13 = ((_modbusSlaveDataTable_4[12])) == (1);
_gtv28 = ((_modbusSlaveDataTable_4[13])) == (1);
_modbusSlaveDataTable_4[14] = _gtv18;
_modbusSlaveDataTable_4[15] = _gtv16;
_gtv35 = ((_modbusSlaveDataTable_4[16])) == (1);
 if (1)
{ _RTCAlO2 = (((_tRTC1.hour()) == 0) && ((_tRTC1.minute()) == 0) && ((_tRTC1.second()) == 0));}
    else
{_RTCAlO2 = 0;}
if (( ((_gtv5) > (_gtv16)) || (_RTCAlO2) )) {
_gtv16 = _gtv5;
}
if (( ((_gtv5) < (_gtv18)) || (_RTCAlO2) )) {
_gtv18 = _gtv5;
}




}
bool _isTimer(unsigned long startTime, unsigned long period )
  {
  unsigned long currentTime;
currentTime = millis();
if (currentTime>= startTime) {return (currentTime>=(startTime + period));} else {return (currentTime >=(4294967295-startTime+period));}
  }

ISR(TIMER2_OVF_vect)
{ TCNT2=100;
if(_PWDC >= 1000){asm volatile ("jmp 0x0000");}else{_PWDC = _PWDC+1;};
}
byte _modbusSlavePoll()
{
if( !_modbusSlaveTCPClient.connected()) {_modbusSlaveTCPClient = _modbusSlaveTCPServer.available();}
if (_modbusSlaveTCPClient) { _modbusGetSlaveRxBuffer();} else{return 0;}
if(_modbusSlaveBufferSize ==0) {return 0;}
if ((_modbusSlaveBuffer[0] != _modbuseSetSlId2_SlId) && (_modbusSlaveBuffer[0] != 0)) return 0;
  byte exception =  _modbusValidateRequest();
  if (exception > 0) {

    if (exception != 255) { _modbusSlaveBuildException( exception );
      _modbusSlaveSendTxBuffer();
    }  
    return exception;
  }

switch ( _modbusSlaveBuffer[1] ) {
 case 3 :
      return process_modbus_FC3(4);
      break;
  case 6 :
      return process_modbus_FC6();
      break;
 case 16 :
      return process_modbus_FC16();
      break;
default:
      break;
  }
  return 25;
}
byte _modbusValidateRequest() {
  boolean isSupported = false;
  for (uint8_t i = 0; i < sizeof( _modbusSlave_fctsupported ); i++) {
    if (_modbusSlave_fctsupported[i] == _modbusSlaveBuffer[1]) {
      isSupported = 1;
      break;
    }
  }
 if (!isSupported) { return 1;}
int intRegs = 0;
  byte byteRegs;
    switch ( _modbusSlaveBuffer[1] ) {
case 6 :
if(!(checkModbusAddres(( word( _modbusSlaveBuffer[2], _modbusSlaveBuffer[3]) ),4))){return 2;}     
        break;
case 3 :
case 16 :
 if(!(checkModbusRange((word( _modbusSlaveBuffer[2], _modbusSlaveBuffer[3])), (word( _modbusSlaveBuffer[4], _modbusSlaveBuffer[5])),4))){return 2;}    
 break;
}
  return 0; // OK, no exception code thrown
}
bool checkModbusAddres(int addr, byte table)
{
return (!(( modbusSlaveIndexForAddres(addr,table)) == -1));
}
int modbusSlaveIndexForAddres(int addr, byte table)
{
int tableSize = 0;
switch (table) {
case 4:
tableSize = 17;
break;
}
for (byte i = 0; i < tableSize; i++) {if((modbusSlaveAddresFromIndex(i,table)) == addr){return  i;}}
return -1;
}
int modbusSlaveAddresFromIndex(byte index, byte table)
{
switch (table) {
case 4:
return _modbusSlaveAddresTable_4[index];
break;
}
return -1;
}
bool checkModbusRange(int startAddr, int addrNumber, byte table)
{
for (int i=0; i < addrNumber; i++) {if(!(checkModbusAddres((startAddr+i),table))){return false;}}
return true;
}
void  _modbusSlaveBuildException( byte exception ) {
  byte func = _modbusSlaveBuffer[1];  
  _modbusSlaveBuffer[0] = _modbuseSetSlId2_SlId;
  _modbusSlaveBuffer[1] = func + 0x80;
  _modbusSlaveBuffer[ 2 ] = exception;
  _modbusSlaveBufferSize = 3;}
void _modbusSlaveSendTxBuffer()
{
 if(_modbusSlaveBuffer[0] == 0) {_modbusSlaveTCPClient.stop(); return;}
_modbusSlaveMBAPBuffer[4] = highByte(_modbusSlaveBufferSize);
_modbusSlaveMBAPBuffer[5] = lowByte(_modbusSlaveBufferSize);
_modbusSlaveTCPClient.write( _modbusSlaveMBAPBuffer, 6 );
_modbusSlaveTCPClient.write( _modbusSlaveBuffer, _modbusSlaveBufferSize );
 _modbusSlaveBufferSize = 0;
}
byte _modbusGetSlaveRxBuffer()
{
byte currentByte = 0;
boolean bBuffOverflow = false;
byte currentByteIndex = 0;
 _modbusSlaveBufferSize = 0;
 while (_modbusSlaveTCPClient.available() ) {currentByte = _modbusSlaveTCPClient.read();
if (currentByteIndex < 6) 
	{_modbusSlaveMBAPBuffer[currentByteIndex] = currentByte; } 
else
{
  _modbusSlaveBuffer[ _modbusSlaveBufferSize ] = currentByte; 
  _modbusSlaveBufferSize ++;
 if (_modbusSlaveBufferSize >= 64) bBuffOverflow = true;}
	currentByteIndex++;
  }
  if (bBuffOverflow) {return -3; }
  return _modbusSlaveBufferSize;
}
byte process_modbus_FC3(byte table)
{
  byte startAddr = word( _modbusSlaveBuffer[2], _modbusSlaveBuffer[3] );
  byte byteRegsno = word( _modbusSlaveBuffer[4], _modbusSlaveBuffer[5] );
  byte i;
  int value;
byte index;
  _modbusSlaveBuffer[ 2 ]  = byteRegsno * 2;
  _modbusSlaveBufferSize = 3;
  for (i = startAddr; i < startAddr + byteRegsno; i++) {
index = modbusSlaveIndexForAddres(i, table);
if (table == 4) {value = _modbusSlaveDataTable_4[index]; } 
  _modbusSlaveBuffer[ _modbusSlaveBufferSize ] = highByte(value);
    _modbusSlaveBufferSize++;
    _modbusSlaveBuffer[ _modbusSlaveBufferSize ] = lowByte(value);
    _modbusSlaveBufferSize++;
  }
   _modbusSlaveSendTxBuffer();
  return _modbusSlaveBufferSize + 2;
}
byte process_modbus_FC6()
{
 byte addres = word( _modbusSlaveBuffer[2], _modbusSlaveBuffer[3] );
 byte index;
index = modbusSlaveIndexForAddres(addres, 4);
_modbusSlaveDataTable_4[index] =word( _modbusSlaveBuffer[4], _modbusSlaveBuffer[5] );
  _modbusSlaveBufferSize = 6;
  _modbusSlaveSendTxBuffer();
  return _modbusSlaveBufferSize + 2;
}
byte process_modbus_FC16(  ) 
{
byte func = _modbusSlaveBuffer[1];
  byte startAddr = _modbusSlaveBuffer[2] << 8 | _modbusSlaveBuffer[3];
  byte byteRegsno = _modbusSlaveBuffer[4] << 8 | _modbusSlaveBuffer[5];
  byte i;
 byte index;
  _modbusSlaveBuffer[4]   = 0;
  _modbusSlaveBuffer[5]   = byteRegsno;
  _modbusSlaveBufferSize = 6;
  for (i = 0; i < byteRegsno; i++) {
index = modbusSlaveIndexForAddres((startAddr+i), 4);
_modbusSlaveDataTable_4[index] =word( _modbusSlaveBuffer[ 7 + i * 2 ],  _modbusSlaveBuffer[8 + i * 2 ]);
  }
  _modbusSlaveSendTxBuffer();
  return _modbusSlaveBufferSize +2;
}
float _convertDS18x2xData(byte type_s, byte data[12])
{
  int16_t raw = (data[1] << 8) | data[0];
  if (type_s) 
  {
  raw = raw << 3; 
  if (data[7] == 0x10) { raw = (raw & 0xFFF0) + 12 - data[6]; }
  }
else 
  {
   byte cfg = (data[4] & 0x60);
   if (cfg == 0x00) raw = raw & ~7;   else if (cfg == 0x20) raw = raw & ~3;  else if (cfg == 0x40) raw = raw & ~1;
  }
return  (float)raw / 16.0;
}
float _readDS18_ow7(byte addr[8], byte type_s)
{  byte data[12];
byte i;
_ow7.reset();
_ow7.select(addr);
_ow7.write(0xBE);
for ( i = 0; i < 9; i++) {
 data[i] = _ow7.read();}
_ow7.reset();
_ow7.select(addr);
_ow7.write(0x44, 1);
return _convertDS18x2xData(type_s, data);}int EEPROMReadInt(int p_address)
        {
        byte lowByte = EEPROM.read(p_address);
        byte highByte = EEPROM.read(p_address + 1);

        return ((lowByte << 0) & 0xFF) + ((highByte << 8) & 0xFF00);
        }
void EEPROMWriteInt(int p_address, int p_value)
       {
        byte lowByte = ((p_value >> 0) & 0xFF);
        byte highByte = ((p_value >> 8) & 0xFF);

        EEPROM.write(p_address, lowByte);
        EEPROM.write(p_address + 1, highByte);
        }
struct UB_93993507 _func_UB_93993507(struct UB_93993507 _ubInstans, int ubi_200586030, int ubi_679972, int ubi_251662263, int ubi_149551738, int ubi_235635076)
{
String ubo_98898145 = _ubInstans.ubo_98898145;
String ubo_190631320 = _ubInstans.ubo_190631320;
String ubo_242595348 = _ubInstans.ubo_242595348;
String ubo_2845936 = _ubInstans.ubo_2845936;
String ubo_221470420 = _ubInstans.ubo_221470420;
int _gtv6 = _ubInstans._gtv6;
int _gtv7 = _ubInstans._gtv7;
int _gtv8 = _ubInstans._gtv8;
int _gtv9 = _ubInstans._gtv9;
int _gtv10 = _ubInstans._gtv10;
String _gtv1 = _ubInstans._gtv1;
String _gtv2 = _ubInstans._gtv2;
String _gtv3 = _ubInstans._gtv3;
String _gtv4 = _ubInstans._gtv4;
String _gtv5 = _ubInstans._gtv5;
String _swi1 = _ubInstans._swi1;
String _swi2 = _ubInstans._swi2;
String _swi3 = _ubInstans._swi3;
String _swi4 = _ubInstans._swi4;
String _swi5 = _ubInstans._swi5;
if((_gtv6) > (9))
{_swi1=_gtv1;}
else
{_swi1=((String("0")) + (_gtv1));}
if((_gtv7) > (9))
{_swi2=_gtv2;}
else
{_swi2=((String("0")) + (_gtv2));}
if((_gtv8) > (9))
{_swi3=_gtv3;}
else
{_swi3=((String("0")) + (_gtv3));}
if((_gtv9) > (9))
{_swi4=_gtv4;}
else
{_swi4=((String("0")) + (_gtv4));}
if((_gtv10) > (9))
{_swi5=_gtv5;}
else
{_swi5=((String("0")) + (_gtv5));}
_gtv6 = ubi_200586030;
_gtv1 = (String(_gtv6));
ubo_98898145 = _swi1;
_gtv7 = ubi_679972;
_gtv2 = (String(_gtv7));
ubo_190631320 = _swi2;
_gtv8 = ubi_251662263;
_gtv3 = (String(_gtv8));
ubo_242595348 = _swi3;
_gtv9 = ubi_149551738;
_gtv4 = (String(_gtv9));
ubo_2845936 = _swi4;
_gtv10 = ubi_235635076;
_gtv5 = (String(_gtv10));
ubo_221470420 = _swi5;
_ubInstans.ubo_98898145 = ubo_98898145;
_ubInstans.ubo_190631320 = ubo_190631320;
_ubInstans.ubo_242595348 = ubo_242595348;
_ubInstans.ubo_2845936 = ubo_2845936;
_ubInstans.ubo_221470420 = ubo_221470420;
_ubInstans._gtv6 = _gtv6;
_ubInstans._gtv7 = _gtv7;
_ubInstans._gtv8 = _gtv8;
_ubInstans._gtv9 = _gtv9;
_ubInstans._gtv10 = _gtv10;
_ubInstans._gtv1 = _gtv1;
_ubInstans._gtv2 = _gtv2;
_ubInstans._gtv3 = _gtv3;
_ubInstans._gtv4 = _gtv4;
_ubInstans._gtv5 = _gtv5;
_ubInstans._swi1 = _swi1;
_ubInstans._swi2 = _swi2;
_ubInstans._swi3 = _swi3;
_ubInstans._swi4 = _swi4;
_ubInstans._swi5 = _swi5;
return _ubInstans;
}

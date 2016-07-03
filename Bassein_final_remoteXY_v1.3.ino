#define REMOTEXY_MODE__HC05_HARDSERIAL
#include <Wire.h>
#include "RTClib.h"
#include <OneWire.h>
#include <EEPROM.h>
#include <RemoteXY.h>
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
UB_93993507 UB_93993507_Instance3;
UB_93993507 UB_93993507_Instance1;
int UB_93993507_ubi_200586030 = 0;
int UB_93993507_ubi_679972 = 0;
int UB_93993507_ubi_251662263 = 0;
int UB_93993507_ubi_149551738 = 0;
int UB_93993507_ubi_235635076 = 0;
#define REMOTEXY_SERIAL Serial1
#define REMOTEXY_SERIAL_SPEED 9600
unsigned char RemoteXY_CONF[] = {3, 39, 62, 2, 5, 5, 4, 1, 0, 25, 29, 12, 12, 2, 2, 208, 146, 208, 186, 208, 187, 0, 3, 136, 1, 48, 96, 13, 2, 2, 1, 0, 3, 29, 12, 12, 2, 2, 208, 149, 0, 67, 5, 1, 48, 19, 14, 2, 1, 3, 67, 5, 27, 48, 18, 14, 2, 1, 3, 65, 2, 1, 32, 9, 9, 2, 1, 65, 2, 17, 32, 9, 9, 2, 1, 67, 5, 51, 30, 23, 8, 2, 0, 5, 67, 4, 5, 19, 28, 7, 2, 1, 9, 67, 5, 79, 58, 22, 5, 2, 1, 9, 67, 5, 71, 58, 7, 5, 2, 1, 3, 67, 5, 78, 30, 23, 8, 2, 0, 5, 129, 0, 6, 43, 8, 3, 9, 1, 208, 178, 208, 190, 208, 180, 209, 139, 0, 129, 0, 30, 43, 12, 3, 9, 1, 208, 178, 208, 190, 208, 183, 208, 180, 209, 131, 209, 133, 208, 176, 0, 129, 0, 2, 44, 10, 3, 9, 2, 49, 32, 208, 155, 208, 184, 209, 130, 209, 128, 0, 129, 0, 51, 25, 22, 3, 9, 0, 208, 154, 208, 190, 208, 187, 32, 208, 165, 208, 187, 32, 69, 69, 82, 79, 77, 0, 129, 0, 17, 28, 9, 3, 9, 1, 208, 148, 208, 190, 208, 183, 208, 184, 209, 128, 0, 129, 0, 0, 28, 11, 3, 9, 1, 208, 164, 208, 184, 208, 187, 209, 140, 209, 130, 209, 128, 0, 130, 0, 0, 42, 46, 21, 0, 1, 129, 0, 84, 24, 13, 3, 9, 0, 208, 189, 208, 176, 32, 208, 189, 208, 176, 209, 129, 208, 190, 209, 129, 0, 129, 0, 7, 14, 24, 3, 9, 1, 208, 146, 209, 128, 208, 181, 208, 188, 209, 143, 32, 209, 129, 208, 184, 209, 129, 209, 130, 208, 181, 208, 188, 209, 139, 0, 129, 0, 86, 55, 10, 3, 9, 1, 85, 112, 116, 105, 109, 101, 0, 129, 0, 71, 55, 6, 3, 9, 1, 208, 148, 208, 189, 208, 184, 0, 131, 1, 1, 2, 36, 8, 2, 1, 208, 152, 208, 189, 208, 180, 208, 184, 208, 186, 208, 176, 209, 134, 208, 184, 209, 143, 0, 131, 0, 38, 2, 35, 8, 2, 2, 208, 163, 208, 191, 209, 128, 208, 176, 208, 178, 208, 187, 208, 181, 208, 189, 208, 184, 208, 181, 0, 129, 0, 14, 44, 10, 3, 9, 2, 50, 32, 208, 155, 208, 184, 209, 130, 209, 128, 0, 129, 0, 26, 44, 10, 3, 9, 2, 51, 32, 208, 155, 208, 184, 209, 130, 209, 128, 0, 129, 0, 38, 44, 10, 3, 9, 2, 52, 32, 208, 155, 208, 184, 209, 130, 209, 128, 0, 129, 0, 50, 44, 10, 3, 9, 2, 53, 32, 208, 155, 208, 184, 209, 130, 209, 128, 0, 129, 0, 61, 44, 10, 3, 9, 2, 54, 32, 208, 155, 208, 184, 209, 130, 209, 128, 0, 129, 0, 73, 44, 10, 3, 9, 2, 55, 32, 208, 155, 208, 184, 209, 130, 209, 128, 0, 129, 0, 85, 44, 10, 3, 9, 2, 56, 32, 208, 155, 208, 184, 209, 130, 209, 128, 0, 130, 1, 1, 42, 98, 20, 0, 2, 129, 0, 2, 24, 14, 4, 9, 2, 208, 151, 208, 176, 208, 191, 208, 184, 209, 129, 209, 140, 0, 129, 0, 24, 24, 13, 4, 9, 2, 49, 32, 208, 155, 208, 184, 209, 130, 209, 128, 0};
struct {
unsigned char litr_hl;
unsigned char kol_hlor;
unsigned char save_eerom;
char temp_vod[3];
char temp_vozd[3];
unsigned char filtr_g;
unsigned char dozatr_g;
char eerom_hl[5];
char vrem_sist[9];
char hour[9];
char dey[3];
char hlor_nasos[5];
 unsigned char connect_flag;
} RemoteXY;
OneWire  _ow7(7);
int _PWDC = 0;
int _gtv2;
int _gtv1;
int _gtv4;
String _gtv3;
bool _gtv6 = 0;
int _gtv5;
int _gtv7;
int _gtv9;
bool _gtv10 = 0;
bool _gtv11 = 0;
bool _gtv12 = 0;
bool _gtv13 = 0;
int _gtv15;
int _gtv17;
String _gtv20;
int _gtv23;
int _gtv26;
int _gtv27;
bool _gtv28 = 0;
bool _gtv30 = 0;
bool _gtv31 = 0;
int _gtv32 = 0;
bool _count1I = 0;
int _count1P = 0;
bool _count2I = 0;
int _count2P = 0;
bool _tim15I = 0;
bool _tim15O = 0;
unsigned long _tim15P = 0UL;
String _mux2;
bool _tim11I = 0;
bool _tim11O = 0;
unsigned long _tim11P = 0UL;
int _swi3;
bool _gen1I = 0;
bool _gen1O = 0;
unsigned long _gen1P = 0UL;
bool _tim6I = 0;
bool _tim6O = 0;
unsigned long _tim6P = 0UL;
bool _gen2I = 0;
bool _gen2O = 0;
unsigned long _gen2P = 0UL;
bool _tim8I = 0;
bool _tim8O = 0;
unsigned long _tim8P = 0UL;
bool _count4I = 0;
int _count4P = 0;
bool _swi11;
bool _bounse1S = 0;
bool _bounse1O = 0;
unsigned long _bounse1P = 0UL;
bool _tim13I = 0;
bool _tim13O = 0;
unsigned long _tim13P = 0UL;
bool _tim9I = 0;
bool _tim9O = 0;
unsigned long _tim9P = 0UL;
bool _SEEPR1OSN = 0;
bool _count3I = 0;
int _count3P = 0;
bool _RTCAlO1 = 0;
int _swi4;
bool _bounseInputD8S = 0;
bool _bounseInputD8O = 0;
unsigned long _bounseInputD8P = 0UL;
unsigned long _d18x2x2Tti = 0UL;
float _d18x2x2O = 0.00;
bool _tim12I = 0;
bool _tim12O = 0;
unsigned long _tim12P = 0UL;
unsigned long _d18x2x1Tti = 0UL;
float _d18x2x1O = 0.00;
bool _swi2;
bool _tim7I = 0;
bool _tim7O = 0;
unsigned long _tim7P = 0UL;
int _swi5;
bool _tim14I = 0;
bool _tim14O = 0;
unsigned long _tim14P = 0UL;
String _mux1;
bool _tim10I = 0;
bool _tim10O = 0;
unsigned long _tim10P = 0UL;
void setup()
{
RemoteXY_Init ();
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
{RemoteXY_Handler  ();
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
UB_93993507_Instance3 = _func_UB_93993507(UB_93993507_Instance3, UB_93993507_ubi_200586030, UB_93993507_ubi_679972, UB_93993507_ubi_251662263, UB_93993507_ubi_149551738, UB_93993507_ubi_235635076);
if(_gtv28){ if(!_SEEPR1OSN){ EEPROMWriteInt(0, _gtv23); _SEEPR1OSN=1;} }else{ if(_SEEPR1OSN){_SEEPR1OSN=0;}}
_gtv2 = (_tRTC1.hour());
_gtv1 = (_tRTC1.minute());
_gtv4 = (_tRTC1.second());
_gtv3 = ((UB_93993507_Instance3.ubo_98898145) + (String(":")) + (UB_93993507_Instance3.ubo_190631320) + (String(":")) + (UB_93993507_Instance3.ubo_242595348));
_gtv15 = _gtv27;
_gtv27 = (EEPROMReadInt(0));
bool   _bounceTmpD1 = _bounseInputD8O;

if (_bounse1S) 
    {
     if (millis() >= (_bounse1P + 40)) 
         {_bounse1O=  _bounceTmpD1; _bounse1S=0;}
     }
else
    {
     if ( _bounceTmpD1 != _bounse1O )
         {_bounse1S=1; _bounse1P = millis();} 
      } 
if(_isTimer(_d18x2x1Tti, 5000)) {
_d18x2x1Tti = millis(); 
_d18x2x1O=  _readDS18_ow7(_d18x2x1Addr, 0);}
if(_isTimer(_d18x2x2Tti, 6000)) {
_d18x2x2Tti = millis(); 
_d18x2x2O=  _readDS18_ow7(_d18x2x2Addr, 0);}
if (1) {
_gtv6 = _bounse1O;
}
if (((_d18x2x1O)) < (60.00)) {
_gtv7 = (_d18x2x1O);
}
if (((_d18x2x2O)) < (60.00)) {
_gtv5 = (_d18x2x2O);
}
if(( (( (( (((_tRTC1.hour())) >= (0)) && (((_tRTC1.hour())) <= (8)) )) || (_tim7O) )) || (_gen1O) ))
{_swi11=1;}
else
{_swi11=0;}
if(_gtv6) {_tim7O = 1; _tim7I = 1;} else { if(_tim7I) {_tim7I = 0; _tim7P = millis();} else { if (_tim7O) {if ( _isTimer(_tim7P, 180000)) _tim7O = 0;}}}
if (( (((_tRTC1.hour())) >= (9)) && (((_tRTC1.hour())) <= (23)) )) { if (! _gen1I) { _gen1I = 1; _gen1O = 1; _gen1P = millis(); } } else { _gen1I = 0 ; _gen1O= 0;}
 if (_gen1I) {  if ( _isTimer ( _gen1P , 1800000 )) { _gen1P = millis(); _gen1O = ! _gen1O;}}
digitalWrite(9, !(_swi11));
_gtv11 = _swi11;
if(_gtv13) {_tim12O = 1; _tim12I = 1;} else { if(_tim12I) {_tim12I = 0; _tim12P = millis();} else { if (_tim12O) {if ( _isTimer(_tim12P, 600000)) _tim12O = 0;}}}
if(( ((_gtv15) == (0)) && (_RTCAlO1) )) {_tim8O = 1; _tim8I = 1;} else { if(_tim8I) {_tim8I = 0; _tim8P = millis();} else { if (_tim8O) {if ( _isTimer(_tim8P, 25000)) _tim8O = 0;}}}
if(( ((_gtv15) == (1)) && (_RTCAlO1) )) {_tim9O = 1; _tim9I = 1;} else { if(_tim9I) {_tim9I = 0; _tim9P = millis();} else { if (_tim9O) {if ( _isTimer(_tim9P, 50000)) _tim9O = 0;}}}
if(( ((_gtv15) == (2)) && (_RTCAlO1) )) {_tim10O = 1; _tim10I = 1;} else { if(_tim10I) {_tim10I = 0; _tim10P = millis();} else { if (_tim10O) {if ( _isTimer(_tim10P, 75000)) _tim10O = 0;}}}
if(( (( (_tim12O) ^ (( (( (_tim8O) ^ (_tim9O) )) ^ (( (_tim10O) ^ (_tim11O) )) )) )) ^ (( (( (_tim6O) ^ (_tim13O) )) ^ (( (_tim14O) ^ (_tim15O) )) )) ))
{_swi2=1;}
else
{_swi2=0;}
if(( ((_gtv15) == (3)) && (_RTCAlO1) )) {_tim11O = 1; _tim11I = 1;} else { if(_tim11I) {_tim11I = 0; _tim11P = millis();} else { if (_tim11O) {if ( _isTimer(_tim11P, 100000)) _tim11O = 0;}}}
if(( ((_gtv15) == (4)) && (_RTCAlO1) )) {_tim6O = 1; _tim6I = 1;} else { if(_tim6I) {_tim6I = 0; _tim6P = millis();} else { if (_tim6O) {if ( _isTimer(_tim6P, 125000)) _tim6O = 0;}}}
if(( ((_gtv15) == (5)) && (_RTCAlO1) )) {_tim13O = 1; _tim13I = 1;} else { if(_tim13I) {_tim13I = 0; _tim13P = millis();} else { if (_tim13O) {if ( _isTimer(_tim13P, 150000)) _tim13O = 0;}}}
if(( ((_gtv15) == (6)) && (_RTCAlO1) )) {_tim14O = 1; _tim14I = 1;} else { if(_tim14I) {_tim14I = 0; _tim14P = millis();} else { if (_tim14O) {if ( _isTimer(_tim14P, 175000)) _tim14O = 0;}}}
if(( ((_gtv15) == (7)) && (_RTCAlO1) )) {_tim15O = 1; _tim15I = 1;} else { if(_tim15I) {_tim15I = 0; _tim15P = millis();} else { if (_tim15O) {if ( _isTimer(_tim15P, 200000)) _tim15O = 0;}}}
 if (1)
{ _RTCAlO1 = (((_tRTC1.minute()) == 0) && ((_tRTC1.second()) == 0));}
    else
{_RTCAlO1 = 0;}
_gtv12 = _swi2;
digitalWrite(6, !(_swi2));
if (1) { if (! _gen2I) { _gen2I = 1; _gen2O = 1; _gen2P = millis(); } } else { _gen2I = 0 ; _gen2O= 0;}
 if (_gen2I) {  if ( _isTimer ( _gen2P , 500 )) { _gen2P = millis(); _gen2O = ! _gen2O;}}

if (_gen2O) 
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
if (_gtv10) _count1P = 0;

if ((_gtv26) == (60)) 
   { 
   if (! _count2I)  
      {
       _count2P = _count2P+1;
       _count2I = 1;
      }
   }
else
   {
   _count2I=0;
   }
if (_gtv30) _count2P = 0;
if(0)
{_swi5=0;}
else
{_swi5=0;}

if ((_gtv17) == (60)) 
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
if (_gtv31) _count3P = 0;

if ((_gtv9) == (24)) 
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
UB_93993507_ubi_200586030 = _gtv9;
UB_93993507_ubi_679972 = _gtv17;
UB_93993507_ubi_251662263 = _gtv26;
UB_93993507_ubi_149551738 = 0;
UB_93993507_ubi_235635076 = 0;
UB_93993507_Instance1 = _func_UB_93993507(UB_93993507_Instance1, UB_93993507_ubi_200586030, UB_93993507_ubi_679972, UB_93993507_ubi_251662263, UB_93993507_ubi_149551738, UB_93993507_ubi_235635076);
_gtv26 = _count1P;
_gtv10 =  _count1P  >=  60;
_gtv17 = _count2P;
_gtv30 =  _count2P  >=  60;
_gtv9 = _count3P;
_gtv32 = _count4P;
_gtv31 =  _count3P  >=  24;
_gtv20 = ((UB_93993507_Instance1.ubo_98898145) + (String(":")) + (UB_93993507_Instance1.ubo_190631320) + (String(":")) + (UB_93993507_Instance1.ubo_242595348));
if(_gtv11)
{_swi3=255;}
else
{_swi3=0;}
if(_gtv12)
{_swi4=255;}
else
{_swi4=0;}
if((_gtv15) == 0) {_mux2 = String("1 L");}
if((_gtv15) == 1) {_mux2 = String("2 L");}
if((_gtv15) == 2) {_mux2 = String("3 L");}
if((_gtv15) == 3) {_mux2 = String("4 L");}
if((_gtv15) == 4) {_mux2 = String("5 L");}
if((_gtv15) == 5) {_mux2 = String("6 L");}
if((_gtv15) == 6) {_mux2 = String("7 L");}
if((_gtv15) == 7) {_mux2 = String("8 L");}
if((_gtv27) == 0) {_mux1 = String("1 L");}
if((_gtv27) == 1) {_mux1 = String("2 L");}
if((_gtv27) == 2) {_mux1 = String("3 L");}
if((_gtv27) == 3) {_mux1 = String("4 L");}
if((_gtv27) == 4) {_mux1 = String("5 L");}
if((_gtv27) == 5) {_mux1 = String("6 L");}
if((_gtv27) == 6) {_mux1 = String("7 L");}
if((_gtv27) == 7) {_mux1 = String("8 L");}
((String(_gtv7))).toCharArray((RemoteXY.temp_vod), 3);
((String(_gtv5))).toCharArray((RemoteXY.temp_vozd), 3);
RemoteXY.filtr_g = _swi3;
RemoteXY.dozatr_g = _swi4;
(_mux1).toCharArray((RemoteXY.eerom_hl), 5);
(_gtv3).toCharArray((RemoteXY.vrem_sist), 9);
(_gtv20).toCharArray((RemoteXY.hour), 9);
((String(_gtv32))).toCharArray((RemoteXY.dey), 3);
(_mux2).toCharArray((RemoteXY.hlor_nasos), 5);
_gtv13 = (RemoteXY.litr_hl);
_gtv23 = (RemoteXY.kol_hlor);
_gtv28 = (RemoteXY.save_eerom);




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

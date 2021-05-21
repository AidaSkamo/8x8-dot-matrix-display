#include <LedControl.h>

int DIN = 7;
int CS =  6;
int CLK = 5;

LedControl lcd=LedControl(DIN,CLK,CS,3);
int devices;


void setup(){
     //we have already set the number of devices when we created the LedControl
  devices=lcd.getDeviceCount();
  //we have to init all devices in a loop
  for(int address=0;address<devices;address++) {
    /*The MAX72XX is in power-saving mode on startup*/
    lcd.shutdown(address,false);
    /* Set the brightness to a medium values */
    lcd.setIntensity(address,15);
    /* and clear the display */
    lcd.clearDisplay(address);
  }
}

void loop(){

   byte A[8] = {0x7e, 0x81, 0x81, 0xff, 0xff, 0x81, 0x81, 0x00};
   byte I[8] = {0x7e, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x7e};
   byte D[8] = {0xfc, 0xfe, 0xc6, 0xc6, 0xc6, 0xc6, 0xfe, 0xfc};
   byte S[8] = {0x00, 0x78, 0x80, 0x80, 0x70, 0x08, 0x08, 0xf0};
   byte K[8] = {0xc6, 0xc8, 0xd0, 0xe0, 0xe0, 0xd0, 0xc8, 0xc6};
   byte M[8] = {0xc3, 0xe7, 0xdb, 0xdb, 0xc3, 0xc3, 0xc3, 0xc3};
   byte O[8] = {0x3c, 0x7e, 0xc3, 0xc3, 0xc3, 0xc3, 0x7e, 0x3c};


   printByte(A);
   printByte(I);
   printByte(D);
   printByte(A);
   printByte(S);
   printByte(K);
   printByte(A);
   printByte(M);
   printByte(O);
    delay(50);
}



void printByte(byte character [])
{
  int i = 0;
  for(int address=0;address<devices;address++){ 
  for(i=0;i<8;i++){
    delay(50);
    lcd.setRow(address,i,character[i]);
  }
  }
}

#include "mbed.h"
#include "PS3BT.h"
#include "usbhub.h"
 
Serial pc(USBTX, USBRX,115200);
 
//Nucleo F303K8
USB Usb(D11, D12, D13, A3, A2); // mosi, miso, sclk, ssel, intr


//Nucleo F446ZE
//USB Usb(PE_14, PE_13,PE_12,PG_14,PD_15);
//USB Usb(PE_6,PE_5,PE_2,PE_4, PD_15); 

BTD Btd(&Usb);
PS3BT PS3(&Btd);

int main(){
    if (Usb.Init() == -1){
        pc.printf("\r\nOSC did not start");
        while (1); // Halt
    }
    pc.printf("\r\nPS3 USB Library Started");
 
    while (1){
        Usb.Task();
        
        if (PS3.PS3Connected) {
            //printf("\n\r%d %d %d %d %d",PS3.getStatus(Low),PS3.getStatus(High),PS3.getStatus(Full),PS3.getStatus(BluetoothRumble),PS3.getStatus(Bluetooth));
            
            
            
            printf("\n\r%3d %3d %3d %3d",PS3.getAnalogHat(LeftHatX),PS3.getAnalogHat(LeftHatY),PS3.getAnalogHat(RightHatX),PS3.getAnalogHat(RightHatY));
            printf(" %3d %3d %3d %3d",PS3.getAnalogButton(UP),PS3.getAnalogButton(DOWN),PS3.getAnalogButton(RIGHT),PS3.getAnalogButton(LEFT));
            printf(" %3d %3d %3d %3d",PS3.getAnalogButton(TRIANGLE),PS3.getAnalogButton(CIRCLE),PS3.getAnalogButton(CROSS),PS3.getAnalogButton(SQUARE));
            printf(" %3d %3d %3d %3d",PS3.getAnalogButton(L1),PS3.getAnalogButton(R1),PS3.getAnalogButton(L2),PS3.getAnalogButton(R2));
            //printf(" %3d %3d",PS3.getAnalogButton(SELECT),PS3.getAnalogButton(START));
            //printf(" %3d %3d",PS3.getAnalogButton(L3),PS3.getAnalogButton(R3));
            
            
        }else{
            pc.printf("not connect\n");
        }
    }
}
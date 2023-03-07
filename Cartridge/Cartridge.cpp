#include "Cartridge.h"

Cartridge::Cartridge() 
{
    for (auto &i : programData)
        i = 0x00;
    programData[0] = 0x60;  //0x200 
    programData[1] = 0x33;
    programData[2] = 0x60;  //0x202
    programData[3] = 0x12;  
    programData[4] = 0x60;  //0x204
    programData[5] = 0xA1;
    programData[6] = 0x60;  //0x206   
    programData[7] = 0x11;
    programData[8] = 0x60;  //0x208  
    programData[9] = 0x12;
    programData[8] = 0x60;  //0x20A  
    programData[9] = 0x13;
}
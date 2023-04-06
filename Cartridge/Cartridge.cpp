#include "Cartridge.h"

Cartridge::Cartridge() 
{
    for (auto &i : programData)
        i = 0x00;
    programData[0] = 0xF0;  //0x200 
    programData[1] = 0x0A;
    programData[2] = 0x12;  //0x202
    programData[3] = 0x00;  
    programData[4] = 0x12;  //0x204
    programData[5] = 0x02;
    programData[6] = 0xE0;  //0x206   
    programData[7] = 0xA1;
    programData[8] = 0x12;  //0x208  
    programData[9] = 0x06;
    programData[10] = 0x60;  //0x20A  
    programData[11] = 0x13;
}
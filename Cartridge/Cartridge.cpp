#include "Cartridge.h"

Cartridge::Cartridge() 
{
    for (auto &i : programData)
        i = 0x00;
    programData[0] = 0xA0;  //0x200 
    programData[1] = 0x00;
    programData[2] = 0xD0;  //0x202 
    programData[3] = 0x05;
    programData[4] = 0x61;  //0x204
    programData[5] = 0x02;
    programData[6] = 0xD1;  //0x206   
    programData[7] = 0x15;
    programData[8] = 0xA0;  //0x208  
    programData[9] = 0x00;
    programData[10] = 0x12;  //0x20A  
    programData[11] = 0x00;
}
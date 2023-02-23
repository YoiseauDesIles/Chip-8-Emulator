#include "Cartridge.h"

Cartridge::Cartridge() 
{
    for (auto &i : programData)
        i = 0x00;
    programData[0] = 0x12;  //0x200
    programData[1] = 0x04;
    programData[2] = 0x00;  //0x202
    programData[3] = 0xEE;  
    programData[4] = 0x22;  //0x204
    programData[5] = 0x02;
    programData[6] = 0x12;  //0x206
    programData[7] = 0x00;
}
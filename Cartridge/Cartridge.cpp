#include "Cartridge.h"

Cartridge::Cartridge() 
{
    for (auto &i : programData)
        i = 0x00;
    programData[0] = 0x00;
    programData[1] = 0xE0;
    programData[2] = 0x01;
    programData[3] = 0x03;
}
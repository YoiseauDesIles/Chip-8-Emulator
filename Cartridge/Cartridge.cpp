#include "Cartridge.h"

Cartridge::Cartridge() 
{
    for (auto &i : programData)
        i = 0x00;
    programData[0] = 0x01;
    programData[1] = 0x02;
    programData[2] = 0x03;
}
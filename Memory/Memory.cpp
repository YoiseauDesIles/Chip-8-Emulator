#include "Memory.h"

Memory::Memory()
{
    for (auto &i : ram) 
        i = 0x00;
}

Memory::~Memory()
{

}

uint8_t Memory::read(uint16_t &address) const
{
    return ram[address];
}

void Memory::write(uint16_t const &address, uint8_t const &data) 
{
    ram[address] = data;
}

void Memory::copyCartridge()
{
    Cartridge cartridge;
    std::array<uint8_t, 4096>::iterator ramIterator = ram.begin();
    ramIterator+=0x200;

    for (auto &data : cartridge.programData)
    {
        *ramIterator = data;
        ramIterator++;
    }
    
}


 void Memory::printFullRam() const
 {
    for (auto &i : ram)
    {
        std::cout << i+0 << " ";
    }
 }

 void Memory::printRamRange(uint16_t const &from, uint16_t const &to) 
 {
    for (uint16_t address = from; address < to; address++) {
        std::cout << ram[address]+0 << " ";
    }
 }

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

    for (auto &data : cartridge.getProgramData())
    {
        *ramIterator = data;
        ramIterator++;
    }
    
}

void Memory::initCharacters()
{
    ram[0]=0xF0;ram[1]=0x90;ram[2]=0x90;ram[3]=0x90; ram[4]=0xF0;     // O  0x0000

    ram[5]=0x20;ram[6]=0x60;ram[7]=0x20;ram[8]=0x20;ram[9]=0x70;      // 1  0x0005

    ram[10]=0xF0;ram[11]=0x10;ram[12]=0xF0;ram[13]=0x80; ram[14]=0xF0;// 2  0x000A

    ram[15]=0xF0;ram[16]=0x10;ram[17]=0xF0;ram[18]=0x10;ram[19]=0xF0; // 3  0x000F

    ram[20]=0x90;ram[21]=0x90;ram[22]=0xF0;ram[23]=0x10;ram[24]=0x10; // 4  0x0014

    ram[25]=0xF0;ram[26]=0x80;ram[27]=0xF0;ram[28]=0x10;ram[29]=0xF0; // 5  0x0019

    ram[30]=0xF0;ram[31]=0x80;ram[32]=0xF0;ram[33]=0x90;ram[34]=0xF0; // 6  0x001E

    ram[35]=0xF0;ram[36]=0x10;ram[37]=0x20;ram[38]=0x40;ram[39]=0x40; // 7  0x0023

    ram[40]=0xF0;ram[41]=0x90;ram[42]=0xF0;ram[43]=0x90;ram[44]=0xF0; // 8  0x0028

    ram[45]=0xF0;ram[46]=0x90;ram[47]=0xF0;ram[48]=0x10;ram[49]=0xF0; // 9  0x002D

    ram[50]=0xF0;ram[51]=0x90;ram[52]=0xF0;ram[53]=0x90;ram[54]=0x90; // A  0x0032

    ram[55]=0xE0;ram[56]=0x90;ram[57]=0xE0;ram[58]=0x90;ram[59]=0xE0; // B  0x0037

    ram[60]=0xF0;ram[61]=0x80;ram[62]=0x80;ram[63]=0x80;ram[64]=0xF0; // C  0x003C

    ram[65]=0xE0;ram[66]=0x90;ram[67]=0x90;ram[68]=0x90;ram[69]=0xE0; // D  0x0041

    ram[70]=0xF0;ram[71]=0x80;ram[72]=0xF0;ram[73]=0x80;ram[74]=0xF0; // E  0x0046

    ram[75]=0xF0;ram[76]=0x80;ram[77]=0xF0;ram[78]=0x80;ram[79]=0x80; // F  0x004B
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

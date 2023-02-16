#include "OpCodeTable.h"

OpCodeTable::OpCodeTable()
{
    initMaskMap();
}

void OpCodeTable::initMaskMap()
{
    maskList[0]=std::make_pair(0x0000,0x0FFF);
    maskList[1]=std::make_pair(0xFFFF,0x00E0);
    maskList[2]=std::make_pair(0xFFFF,0x00EE);
    maskList[3]=std::make_pair(0xF000,0x1000);
    maskList[4]=std::make_pair(0xF000,0x2000);
    maskList[5]=std::make_pair(0xF000,0x3000);
    maskList[6]=std::make_pair(0xF000,0x4000);
    maskList[7]=std::make_pair(0xF00F,0x5000);
    maskList[8]=std::make_pair(0xF000,0x6000);
    maskList[9]=std::make_pair(0xF000,0x7000);
    maskList[10]=std::make_pair(0xF00F,0x8000);
    maskList[11]=std::make_pair(0xF00F,0x8001);
    maskList[12]=std::make_pair(0xF00F,0x8002);
    maskList[13]=std::make_pair(0xF00F,0x8003);
    maskList[14]=std::make_pair(0xF00F,0x8004);
    maskList[15]=std::make_pair(0xF00F,0x8005);
    maskList[16]=std::make_pair(0xF00F,0x8006);
    maskList[17]=std::make_pair(0xF00F,0x8007);
    maskList[18]=std::make_pair(0xF00F,0x800E);
    maskList[19]=std::make_pair(0xF00F,0x9000);
    maskList[20]=std::make_pair(0xF000,0xA000);
    maskList[21]=std::make_pair(0xF000,0xB000);
    maskList[22]=std::make_pair(0xF000,0xC000);
    maskList[23]=std::make_pair(0xF000,0xD000);
    maskList[24]=std::make_pair(0xF0FF,0xE09E);
    maskList[25]=std::make_pair(0xF0FF,0xE0A1);
    maskList[26]=std::make_pair(0xF0FF,0xF007);
    maskList[27]=std::make_pair(0xF0FF,0xF00A);
    maskList[28]=std::make_pair(0xF0FF,0xF015);
    maskList[29]=std::make_pair(0xF0FF,0xF018);
    maskList[30]=std::make_pair(0xF0FF,0xF01E);
    maskList[31]=std::make_pair(0xF0FF,0xF029);
    maskList[32]=std::make_pair(0xF0FF,0xF033);
    maskList[33]=std::make_pair(0xF0FF,0xF055);
    maskList[34]=std::make_pair(0xF0FF,0xF065);
}


EnumInstruction OpCodeTable::getInstruction(uint16_t opcode) const
{
    uint8_t index = 0;
    for (auto const &i : maskList){
        auto a = ((i.first & opcode));
        if (i.first & opcode == i.second)
            return EnumInstruction(index);
        index++;
    }
    
    return EnumInstruction::ERROR;
}
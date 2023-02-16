#include "CPU.h"

CPU::CPU()
{
    Memory memory = Memory();
    Registry registry = Registry();
    OpCodeTable opCodeTable = OpCodeTable();

    initMemory();

    //TODO Initialiser le tableau de pointeur d'instructions
}

CPU::~CPU()
{
    std::cout << "BYE BYE \n";
}

void CPU::initMemory()
{
    memory.copyCartridge();
}

void CPU::clock() const
{
    // Clock* clock = Clock::GetInstance();
    // uint8_t cycleState = clock->getCycleState();
    // clock->setCycleState(--cycleState);
}

uint16_t const CPU::getNextOpCode() 
{
    uint8_t opCodeMsb = memory.read(pc);
    pc++;
    uint8_t opCodeLsb = memory.read(pc);
    pc++;

    uint16_t opCode = addBytes(opCodeMsb, opCodeLsb);

    std::cout << "opcode: " << std::hex << opCode << "\n";
    return opCode;

}


uint16_t const CPU::addBytes(uint8_t const &msb, uint8_t const &lsb) const
{
    return byteShiftLeft(msb) + lsb;
}

uint16_t const CPU::byteShiftLeft(uint8_t const &data) const
{
    uint16_t res = data<<8;
    return res;
}

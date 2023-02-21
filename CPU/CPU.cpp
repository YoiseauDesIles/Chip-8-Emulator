#include "CPU.h"

CPU::CPU()
{
    memory = Memory();
    registry = Registry();
    opCodeTable = OpCodeTable();
    instructionProcessor = InstructionProcessor();

    initMemory();
    initInstructionSet();
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

void CPU::initInstructionSet()
{
      instructionSet =
          {
            &InstructionProcessor::test,// 0x46
            &InstructionProcessor::test,// 0x46
            &InstructionProcessor::test,// 0x46
            &InstructionProcessor::test,// 0x46
            &InstructionProcessor::test,// 0x46
            &InstructionProcessor::test,// 0x46
            &InstructionProcessor::test,// 0x46
            &InstructionProcessor::test,// 0x46
            &InstructionProcessor::test,// 0x46
            &InstructionProcessor::test,// 0x46
            &InstructionProcessor::test,// 0x46
            &InstructionProcessor::test,// 0x46
            &InstructionProcessor::test,// 0x46
            &InstructionProcessor::test,// 0x46
            &InstructionProcessor::test,// 0x46
            &InstructionProcessor::test,// 0x46
            &InstructionProcessor::test,// 0x46
            &InstructionProcessor::test,// 0x46
            &InstructionProcessor::test,// 0x46
            &InstructionProcessor::test,// 0x46
            &InstructionProcessor::test,// 0x46
            &InstructionProcessor::test,// 0x46
            &InstructionProcessor::test,// 0x46
            &InstructionProcessor::test,// 0x46
            &InstructionProcessor::test,// 0x46
            &InstructionProcessor::test,// 0x46
            &InstructionProcessor::test,// 0x46
            &InstructionProcessor::test,// 0x46
            &InstructionProcessor::test,// 0x46
            &InstructionProcessor::test,// 0x46
            &InstructionProcessor::test,// 0x46
            &InstructionProcessor::test,// 0x46
            &InstructionProcessor::test,// 0x46
            &InstructionProcessor::test,// 0x46
            &InstructionProcessor::test// 0x46
          };


}

void CPU::clock() const
{
    // Clock* clock = Clock::GetInstance();
    // uint8_t cycleState = clock->getCycleState();
    // clock->setCycleState(--cycleState);
}

uint16_t CPU::getNextOpCode() 
{
    uint8_t opCodeMsb = memory.read(pc);
    pc++;
    uint8_t opCodeLsb = memory.read(pc);
    pc++;

    uint16_t opCode = addBytes(opCodeMsb, opCodeLsb);

    // std::cout << "opcode : " << std::hex << opCode << "\n";

    EnumInstruction instruction = opCodeTable.getInstruction(opCode);

    // std::cout << "instruciton : " << instruction << "\n";
    return opCode;

}


uint16_t CPU::addBytes(uint8_t const &msb, uint8_t const &lsb) 
{
    return byteShiftLeft(msb) + lsb;
}

uint16_t CPU::byteShiftLeft(uint8_t const &data) 
{
    uint16_t res = data<<8;
    return res;
}

void CPU::processInstruction(uint16_t opcode, EnumInstruction instruction) 
{
    // *instructionSet[1] : fonction qui est dans instructionProcessor
    (instructionProcessor.*instructionSet[instruction])(opcode);

}

void CPU::process() 
{
    uint16_t opcode = getNextOpCode();

    EnumInstruction instruction = opCodeTable.getInstruction(opcode);  

    processInstruction(opcode, instruction);  

}
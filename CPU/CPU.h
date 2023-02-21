#pragma once

#include <iostream>
#include <stack>
#include "../Memory/Memory.h"
#include "../Registry/Registry.h"
#include "../OpCodeTable/OpCodeTable.h"
#include "../Clock/Clock.h"
#include "../InstructionProcessor/InstructionProcessor.h"

class CPU
{
    private:
        Memory memory;
        Registry registry;
        std::stack<uint16_t> stack; 
        uint16_t pc = 0x0200;
        OpCodeTable opCodeTable;
        // Déclaration du pointeur sur fonction (qui pointe vers une fonction de InstructionProcessor)
        typedef void (InstructionProcessor::*nomPtr)(uint16_t);
        std::array<nomPtr, 35> instructionSet;
        InstructionProcessor instructionProcessor;

        void initMemory();
        void initInstructionSet();
        void resetMemory();
        void clock() const;
        void processInstruction(uint16_t opCode, EnumInstruction instruction) ;
        uint16_t byteShiftLeft(uint8_t const &data) ;
        uint16_t addBytes(uint8_t const &msb, uint8_t const &lsb) ;
        uint16_t getNextOpCode();

    public:
        CPU();
        virtual ~CPU();

        void process() ;
};
#pragma once

#include <iostream>
#include <stack>
#include <windows.h>
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
        // typedef void (InstructionProcessor::*nomPtr)(uint16_t);
        typedef void (*Instruction)(CPU&, uint16_t);
        std::array<Instruction, 35> instructionSet;


        void initMemory();
        void initInstructionSet();
        void resetMemory();
        void clock(Clock & clock) const;
        void processInstruction(uint16_t opCode, EnumInstruction instruction) ;
        uint16_t byteShiftLeft(uint8_t const &data) ;
        uint16_t addBytes(uint8_t const &msb, uint8_t const &lsb) ;
        uint16_t getNextOpCode();
        

    public:
        CPU();
        virtual ~CPU();

        void process() ;

        std::stack<uint16_t> & getStack() { return stack; }
        uint16_t & getPc() { return pc; }
        Registry & getRegistry() { return registry; }
                
        void setPc(uint16_t pc) { this->pc = pc; }

        void printStackTop() { std::cout << "stack top " << stack.top() << "\n"; }

        Memory & getMemory() { return memory; }

        void handleClockCycles(Clock & clock);
        
};
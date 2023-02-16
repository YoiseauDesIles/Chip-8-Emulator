#pragma once

#include <iostream>
#include <stack>
#include "../Memory/Memory.h"
#include "../Registry/Registry.h"
#include "../OpCodeTable/OpCodeTable.h"
#include "../Clock/Clock.h"

class CPU
{
    private:
        Memory memory;
        Registry registry;
        std::stack<uint16_t> stack; 
        uint16_t pc = 0x0200;
        OpCodeTable opCodeTable;
        std::array<EnumInstruction, 35> instructions;
        void initMemory();
        void resetMemory();
        void clock() const;
        bool processInstruction();

    public:
        CPU();
        virtual ~CPU();
        uint16_t const byteShiftLeft(uint8_t const &data) const;
        uint16_t const addBytes(uint8_t const &msb, uint8_t const &lsb) const;
        uint16_t const getNextOpCode();
};
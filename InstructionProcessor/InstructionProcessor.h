#pragma once

#include <iostream>

class CPU;

#include "../CPU/CPU.h"

class InstructionProcessor 
{
    private:
        static uint8_t getHexChar(uint16_t opcode, uint8_t position);
        InstructionProcessor() {};
        //InstructionProcessor(CPU* cpu);
        virtual ~InstructionProcessor() = default;

    public:
        
        static void instr0NNN(CPU &cpu, uint16_t opcode);
        static void instr00E0(CPU &cpu, uint16_t opcode);
        static void instr00EE(CPU &cpu, uint16_t opcode);
        static void instr1NNN(CPU &cpu, uint16_t opcode);
        static void instr2NNN(CPU &cpu, uint16_t opcode);
        static void instr3XNN(CPU &cpu, uint16_t opcode);
        static void instr4XNN(CPU &cpu, uint16_t opcode);
        static void instr5XY0(CPU &cpu, uint16_t opcode);
        static void instr6XNN(CPU &cpu, uint16_t opcode);
        static void instr7XNN(CPU &cpu, uint16_t opcode);
        static void instr8XY0(CPU &cpu, uint16_t opcode);
        static void instr8XY1(CPU &cpu, uint16_t opcode);
        static void instr8XY2(CPU &cpu, uint16_t opcode);
        static void instr8XY3(CPU &cpu, uint16_t opcode);
        static void instr8XY4(CPU &cpu, uint16_t opcode);
        static void instr8XY5(CPU &cpu, uint16_t opcode);
        static void instr8XY6(CPU &cpu, uint16_t opcode);
        static void instr8XY7(CPU &cpu, uint16_t opcode);
        static void instr8XYE(CPU &cpu, uint16_t opcode);
        static void instr9XY0(CPU &cpu, uint16_t opcode);
        static void instrANNN(CPU &cpu, uint16_t opcode);
        static void instrBNNN(CPU &cpu, uint16_t opcode);
        static void instrCXNN(CPU &cpu, uint16_t opcode);
        static void instrDXYN(CPU &cpu, uint16_t opcode);
        static void instrEX9E(CPU &cpu, uint16_t opcode);
        static void instrEXA1(CPU &cpu, uint16_t opcode);
        static void instrFX07(CPU &cpu, uint16_t opcode);
        static void instrFX0A(CPU &cpu, uint16_t opcode);
        static void instrFX15(CPU &cpu, uint16_t opcode);
        static void instrFX18(CPU &cpu, uint16_t opcode);
        static void instrFX1E(CPU &cpu, uint16_t opcode);
        static void instrFX29(CPU &cpu, uint16_t opcode);
        static void instrFX33(CPU &cpu, uint16_t opcode);
        static void instrFX55(CPU &cpu, uint16_t opcode);
        static void instrFX65(CPU &cpu, uint16_t opcode);


}; 
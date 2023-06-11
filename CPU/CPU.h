#pragma once

#include <iostream>
#include <stack>
#include <windows.h>
#include "../Memory/Memory.h"
#include "../Registry/Registry.h"
#include "../OpCodeTable/OpCodeTable.h"
#include "../Clock/Clock.h"
#include "../InstructionProcessor/InstructionProcessor.h"
#include "../Controller/Controller.h"
#include "../Pixel/Pixel.h"


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
        std::array<uint8_t, 16> keys;
        std::array<std::array<Pixel, 64>, 32> pixelArray;
        Controller controller;

        uint8_t continueGame = 1;

        void initMemory();
        void initInstructionSet();
        void resetMemory();
        //void clock(Clock & clock) const;
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

        std::array<uint8_t, 16> getKeys() const { return keys; }

        void setContinueGame(uint8_t continueGame) { continueGame = continueGame; }
        uint8_t getContinueGame() { return continueGame; }
        //void handleClockCycles(Clock & clock);

        void updateKeys();

        uint8_t waitForKeys(uint8_t XRegistry);

        std::array<std::array<Pixel, 64>, 32> getPixelArray() { return pixelArray; }
        void setPixelColor(uint8_t y, uint8_t x, uint8_t color); 

        void resetPixelArray();

        void printPixelArray();
        
};
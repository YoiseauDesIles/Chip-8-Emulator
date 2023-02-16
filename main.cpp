#include <iostream>
#include "CPU/CPU.h"

int main()
{

    CPU cpu = CPU();
    cpu.getNextOpCode();
    // Memory m = Memory();
    // m.copyCartridge();
    // m.printRamRange(0x200, 0x203);
    
    return 0;
    
}
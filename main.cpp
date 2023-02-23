#include <iostream>
#include "CPU/CPU.h"

enum enumTest {a = 0, b = 1};
int main()
{

    CPU cpu = CPU();
    cpu.process();
    cpu.process();
    cpu.process();
    cpu.process();
    cpu.process();

    // Memory m = Memory();
    // m.copyCartridge();
    // m.printRamRange(0x200, 0x203);
    
    return 0;
    
}
#include <iostream>
#include "CPU/CPU.h"

enum enumTest {a = 0, b = 1};
int main()
{

    CPU cpu = CPU();
    cpu.getNextOpCode();
    // Memory m = Memory();
    // m.copyCartridge();
    // m.printRamRange(0x200, 0x203);
    
    enumTest test = (enumTest)0;
    std::cout << test << "\n";
    return 0;
    
}
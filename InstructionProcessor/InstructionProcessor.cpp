#include "InstructionProcessor.h"

 
 uint8_t InstructionProcessor::getHexChar(uint16_t opcode, uint8_t position)
 {
   uint8_t hexChar = (opcode >> position*4) & 0x000F; 

   std::cout << "getHexChar - hexChar : " << std::hex << hexChar+0 << "\n";

   return hexChar;
 }


void InstructionProcessor::instr0NNN(CPU &cpu, uint16_t opcode) 
{
   // Non utilise
}

void InstructionProcessor::instr00E0(CPU &cpu, uint16_t opcode) 
{
   // Effacer l'écran
   // TODO : graphique
}

void InstructionProcessor::instr00EE(CPU &cpu, uint16_t opcode) 
{
   std::cout << "Instuction 00EE" << "\n";
   // Retour à partir d'un sous-fonction
   
   auto stack = cpu.getStack();
   uint16_t address = stack.top();
   stack.pop();

   cpu.setPc(address);

   std::cout << "Fin instruction 00EE - Adresse : " << std::hex << address << "\n";
   
}

void InstructionProcessor::instr1NNN(CPU &cpu, uint16_t opcode) 
{
   uint8_t N0 = getHexChar(opcode, 0);
   uint8_t N1 = getHexChar(opcode, 1);
   uint8_t N2 = getHexChar(opcode, 2);

   uint16_t address = (N2 << 8) + (N1 << 4) + N0;
   
   std::cout << "Instruction 1NNN - address = " << std::hex << address+0 << "\n";

   cpu.setPc(address);
}

void InstructionProcessor::instr2NNN(CPU &cpu, uint16_t opcode) 
{
   auto &stack = cpu.getStack();
   stack.emplace(cpu.getPc());

   cpu.printStackTop();

   std::cout << "Instruction 2NNN - stack top = " << std::hex << stack.top()+0 << "\n";

   uint8_t N0 = getHexChar(opcode, 0);
   uint8_t N1 = getHexChar(opcode, 1);
   uint8_t N2 = getHexChar(opcode, 2);

   uint16_t address = (N2 << 8) + (N1 << 4) + N0;
   
   std::cout << "Instruction 2NNN - address = " << std::hex << address+0 << "\n";

   cpu.setPc(address);
}

void InstructionProcessor::instr3XNN(CPU &cpu, uint16_t opcode) 
{

}

void InstructionProcessor::instr4XNN(CPU &cpu, uint16_t opcode) 
{

}

void InstructionProcessor::instr5XY0(CPU &cpu, uint16_t opcode) 
{

}

void InstructionProcessor::instr6XNN(CPU &cpu, uint16_t opcode) 
{

}

void InstructionProcessor::instr7XNN(CPU &cpu, uint16_t opcode) 
{

}

void InstructionProcessor::instr8XY0(CPU &cpu, uint16_t opcode) 
{

}

void InstructionProcessor::instr8XY1(CPU &cpu, uint16_t opcode) 
{

}

void InstructionProcessor::instr8XY2(CPU &cpu, uint16_t opcode) 
{

}

void InstructionProcessor::instr8XY3(CPU &cpu, uint16_t opcode) 
{

}

void InstructionProcessor::instr8XY4(CPU &cpu, uint16_t opcode) 
{

}

void InstructionProcessor::instr8XY5(CPU &cpu, uint16_t opcode) 
{

}

void InstructionProcessor::instr8XY6(CPU &cpu, uint16_t opcode) 
{

}

void InstructionProcessor::instr8XY7(CPU &cpu, uint16_t opcode) 
{

}

void InstructionProcessor::instr8XYE(CPU &cpu, uint16_t opcode) 
{

}

void InstructionProcessor::instr9XY0(CPU &cpu, uint16_t opcode) 
{

}

void InstructionProcessor::instrANNN(CPU &cpu, uint16_t opcode) 
{

}

void InstructionProcessor::instrBNNN(CPU &cpu, uint16_t opcode) 
{

}

void InstructionProcessor::instrCXNN(CPU &cpu, uint16_t opcode) 
{

}

void InstructionProcessor::instrDXYN(CPU &cpu, uint16_t opcode) 
{

}

void InstructionProcessor::instrEX9E(CPU &cpu, uint16_t opcode) 
{

}

void InstructionProcessor::instrEXA1(CPU &cpu, uint16_t opcode) 
{

}

void InstructionProcessor::instrFX07(CPU &cpu, uint16_t opcode) 
{

}

void InstructionProcessor::instrFX0A(CPU &cpu, uint16_t opcode) 
{

}

void InstructionProcessor::instrFX15(CPU &cpu, uint16_t opcode) 
{

}

void InstructionProcessor::instrFX18(CPU &cpu, uint16_t opcode) 
{

}

void InstructionProcessor::instrFX1E(CPU &cpu, uint16_t opcode) 
{

}

void InstructionProcessor::instrFX29(CPU &cpu, uint16_t opcode) 
{

}

void InstructionProcessor::instrFX33(CPU &cpu, uint16_t opcode) 
{

}

void InstructionProcessor::instrFX55(CPU &cpu, uint16_t opcode) 
{

}

void InstructionProcessor::instrFX65(CPU &cpu, uint16_t opcode) 
{

}

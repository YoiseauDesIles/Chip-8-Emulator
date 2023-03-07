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
   // Saut à l'adresse NNN

   uint8_t N0 = getHexChar(opcode, 0);
   uint8_t N1 = getHexChar(opcode, 1);
   uint8_t N2 = getHexChar(opcode, 2);

   uint16_t address = (N2 << 8) + (N1 << 4) + N0;
   
   std::cout << "Instruction 1NNN - address = " << std::hex << address+0 << "\n";

   cpu.setPc(address);
}

void InstructionProcessor::instr2NNN(CPU &cpu, uint16_t opcode) 
{

   // Exécute le sous-programme à l'adresse NNN

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

   // Saute l'instruction suivante si VX = NN

   std::cout << "Instruction 3XNN" << "\n";

   uint8_t N0 = getHexChar(opcode, 0);
   uint8_t N1 = getHexChar(opcode, 1);
   uint8_t X = getHexChar(opcode, 2);

   if (cpu.getRegistry().getRegistry(X) == ((N1 << 4) + N0))
      cpu.setPc(cpu.getPc()+2);

   std::cout << "Instruction 3XNN - pc apres traitement = " << std::hex << cpu.getPc()+0 << "\n";

}

void InstructionProcessor::instr4XNN(CPU &cpu, uint16_t opcode) 
{

   // Saute l'instruction suivante si VX != NN

   std::cout << "Instruction 4XNN" << "\n";

   uint8_t N0 = getHexChar(opcode, 0);
   uint8_t N1 = getHexChar(opcode, 1);
   uint8_t X = getHexChar(opcode, 2);

   if (cpu.getRegistry().getRegistry(X) != ((N1 << 4) + N0))
      cpu.setPc(cpu.getPc()+2);

   std::cout << "Instruction 4XNN - pc apres traitement = " << std::hex << cpu.getPc()+0 << "\n";

}

void InstructionProcessor::instr5XY0(CPU &cpu, uint16_t opcode) 
{

   // Saute l'instruction suivante si VX = VY

   std::cout << "Instruction 5XY0" << "\n";

   uint8_t X = getHexChar(opcode, 2);
   uint8_t Y = getHexChar(opcode, 1);

   if (cpu.getRegistry().getRegistry(X) == cpu.getRegistry().getRegistry(Y))
      cpu.setPc(cpu.getPc()+2);

   std::cout << "Instruction 5XY0 - pc apres traitement = " << std::hex << cpu.getPc()+0 << "\n";
}

void InstructionProcessor::instr6XNN(CPU &cpu, uint16_t opcode) 
{
   // Definit VX a NN

   std::cout << "Instruction 6XNN" << "\n";

   uint8_t N0 = getHexChar(opcode, 0);
   uint8_t N1 = getHexChar(opcode, 1);
   uint8_t X = getHexChar(opcode, 2);

   cpu.getRegistry().setRegistry(X, (N1 << 4) + N0);

   std::cout << "Instruction 6XNN - valeur du registre " << std::hex << X+0 << " : " << std::hex << cpu.getRegistry().getRegistry(X)+0 << "\n";

}

void InstructionProcessor::instr7XNN(CPU &cpu, uint16_t opcode) 
{
   // Ajoute NN à VX

   std::cout << "Instruction 7XNN" << "\n";

   uint8_t N0 = getHexChar(opcode, 0);
   uint8_t N1 = getHexChar(opcode, 1);
   uint8_t X = getHexChar(opcode, 2);

   uint8_t currRegistry = cpu.getRegistry().getRegistry(X);
   cpu.getRegistry().setRegistry(X,  currRegistry + (N1 << 4) + N0);

   std::cout << "Instruction 7XNN - valeur du registre " << std::hex << X+0 << " : " << std::hex << cpu.getRegistry().getRegistry(X)+0 << "\n";

}

void InstructionProcessor::instr8XY0(CPU &cpu, uint16_t opcode) 
{

   // Définit VX à la valeur de VY

   std::cout << "Instruction 8XY0" << "\n";
   
   uint8_t X = getHexChar(opcode, 2);
   uint8_t Y = getHexChar(opcode, 1);

   uint8_t currRegistry = cpu.getRegistry().getRegistry(Y);
   cpu.getRegistry().setRegistry(X,  currRegistry);

   std::cout << "Instruction 8XY0 - valeur du registre " << std::hex << X+0 << " : " << std::hex << cpu.getRegistry().getRegistry(X)+0 << "\n";


}

void InstructionProcessor::instr8XY1(CPU &cpu, uint16_t opcode) 
{

   // Définit VX à la valeur de VX OR VY

   std::cout << "Instruction 8XY1" << "\n";
   
   uint8_t X = getHexChar(opcode, 2);
   uint8_t Y = getHexChar(opcode, 1);

   uint8_t currRegistryX = cpu.getRegistry().getRegistry(X);
   uint8_t currRegistryY = cpu.getRegistry().getRegistry(Y);
   cpu.getRegistry().setRegistry(X,  currRegistryX | currRegistryY);

   std::cout << "Instruction 8XY1 - valeur du registre " << std::hex << X+0 << " : " << std::hex << cpu.getRegistry().getRegistry(X)+0 << "\n";

}

void InstructionProcessor::instr8XY2(CPU &cpu, uint16_t opcode) 
{
   // Definit VX a VX AND VY

   std::cout << "Instruction 8XY2" << "\n";

   uint8_t Y = getHexChar(opcode, 1);
   uint8_t X = getHexChar(opcode, 2);

   uint8_t currRegistryX = cpu.getRegistry().getRegistry(X);
   uint8_t currRegistryY = cpu.getRegistry().getRegistry(Y);
   
   cpu.getRegistry().setRegistry(X, currRegistryX & currRegistryY );

   std::cout << "Instruction 8XY2 - valeur du registre " << std::hex << X+0 << " : " << std::hex << cpu.getRegistry().getRegistry(X)+0 << "\n";
}

void InstructionProcessor::instr8XY3(CPU &cpu, uint16_t opcode) 
{
   // Definit VX a VX XOR VY

   std::cout << "Instruction 8XY3" << "\n";

   uint8_t Y = getHexChar(opcode, 1);
   uint8_t X = getHexChar(opcode, 2);

   uint8_t currRegistryX = cpu.getRegistry().getRegistry(X);
   uint8_t currRegistryY = cpu.getRegistry().getRegistry(Y);
   
   cpu.getRegistry().setRegistry(X, currRegistryX ^ currRegistryY );

   std::cout << "Instruction 8XY3 - valeur du registre " << std::hex << X+0 << " : " << std::hex << cpu.getRegistry().getRegistry(X)+0 << "\n";
}

void InstructionProcessor::instr8XY4(CPU &cpu, uint16_t opcode) 
{
   // Ajoute VY à VX. VF est mis à 1 quand il y a un dépassement de mémoire (carry), à 0 quand il n'y en a pas.

   std::cout << "Instruction 8XY4" << "\n";

   uint8_t Y = getHexChar(opcode, 1);
   uint8_t X = getHexChar(opcode, 2);

   uint8_t currRegistryX = cpu.getRegistry().getRegistry(X);
   uint8_t currRegistryY = cpu.getRegistry().getRegistry(Y);

   uint16_t sum = currRegistryX + currRegistryY;

   // S'il y a un depassement de memoire, mise a 1 du registe F, sinon 0
   cpu.getRegistry().setRegistry(0xF, sum > 0xFF ? 1 : 0);

   cpu.getRegistry().setRegistry(X, sum & 0x00FF);

   std::cout << "Instruction 8XY4 - valeur du registre " << std::hex << X+0 << " : " << std::hex << cpu.getRegistry().getRegistry(X)+0 << "\n";
   std::cout << "Instruction 8XY4 - valeur du registre F : " << std::hex << cpu.getRegistry().getRegistry(0xF)+0 << "\n";

}

void InstructionProcessor::instr8XY5(CPU &cpu, uint16_t opcode) 
{
   // VY est soustrait de VX. VF est mis à 0 quand il y a un emprunt et à 1 quand il n'y en a pas.

   std::cout << "Instruction 8XY5" << "\n";

   uint8_t Y = getHexChar(opcode, 1);
   uint8_t X = getHexChar(opcode, 2);

   uint8_t currRegistryX = cpu.getRegistry().getRegistry(X);
   uint8_t currRegistryY = cpu.getRegistry().getRegistry(Y);

   uint8_t diff = currRegistryX - currRegistryY;

   // S'il y a un underflow, mise a 1 du registe F, sinon 0
   cpu.getRegistry().setRegistry(0xF, currRegistryY > currRegistryX ? 1 : 0);

   cpu.getRegistry().setRegistry(X, diff);

   std::cout << "Instruction 8XY5 - valeur du registre " << std::hex << X+0 << " : " << std::hex << cpu.getRegistry().getRegistry(X)+0 << "\n";
   std::cout << "Instruction 8XY5 - valeur du registre F : " << std::hex << cpu.getRegistry().getRegistry(0xF)+0 << "\n";

}

void InstructionProcessor::instr8XY6(CPU &cpu, uint16_t opcode) 
{
   // Décale (shift) VX à droite de 1 bit. VF est fixé à la valeur du bit de poids faible de VX avant le décalage.

   std::cout << "Instruction 8XY6" << "\n";

   uint8_t X = getHexChar(opcode, 2);

   uint8_t currRegistryX = cpu.getRegistry().getRegistry(X);

   cpu.getRegistry().setRegistry(0xF, currRegistryX & 0x01);

   cpu.getRegistry().setRegistry(X, currRegistryX >> 1);

   std::cout << "Instruction 8XY6 - valeur du registre " << std::hex << X+0 << " : " << std::hex << cpu.getRegistry().getRegistry(X)+0 << "\n";
   std::cout << "Instruction 8XY6 - valeur du registre F : " << std::hex << cpu.getRegistry().getRegistry(0xF)+0 << "\n";

}

void InstructionProcessor::instr8XY7(CPU &cpu, uint16_t opcode) 
{
   // VX = VY - VX, VF est mis à 0 quand il y a un emprunt, et à 1 quand il n'y en a pas.

   std::cout << "Instruction 8XY" << "\n";

   uint8_t Y = getHexChar(opcode, 1);
   uint8_t X = getHexChar(opcode, 2);

   uint8_t currRegistryX = cpu.getRegistry().getRegistry(X);
   uint8_t currRegistryY = cpu.getRegistry().getRegistry(Y);

   uint8_t diff = currRegistryY - currRegistryX;

   // S'il y a un underflow, mise a 1 du registe F, sinon 0
   cpu.getRegistry().setRegistry(0xF, currRegistryX > currRegistryY ? 1 : 0);

   cpu.getRegistry().setRegistry(X, diff);

   std::cout << "Instruction 8XY7 - valeur du registre " << std::hex << X+0 << " : " << std::hex << cpu.getRegistry().getRegistry(X)+0 << "\n";
   std::cout << "Instruction 8XY7 - valeur du registre F : " << std::hex << cpu.getRegistry().getRegistry(0xF)+0 << "\n";
}

void InstructionProcessor::instr8XYE(CPU &cpu, uint16_t opcode) 
{
   // Décale (shift) VX à gauche de 1 bit. VF est fixé à la valeur du bit de poids fort de VX avant le décalage.

   std::cout << "Instruction 8XYE" << "\n";

   uint8_t X = getHexChar(opcode, 2);

   uint8_t currRegistryX = cpu.getRegistry().getRegistry(X);

   cpu.getRegistry().setRegistry(0xF, currRegistryX >> 7);

   cpu.getRegistry().setRegistry(X, currRegistryX << 1);

   std::cout << "Instruction 8XYE - valeur du registre " << std::hex << X+0 << " : " << std::hex << cpu.getRegistry().getRegistry(X)+0 << "\n";
   std::cout << "Instruction 8XYE - valeur du registre F : " << std::hex << cpu.getRegistry().getRegistry(0xF)+0 << "\n";
}

void InstructionProcessor::instr9XY0(CPU &cpu, uint16_t opcode) 
{
   
   // Saute l'instruction suivante si VX != VY

   std::cout << "Instruction 9XY0" << "\n";

   uint8_t X = getHexChar(opcode, 2);
   uint8_t Y = getHexChar(opcode, 1);

   if (cpu.getRegistry().getRegistry(X) != cpu.getRegistry().getRegistry(Y))
      cpu.setPc(cpu.getPc()+2);
      
   std::cout << "Instruction 9XY0 - pc apres traitement = " << std::hex << cpu.getPc()+0 << "\n";
}

void InstructionProcessor::instrANNN(CPU &cpu, uint16_t opcode) 
{

   // Affecte NNN à I

   std::cout << "Instruction ANNN " << "\n";

   uint8_t N0 = getHexChar(opcode, 0);
   uint8_t N1 = getHexChar(opcode, 1);
   uint8_t N2 = getHexChar(opcode, 2);

   uint16_t address = (N2 << 8) + (N1 << 4) + N0;

   cpu.getRegistry().setI(address);
   
   std::cout << "Instruction ANNN - Registre I = " << std::hex << cpu.getRegistry().getI()+0 << "\n";

}

void InstructionProcessor::instrBNNN(CPU &cpu, uint16_t opcode) 
{
   // Passe à l'adresse NNN + V0.

   std::cout << "Instruction BNNN " << "\n";
   
   uint8_t N0 = getHexChar(opcode, 0);
   uint8_t N1 = getHexChar(opcode, 1);
   uint8_t N2 = getHexChar(opcode, 2);

   uint16_t address = (N2 << 8) + (N1 << 4) + N0;
   cpu.setPc(address + cpu.getRegistry().getRegistry(0));
   
   std::cout << "Instruction BNNN - PC = " << std::hex << cpu.getPc()+0 << "\n";
}

void InstructionProcessor::instrCXNN(CPU &cpu, uint16_t opcode) 
{
   // Définit VX à un nombre aléatoire inférieur à NN

   std::cout << "Instruction CXNN " << "\n";
   
   uint8_t N0 = getHexChar(opcode, 0);
   uint8_t N1 = getHexChar(opcode, 1);
   uint8_t X = getHexChar(opcode, 2);

   uint8_t NN = (N1 << 4) + N0;

   // Initialisation de la seed de rand
   std::srand (time(NULL));

   uint8_t randNumber = std::rand() % NN;

   cpu.getRegistry().setRegistry(X, randNumber);

   std::cout << "Instruction CXNN - valeur du registre " << std::hex << X+0 << " : " << std::hex << cpu.getRegistry().getRegistry(X)+0 << "\n";
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
   // Ajoute VX à I. VF est mis à 1 quand il y a overflow (I+VX>0xFFF), et à 0 si ce n'est pas le cas.

   std::cout << "Instruction FX1E " << "\n";

   uint8_t X = getHexChar(opcode, 2);

   uint8_t currRegistryX = cpu.getRegistry().getRegistry(X);
   uint16_t currRegistryI = cpu.getRegistry().getI();

   uint32_t sum = currRegistryI + currRegistryX;

   cpu.getRegistry().setI(currRegistryI + currRegistryX);

   // S'il y a un depassement de memoire, mise a 1 du registe F, sinon 0
   cpu.getRegistry().setRegistry(0xF, sum > 0xFFFF ? 1 : 0);

   std::cout << "Instruction FX1E - valeur du registre I : " << std::hex << cpu.getRegistry().getI()+0 << "\n";
   std::cout << "Instruction FX1E - valeur du registre F : " << std::hex << cpu.getRegistry().getRegistry(0xF)+0 << "\n";
}

void InstructionProcessor::instrFX29(CPU &cpu, uint16_t opcode) 
{

}

void InstructionProcessor::instrFX33(CPU &cpu, uint16_t opcode) 
{
   // Stocke dans la mémoire le code décimal représentant VX (I, I+1, I+2)

   std::cout << "Instruction FX33 " << "\n";

   uint8_t X = getHexChar(opcode, 2);

   uint8_t number = cpu.getRegistry().getRegistry(X);

   uint8_t hundreds = number / 100;
   uint8_t tens = (number % 100) / 10;
   uint8_t units = (number % 100) % 10;

   uint16_t I = cpu.getRegistry().getI();

   cpu.getMemory().write(I, hundreds);
   cpu.getMemory().write(I+1, tens);
   cpu.getMemory().write(I+2, units);

   uint16_t I1 = I+1;
   uint16_t I2 = I+2;
   std::cout << "Instruction FX55 - mémoire à l'adresse I à I+2 (I = " << std::hex << I+0 << ") : " << 
   std::hex << cpu.getMemory().read(I)+0 << 
   std::hex << cpu.getMemory().read(I1)+0 << 
   std::hex << cpu.getMemory().read(I2)+0 << "\n";
} 

void InstructionProcessor::instrFX55(CPU &cpu, uint16_t opcode) 
{
   // Stocke V0 à VX en mémoire à partir de l'adresse I.

   std::cout << "Instruction FX55 " << "\n";

   uint8_t X = getHexChar(opcode, 2);
   uint16_t iRegistry = cpu.getRegistry().getI();
   
   for (uint16_t i=0; i<=X; i++) 
   {
      uint8_t currRegistry = cpu.getRegistry().getRegistry(i);
      uint16_t iAddress = iRegistry + i;
      cpu.getMemory().write(iAddress, currRegistry);

      std::cout << "Instruction FX55 - mémoire à l'adresse " << std::hex << iAddress+0 << " : " << std::hex << cpu.getMemory().read(iAddress)+0 << "\n";
   }


}

void InstructionProcessor::instrFX65(CPU &cpu, uint16_t opcode) 
{
   // Remplit V0 à VX avec les valeurs de la mémoire à partir de l'adresse I.

   std::cout << "Instruction FX65 " << "\n";

   uint8_t X = getHexChar(opcode, 2);
   uint16_t iRegistry = cpu.getRegistry().getI();
   
   for (uint16_t i=0; i<=X; i++) 
   {
      uint16_t iAddress = iRegistry + i;
      uint8_t data = cpu.getMemory().read(iAddress);
      cpu.getRegistry().setRegistry(i, data);
      
      std::cout << "Instruction FX65 - valeur du registre " << std::hex << i+0 << " : " << std::hex << cpu.getRegistry().getRegistry(i)+0 << "\n";
   }

}

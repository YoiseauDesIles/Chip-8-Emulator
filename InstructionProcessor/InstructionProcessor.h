#include <iostream>

class InstructionProcessor 
{
    public:
        InstructionProcessor();
        virtual ~InstructionProcessor() = default;

        void test(uint16_t opcode);


}; 
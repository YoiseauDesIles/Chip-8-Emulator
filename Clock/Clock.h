#include <iostream>

class Clock 
{
    public :
        Clock();
        virtual ~Clock() = default;

        void decreaseCycle();
        uint8_t getCycle() { return currentCycle; }
        void setCycle(uint8_t cycle) { currentCycle = cycle; }   

    private :
        uint8_t currentCycle;
};
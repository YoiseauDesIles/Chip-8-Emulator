#include "Clock.h"


Clock::Clock()
{
    currentCycle = 250; // 250 Hz
}

void Clock::decreaseCycle() 
{
    currentCycle--;
}  
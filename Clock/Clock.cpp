#include "Clock.h"


Clock* Clock::clock= nullptr;;

/**
 * Static methods should be defined outside the class.
 */
Clock * Clock::GetInstance()
{
    /**
     * This is a safer way to create an instance. instance = new Singleton is
     * dangeruous in case two instance threads wants to access at the same time
     */
    if(clock==nullptr)
    {
        clock = new Clock();
    }
    return clock;
}


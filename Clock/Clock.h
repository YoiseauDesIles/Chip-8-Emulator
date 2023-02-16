#pragma once
#include <iostream>

class Clock 
{
    protected:

        static uint8_t cycleState;
        static Clock* clock;

        Clock() { cycleState = 0; }

    public:

        /**
        * Singletons should not be cloneable.
        */
        Clock(Clock &other) = delete;
        /**
        * Singletons should not be assignable.
        */
        void operator=(const Clock &) = delete;
        /**
        * This is the static method that controls the access to the singleton
        * instance. On the first run, it creates a singleton object and places it
        * into the static field. On subsequent runs, it returns the client existing
        * object stored in the static field.
        */

        static Clock *GetInstance();
        /**
        * Finally, any singleton should define some business logic, which can be
        * executed on its instance.
        */

        static uint8_t getCycleState() { return cycleState; }
        static void setCycleState(uint8_t cycleState) { cycleState = cycleState; }

};
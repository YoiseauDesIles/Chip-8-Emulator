#pragma once
#include <iostream>
#include <windows.h>

#include "../CPU/CPU.h"
#include "../Controller/Controller.h"


class GameScheduler
{
    private:
        uint8_t continueGame;
        uint8_t gameScreenCnt;
        CPU& cpu;
        // GameScreen& gameScreen;
        // GameSound& gameSound;

    public:
        GameScheduler(CPU& cpu);
        virtual ~GameScheduler() = default;

        void startGame();
};
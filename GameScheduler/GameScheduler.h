#pragma once
#include <iostream>
#include <windows.h>

#include "../CPU/CPU.h"
#include "../Controller/Controller.h"
#include "../GameScreen/GameScreen.h"



class GameScheduler
{
    private:
        uint8_t continueGame;
        uint8_t gameScreenCnt;
        CPU& cpu;
        GameScreen& gameScreen;
        // GameSound& gameSound;

    public:
        GameScheduler(CPU& cpu, GameScreen& gameScreen);
        virtual ~GameScheduler() = default;

        void startGame();

};
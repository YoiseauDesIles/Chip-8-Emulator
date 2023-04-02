#include "GameScheduler.h"

GameScheduler::GameScheduler(CPU& cpu, Controller &controller) : cpu(cpu), controller(controller), gameScreenCnt(0), continueGame(1)
{
    std::cout << "game scheduler initialized" << "\n";
}

void GameScheduler::startGame()
{
    do 
    {
        //cpu.process();
        gameScreenCnt++;

        if (gameScreenCnt == 4)
        {
            cpu.updateKeys(controller);
            //gameScreen.update();
            
            gameScreenCnt = 0;
        }

        //continueGame = cpu.getKey() == QUIT;
        Sleep(4);

    } while (continueGame);

}

#include "GameScheduler.h"

GameScheduler::GameScheduler(CPU& cpu, GameScreen& gameScreen) : cpu(cpu), gameScreen(gameScreen), gameScreenCnt(0), continueGame(1)
{
    std::cout << "game scheduler initialized" << "\n";
}

void GameScheduler::startGame()
{
    try 
    {
        
        do 
            {
                cpu.process();
                gameScreenCnt++;

                if (gameScreenCnt == 4)
                {
                    std::cout << "Avant updateKeys : " << cpu.getContinueGame()+0 << "\n";
                    cpu.updateKeys();
                    std::cout << "Apres updateKays : " << cpu.getContinueGame()+0 << "\n";
                    gameScreen.updateScreen(cpu.getPixelArray());
                    
                    gameScreenCnt = 0;
                }

                //continueGame = cpu.getKey() == QUIT;
                Sleep(4);
                std::cout << "continue game : " << cpu.getContinueGame()+0 << "\n";
        } while (cpu.getContinueGame() == 1);

    } catch (const std::exception &e)
    {
        std::cout << e.what() << "\n";
    }
    

}

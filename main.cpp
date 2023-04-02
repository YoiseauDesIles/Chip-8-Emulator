
#include <iostream>
#include "CPU/CPU.h"
#include "GameScheduler/GameScheduler.h"
#include "Controller/Controller.h"
#include <SDL.h>

enum enumTest {a = 0, b = 1};

int main(int argc, char **argv){


    //          /* Initialisation simple */
    if (SDL_Init(SDL_INIT_VIDEO) != 0 )
    {
        std::cout << "Échec de l'initialisation de la SDL";
        return -1;
    }

        // /* Création de la fenêtre */
        SDL_Window* pWindow = NULL;
        pWindow = SDL_CreateWindow("Ma première application SDL2",SDL_WINDOWPOS_UNDEFINED,
                                                                  SDL_WINDOWPOS_UNDEFINED,
                                                                  640,
                                                                  480,
                                                                  SDL_WINDOW_SHOWN);
        CPU cpu = CPU();
        Controller controller = Controller();
        GameScheduler gameScheduler = GameScheduler(cpu, controller);
        gameScheduler.startGame();

        // if( pWindow )
        // {
        //     SDL_Delay(3000); /* Attendre trois secondes, que l'utilisateur voie la fenêtre */

        //     SDL_DestroyWindow(pWindow);
        // }
        // else
        // {
        //     std::cout << "Erreur de création de la fenêtre:";
        // }
    

   
    
   
 
    // Clock clock = Clock();
    // for (int i  = 0; i < 10; i++){
    //     cpu.handleClockCycles(clock);
    // }

    

    // Memory m = Memory();
    // m.copyCartridge();
    // m.printRamRange(0x200, 0x203);
    
    SDL_Quit();
    return 0;
}


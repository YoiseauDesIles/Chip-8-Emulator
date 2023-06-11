
#include <iostream>
#include "CPU/CPU.h"
#include "GameScheduler/GameScheduler.h"
#include "GameScreen/GameScreen.h"
#include "Controller/Controller.h"
#include "Utils/Constants.h"
#include <SDL.h>
#include <cmath>

enum enumTest {a = 0, b = 1};

int main(int argc, char **argv){


        GameScreen gameScreen = GameScreen();
        std::cout << "a";
        gameScreen.initialiseSDL(64, 32);
        std::cout << "b";
        // g.initialiseScreen();
        std::cout << "c";

        CPU cpu = CPU();
        GameScheduler gameScheduler = GameScheduler(cpu, gameScreen);
        gameScheduler.startGame();



    // if(ecran==NULL) 
    // { 
    //     fprintf(stderr,"Erreur lors du chargement du mode vidéo %s",SDL_GetError()); 
    //     exit(EXIT_FAILURE); 
    // } 


    // carre[0]=SDL_CreateRGBSurface(SDL_HWSURFACE,DIMPIXEL,DIMPIXEL,32,0,0,0,0); //le pixel noir 

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



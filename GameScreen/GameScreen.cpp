#include "GameScreen.h"

GameScreen::GameScreen()
{


}

uint8_t GameScreen::initialiseScreen(uint16_t width, uint16_t height)
{

    if (SDL_Init(SDL_INIT_VIDEO) != 0 )
    {
        std::cout << "Échec de l'initialisation de la SDL";
        return -1;
    }

    if (SDL_CreateWindowAndRenderer(512, 256, SDL_WINDOW_SHOWN, &pWindow, &pRenderer) < 0)     
    {         
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "[DEBUG] > %s", SDL_GetError());         
        SDL_Quit();         
        return EXIT_FAILURE;     
    }           
    
    SDL_SetWindowTitle(pWindow, "CHIP 8");     
    resetScreen();

    return 0;
}


uint8_t GameScreen::updateScreen(std::array<std::array<Pixel, 64>, 32> pixelArray )
{
    std::cout<< "updateScreen" << "\n";

    for (int height = 0; height < 32; height++){
        for (int width = 0; width < 64; width++)
        {
                   
            SDL_SetRenderDrawColor(pRenderer, 255*pixelArray[height][width].getColor(), 255*pixelArray[height][width].getColor(), 255*pixelArray[height][width].getColor(), 255);  
            SDL_Rect rect{width*8, height*8, 8, 8};
            SDL_RenderFillRect(pRenderer, &rect);

        }
    }
    SDL_RenderPresent(pRenderer);

}

uint8_t GameScreen::resetScreen() 
{
    std::cout << "resetScreen" << "\n";
    SDL_SetRenderDrawColor(pRenderer, 0, 0, 0, 255);    
    SDL_RenderClear(pRenderer);
    SDL_RenderPresent(pRenderer);
    
}
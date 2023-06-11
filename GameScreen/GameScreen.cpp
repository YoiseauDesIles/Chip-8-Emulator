#include "GameScreen.h"

GameScreen::GameScreen()
{


}

uint8_t GameScreen::initialiseSDL(uint16_t width, uint16_t height)
{

    if (SDL_Init(SDL_INIT_VIDEO) != 0 )
    {
        std::cout << "Échec de l'initialisation de la SDL";
        return -1;
    }

    // SDL_CreateWindowAndRenderer(width, height, 0, &pWindow, &pRenderer);
    SDL_Window* pWindow{ nullptr };       
    // SDL_Renderer* pRenderer{ nullptr };   

    if (SDL_CreateWindowAndRenderer(512, 256, SDL_WINDOW_SHOWN, &pWindow, &pRenderer) < 0)     
    {         
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "[DEBUG] > %s", SDL_GetError());         
        SDL_Quit();         
        return EXIT_FAILURE;     
    }           
    
    SDL_SetWindowTitle(pWindow, "Hello !");     
    SDL_SetRenderDrawColor(pRenderer, 25, 125, 100, 255);    
    SDL_RenderClear(pRenderer);

    SDL_SetRenderDrawColor(pRenderer, 255, 0, 0, 255); // On choisis la couleur rouge 
    SDL_Rect rectangle1{20, 20, 8, 8};
    SDL_RenderFillRect(pRenderer, &rectangle1);
    // SDL_RenderDrawRect(pRenderer, &rectangle1); // On dessiner un point 
    SDL_RenderPresent(pRenderer);

    return 0;
}


uint8_t GameScreen::initialisePixelArray()
{

}


uint8_t GameScreen::initialiseScreen()
{

}


uint8_t GameScreen::updateScreen(std::array<std::array<Pixel, 64>, 32> pixelArray )
{
    std::cout<< "updateScreen" << "\n";

    for (int height = 0; height < 32; height++){
        for (int width = 0; width < 64; width++)
        {

            // std::cout << "HEIGHT = " << height;
            // std::cout << "WIDTH = " << width << "\n";
            
            // SDL_SetRenderDrawColor(pRenderer, pixelArray[width][height].getColor()*255, pixelArray[width][height].getColor()*255, pixelArray[width][height].getColor()*255, 255);  
            SDL_SetRenderDrawColor(pRenderer, 125, 125, 125, 255);  
            SDL_Rect rect{width*8, height*8, 8, 8};
            // SDL_RenderFillRect(pRenderer, pixelArray[height][width].getPosition());
            SDL_RenderFillRect(pRenderer, &rect);

            std::cout << " pixel HEIGHT = " << height << ", width = " << width << ", position x = " << pixelArray[height][width].getPosition().x << ", position y = " << pixelArray[height][width].getPosition().y << "\n";
            // SDL_RenderPresent(pRenderer);
        }
    }
    SDL_RenderPresent(pRenderer);

}
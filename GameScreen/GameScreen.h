#pragma once
#include <iostream>
#include <array>
#include <SDL.h>
#include "../Pixel/Pixel.h"

class GameScreen
{

private:
    SDL_Window *pWindow = nullptr;
    SDL_Renderer *pRenderer = nullptr;

public:
    GameScreen();
    virtual ~GameScreen() = default;

    uint8_t initialiseScreen(uint16_t width, uint16_t height);
    uint8_t updateScreen(std::array<std::array<Pixel, 64>, 32> pixelArray);
    uint8_t resetScreen();
};

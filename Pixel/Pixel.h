#pragma once

#include <iostream>
#include <array>
#include <SDL.h>

class Pixel
{
    private:
        SDL_Rect m_position;
        uint8_t m_color;

    public:
        Pixel();
        virtual ~Pixel() = default;

        SDL_Rect getPosition() { return m_position; }
        uint8_t getColor() { return m_color; }

        void setPosition(SDL_Rect position) { m_position = position; }
        void setColor(uint8_t color) { m_color = color; }
};
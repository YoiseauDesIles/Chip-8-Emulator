#pragma once

#include <iostream>
#include <array>
#include <SDL.h>
#include "../Registry/Registry.h"

class Controller 
{
    private:
        SDL_Event event;

    public:
        Controller() {};
        virtual ~Controller() = default;

        uint8_t updateInputState(std::array<uint8_t, 16> & keys) const;
        uint8_t waitForInput(Registry & registry, std::array<uint8_t, 16> & keys, uint8_t XRegistry) const;
};
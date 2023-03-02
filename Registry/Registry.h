#pragma once

#include <iostream>
#include <array>

class Registry
{
    private:
        std::array<uint8_t, 16> registries;
        uint16_t I = 0x0000;

    public:

        Registry();
        virtual ~Registry() = default;

        uint8_t getRegistry(uint8_t index) const { return registries[index]; }
        uint16_t getI() const { return I; }

        void setI(uint16_t reg) {I = reg;}
        void setRegistry(uint8_t index, uint8_t value) { registries[index] = value; }
};
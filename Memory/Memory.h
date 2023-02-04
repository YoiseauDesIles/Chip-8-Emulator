#include <iostream>
#include <array>
#include "../Cartridge/Cartridge.h"
#include <cstdint>


class Memory 
{

    private:
        std::array<uint8_t, 4 * 1024> ram;

    public:
        Memory();
        virtual ~Memory();
        uint8_t read(uint16_t const &address) const;
        void write(uint16_t const &address, uint8_t const &data);
        void copyCartridge();
    
};
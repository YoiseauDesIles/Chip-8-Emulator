#include <iostream>
#include <fstream>
#include <array>
#include <string>


class Cartridge 
{
    private:
        std::array<uint8_t, 3232> programData;
        std::array<char, 3232> programData2;

    public:
        Cartridge(); 
        virtual ~Cartridge() = default;

        uint8_t parseGameData();

        void printCartrigde() const;

        std::array<uint8_t, 3232> getProgramData() { return programData; }
    
};
#include "Registry.h"


Registry::Registry()
{

    std::fill(std::begin(registries), std::end(registries), 0x00);
    I = 0x0204;
    registries[0] = 0xFF;
    registries[1] = 0x02;
    registries[2] = 0x03;

}
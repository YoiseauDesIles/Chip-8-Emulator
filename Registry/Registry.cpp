#include "Registry.h"


Registry::Registry()
{

    std::fill(std::begin(registries), std::end(registries), 0x00);
    I = 0xFFFF;
    registries[0] = 0x02;
    registries[1] = 0x02;
    registries[2] = 0x01;

}
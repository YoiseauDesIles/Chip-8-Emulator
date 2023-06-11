#include "Registry.h"


Registry::Registry()
{

    std::fill(std::begin(registries), std::end(registries), 0x00);
    I = 0x0204;

}
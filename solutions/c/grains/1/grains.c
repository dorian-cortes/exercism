#include "grains.h"


uint64_t square(uint8_t index)
{
    if(index < 2) return index;
    
    uint64_t g = 1;

    for(uint16_t i = 0; i < index - 1; i++)
    {
        g *= 2;
    }

    return g;
}

uint64_t total(void)
{
    return UINT64_MAX;
}
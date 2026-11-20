#include "eliuds_eggs.h"

uint32_t egg_count(uint32_t decimal)
{
    uint32_t eggs = 0;
    uint32_t result = decimal;
    
    while(result > 0)
    {
        if (result % 2 != 0)
        {
            eggs++;
        }
        
        result /= 2;
    }

    return eggs;
}
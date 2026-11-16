#include "resistor_color_trio.h"

resistor_value_t color_code(resistor_band_t *bands)
{
    const resistor_band_t first = bands[0];
    const resistor_band_t second = bands[1];
    const resistor_band_t third = bands[2];    

    size_t len = 2 + third + 1;
    char *buffer = malloc(len);
    snprintf(buffer, len, "%d%d", first, second);
        
    for(int i = 0; i < (int) third; i++)
    {
        strcat(buffer, "0");
    }    

    uint64_t full = (uint64_t)strtoull(buffer, NULL, 10);
    free(buffer);        

    if(full >= (int) GIGAOHMS)
    {
        return (resistor_value_t){ full / GIGAOHMS, GIGAOHMS };
    }

    if(full >= (int) MEGAOHMS)
    {
        return (resistor_value_t){ full / MEGAOHMS, MEGAOHMS };
    }

    if(full >= (int) KILOOHMS)
    {
        return (resistor_value_t){ full / KILOOHMS, KILOOHMS };
    }

    return (resistor_value_t){ full, OHMS };
}
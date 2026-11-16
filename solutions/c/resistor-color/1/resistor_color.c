#include "resistor_color.h"

uint16_t color_code(resistor_band_t resistor)
{
    return (uint16_t) resistor;
}

const resistor_band_t* colors()
{    
    static const resistor_band_t c[] = 
    {
        BLACK, 
        BROWN,
        RED,
        ORANGE,
        YELLOW,
        GREEN,
        BLUE,
        VIOLET,
        GREY,
        WHITE
    };

    return (const resistor_band_t*) c;    
}
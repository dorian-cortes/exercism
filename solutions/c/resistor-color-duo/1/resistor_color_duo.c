#include "resistor_color_duo.h"

uint16_t color_code(resistor_band_t *colors)
{    
    char buffer[3];
    snprintf(buffer, sizeof(buffer), "%d%d", (int) colors[0], (int) colors[1]);

    return atoi(buffer);     
}
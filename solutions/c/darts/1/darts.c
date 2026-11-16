#include "darts.h"

bool is_in_radius(coordinate_t *landing_position, float *radius)
{
    float x2 = landing_position->x * landing_position->x;
    float y2 = landing_position->y * landing_position->y;
    float r2 = (*radius) * (*radius);

    return (x2 + y2) <= r2;
}

uint8_t score(coordinate_t landing_position)
{
    static float inner_radius = 1.0F;
    static float middle_radius = 5.0F;
    static float outer_radius = 10.0F;
    
    if(is_in_radius(&landing_position, &inner_radius))
    {
        return 10;
    }

    if(is_in_radius(&landing_position, &middle_radius))
    {
        return 5;
    }

    if(is_in_radius(&landing_position, &outer_radius))
    {
        return 1;
    }

    return 0;
}
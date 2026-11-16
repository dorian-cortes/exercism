#include "space_age.h"

float get_planet_orbital_period(planet_t planet)
{
    switch (planet)
    {
        case MERCURY:
            return 0.2408467F;
        case VENUS:
            return 0.61519726F;
        case EARTH:
            return 1.0F;
        case MARS:
            return 1.8808158F;
        case JUPITER:
            return 11.862615F;
        case SATURN:
            return 29.447498F;
        case URANUS:
            return 84.016846F;
        case NEPTUNE:
            return 164.79132F;
        default:
            return -1.0F;
    }
}

float age(planet_t planet, int64_t seconds)
{
    const float orbital_period = get_planet_orbital_period(planet);

    if(orbital_period < 0.0F)
    {
        return orbital_period;
    }
    
    static const int64_t one_earth_year_in_seconds = 31557600;
    const int64_t earth_years = seconds / one_earth_year_in_seconds;
    
    return ((float) (earth_years / orbital_period));
}
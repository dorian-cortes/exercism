#ifndef DARTS_H
#define DARTS_H

#include <stdint.h>
#include <stdbool.h>

typedef struct {
    float x;
    float y;
} coordinate_t;

uint8_t score(coordinate_t landing_position);
bool is_in_radius(coordinate_t *landing_position, float *radius);

#endif

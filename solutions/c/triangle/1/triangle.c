#include "triangle.h"

bool is_triangle(triangle_t t)
{   
    return (
        !(t.a == 0 || t.b == 0 || t.c == 0) &&
        t.a + t.b >= t.c &&
        t.b + t.c >= t.a &&
        t.a + t.c >= t.b
    );
}

bool is_equilateral(triangle_t t)
{
    return (
        is_triangle(t) &&
        t.a == t.b &&
        t.b == t.c
    );
}

bool is_isosceles(triangle_t t)
{
    return (
        is_triangle(t) &&
        !is_scalene(t)
    );
}

bool is_scalene(triangle_t t)
{
    return (
        is_triangle(t) &&
        t.a != t.b &&
        t.b != t.c &&
        t.c != t.a 
    );
}

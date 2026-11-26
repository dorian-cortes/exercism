#include "complex_numbers.h"

complex_t c_add(complex_t z1, complex_t z2)
{
    double a = z1.real;
    double b = z1.imag;
    double c = z2.real;
    double d = z2.imag;

    complex_t r = {
        a + c,
        b + d
    };

    return r;
}

complex_t c_sub(complex_t z1, complex_t z2)
{
    double a = z1.real;
    double b = z1.imag;
    double c = z2.real;
    double d = z2.imag;

    complex_t r = {
        a - c,
        b - d
    };

    return r;
}

complex_t c_mul(complex_t z1, complex_t z2)
{
    double a = z1.real;
    double b = z1.imag;
    double c = z2.real;
    double d = z2.imag;

    complex_t r = {
        a * c - b * d,
        b * c + a * d
    };

    return r;
}

complex_t c_div(complex_t z1, complex_t z2)
{
    double a = z1.real;
    double b = z1.imag;
    double c = z2.real;
    double d = z2.imag;
    
    complex_t r = {
        (a * c + b * d) / (pow(c, 2) + pow(d, 2)),
        (b * c - a * d) / (pow(c, 2) + pow(d, 2))
    };

    return r;
}

double c_abs(complex_t z)
{
    double a = z.real;
    double b = z.imag;    

    return sqrt(pow(a, 2) + pow(b, 2));
}

complex_t c_conjugate(complex_t z)
{
    double a = z.real;
    double b = z.imag;    

    complex_t r = {
        a,
        b * -1
    };

    return r;
}

double c_real(complex_t z)
{
    double a = z.real;    
    return a;
}

double c_imag(complex_t z)
{    
    double b = z.imag;    

    return b;
}

complex_t c_exp(complex_t z)
{
    double a = z.real;
    double b = z.imag;
    
    complex_t r = {
        pow(E, a) * cos(b),
        pow(E, a) * sin(b)
    };

    return r;
}

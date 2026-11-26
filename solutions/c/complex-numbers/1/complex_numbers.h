#ifndef COMPLEX_NUMBERS_H
#define COMPLEX_NUMBERS_H

#include <math.h>

#define E exp(1)

typedef struct {
   double real;
   double imag;
} complex_t;

complex_t c_add(complex_t z1, complex_t z2);
complex_t c_sub(complex_t z1, complex_t z2);
complex_t c_mul(complex_t z1, complex_t z2);
complex_t c_div(complex_t z1, complex_t z2);
double c_abs(complex_t z);
complex_t c_conjugate(complex_t z);
double c_real(complex_t z);
double c_imag(complex_t z);
complex_t c_exp(complex_t z);

#endif

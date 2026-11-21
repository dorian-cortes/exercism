#include "perfect_numbers.h"

kind_t classify_number(int n)
{
    if(n < 1)
    {
        return ERROR;
    }

    int current = 1;
    int sum = 0;

    while(current < n)
    {
        if(n % current == 0)
        {
            sum += current;
        }
        current++;
    }
    
    if(n == sum)
    {
        return PERFECT_NUMBER;
    }

    if(n < sum)
    {
        return ABUNDANT_NUMBER;
    }

    return DEFICIENT_NUMBER;
}
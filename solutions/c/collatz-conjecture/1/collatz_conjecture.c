#include "collatz_conjecture.h"


int steps(int start)
{
    if(start < 1)
    {
        return ERROR_VALUE;
    }

    int counter = 0;
    int number = start;
    
    while(number != 1)
    {
        if(number % 2 == 0)
        {            
            number /= 2;
        }
        else
        {            
            number = (number * 3) + 1;
        }    

        counter++;
    }

    return counter;    
}
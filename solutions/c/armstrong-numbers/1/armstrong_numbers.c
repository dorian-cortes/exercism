#include "armstrong_numbers.h"

bool is_armstrong_number(int candidate)
{
    if(candidate < 0)
    {
        return false;
    }
    
    size_t len = 16;
    char num_str[len];
    snprintf(num_str, len, "%d", candidate);
    size_t digit_count = strlen(num_str);

    int sum = 0;
    for(size_t i = 0; i < digit_count; i++)
    {
        int digit = atoi((char[]){ num_str[i], '\0' });
        sum += pow(digit, digit_count); 
    }

    return sum == candidate;
}
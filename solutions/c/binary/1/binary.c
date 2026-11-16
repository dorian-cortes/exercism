#include "binary.h"

int convert(const char *input)
{
    size_t len = strlen(input);

    int n = 0;
    int p = 1;
    
    for(size_t i = len - 1; i < len; i--)
    {
        if(input[i] != '1' && input[i] != '0')
        {
            return INVALID;
        }
        
        if(input[i] == '1')
        {
            n += p;
        }

        p *= 2;
    }

    return n;
}
#include "luhn.h"

bool luhn(const char *num)
{
    if(num == NULL)
    {
        return false;
    }
    
    int16_t len = strlen(num);
    int16_t digits_found = 0;
    uint16_t sum = 0;    
    bool odd = false;    
    
    for(int16_t i = len - 1; i >= 0; i--)
    {
        if(!isdigit(num[i]) && !isspace(num[i]))
        {
            return false;
        }

        if(isspace(num[i]))
        {
            continue;
        }
        
        digits_found++;
        
        int n = atoi((char[]){ num[i] });

        if(odd)
        {
            int x2 = n * 2;
            n = x2 > 9 ? x2 - 9 : x2;
        }

        sum += n;        
        odd = !odd;
    }

    if(sum == 0 && digits_found < 2)
    {
        return false;
    }

    return sum % 10 == 0;
}

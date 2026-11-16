#include "hamming.h"


int compute(const char *lhs, const char *rhs)
{
    int hd = 0;

    size_t lhs_len = strlen(lhs);
    size_t rhs_len = strlen(rhs);

    if(lhs_len != rhs_len)
    {
        return -1;
    }

    for(size_t i = 0; i < lhs_len; i++)
    {
        if(lhs[i] != rhs[i])
        {
            hd++;
        }
    }
    
    return hd;
}
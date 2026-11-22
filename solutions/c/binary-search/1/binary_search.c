#include "binary_search.h"

const int *binary_search(int value, const int *arr, size_t length)
{   
    size_t start = 0;
    size_t end = length;
    
    while((end - start) > 0)
    {
        size_t middle = start + ((end - start) / 2);
        
        if(arr[middle] == value)
        {
            return &arr[middle];
        }

        if(value < arr[middle])
        {
            end = middle;
        }
        
        if(arr[middle] < value)
        {
            start = middle + 1;
        }
    }

    return NULL;
}

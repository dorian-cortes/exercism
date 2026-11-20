#include "raindrops.h"

void convert(char result[], int drops)
{
    bool by3 = drops % 3 == 0;
    bool by5 = drops % 5 == 0;
    bool by7 = drops % 7 == 0;

    if(!by3 && !by5 && !by7)
    {
        snprintf(result, sizeof(char) * BUFFER_LENGTH, "%d", drops);
        return;
    }

    if(by3)
    {
        strcat(result, "Pling");
    }

    if(by5)
    {
        strcat(result, "Plang");
    }

    if(by7)
    {
        strcat(result, "Plong");
    }
}
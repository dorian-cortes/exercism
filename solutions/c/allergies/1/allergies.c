#include "allergies.h"

bool is_allergic_to(allergen_t allergen, int score)
{
    return (1 << (int) allergen) & score;
}

allergen_list_t get_allergens(int score)
{
    allergen_list_t results = { 0, { false } };

    if(score == 0)
    {
        return results;
    }
    
    for(int i = 0; i < ALLERGEN_COUNT; i++)
    {
        results.allergens[i] = is_allergic_to((allergen_t) i, score);        
        if(results.allergens[i])
        {
            results.count ++;
        }
    }

    return results;
}

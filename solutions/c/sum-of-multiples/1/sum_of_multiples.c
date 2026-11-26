#include "sum_of_multiples.h"

set_t* set_new()
{
    set_t* set = malloc(sizeof(set_t));
    set->head = NULL;
    set->current = NULL;
    return set;
}

void set_reset_iterator(set_t *set)
{
    set->current = set->head;
}

set_item_t * set_next_item(set_t *set)
{
    if(set->current == NULL)
    {
        return NULL;
    }   
    
    set_item_t * next = set->current;
    set->current = set->current->next;
    
    return next;
}

uint32_t * set_next(set_t *set)
{
    set_item_t * current_item = set_next_item(set);
    
    if (current_item == NULL)
    {
        return NULL;
    }

    return &(current_item->value);
}

void set_add(set_t *set, uint32_t value)
{    
    set_item_t *item = malloc(sizeof(set_item_t));
    item->value = value;
    item->next = NULL;
    
    if(set->head == NULL)
    {
        set->head = item;        
        return;
    }

    set_reset_iterator(set);
    set_item_t * current_item = set_next_item(set);
    
    while(current_item != NULL)
    {
        if(current_item->value == value)
        {
            free(item);
            break;
        }
        
        if(current_item->next == NULL)
        {
            current_item->next = item;
            break;
        }
        
        current_item = set_next_item(set);
    }
}

void set_free(set_t *set)
{
    set_reset_iterator(set);
    set_item_t * current_item = set_next_item(set);
    
    while(current_item != NULL)
    {
        free(current_item);
        current_item = set_next_item(set);
    }

    free(set);
}

uint32_t sum(const uint32_t *factors, const size_t number_of_factors, const uint32_t limit)
{
    set_t* set = set_new();    
    
    for(size_t i = 0; i < number_of_factors; i++)
    {
        if (factors[i] == 0)
        {
            continue;
        }
        
        uint32_t multiplier = 1;
        while(true)
        {
            uint32_t multiplication = factors[i] * multiplier; 
            if(multiplication < limit)
            {
                set_add(set, multiplication);
                multiplier++;
                continue;
            }

            break;
        }
    }

    uint32_t result = 0;
    set_reset_iterator(set);
    uint32_t * value = set_next(set);
    
    while(value != NULL)
    {
        result += *value;
        value = set_next(set);
    }

    set_free(set);

    return result;    
}

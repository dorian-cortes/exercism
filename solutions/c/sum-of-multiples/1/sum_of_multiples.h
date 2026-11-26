#ifndef SUM_OF_MULTIPLES_H
#define SUM_OF_MULTIPLES_H

#include <stdbool.h>
#include <stdlib.h>
#include <stddef.h>
#include <stdint.h>

typedef struct SetItem {
    uint32_t value;
    struct SetItem *next;
} set_item_t;

typedef struct Set {
    set_item_t *head;
    set_item_t *current;
} set_t;

set_t* set_new();
void set_add(set_t *set, uint32_t value);
void set_reset_iterator(set_t *set);
set_item_t* set_next_item(set_t *set);
uint32_t* set_next(set_t *set);
void set_free(set_t *set);

uint32_t sum(const uint32_t *factors, const size_t number_of_factors,
                 const uint32_t limit);

#endif

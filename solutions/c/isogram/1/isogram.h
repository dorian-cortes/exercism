#ifndef ISOGRAM_H
#define ISOGRAM_H

#include <stdbool.h>
#include <string.h>
#include <stdint.h>

char get_char(const uint8_t code);
uint8_t get_code(const char character);
bool is_letter(const char character);
char to_lower(const char character);
bool is_isogram(const char phrase[]);

#endif

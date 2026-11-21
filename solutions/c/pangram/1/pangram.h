#ifndef PANGRAM_H
#define PANGRAM_H

#include <stdbool.h>
#include <string.h>
#include <stdint.h>

#define ALPHABET_LEN (26)

bool is_pangram(const char *sentence);

char get_char(const uint8_t code);
uint8_t get_code(const char character);
bool is_letter(const char character);
char to_lower(const char character);

#endif

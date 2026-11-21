#include "pangram.h"

char get_char(const uint8_t code)
{
    return (char) code;
}

uint8_t get_code(const char character)
{
    return (uint8_t) character;
}

bool is_letter(const char character)
{
    uint8_t char_code = get_code(character);
    return (
        (get_code('A') <= char_code && char_code <= get_code('Z')) || 
        (get_code('a') <= char_code && char_code <= get_code('z'))
    );
}

char to_lower(const char character)
{
    uint8_t char_code = get_code(character);
    
    if(!is_letter(character))
    {
        return get_char(char_code);
    }

    uint8_t a_code = get_code('a');
    
    if(char_code < a_code)
    {
        uint8_t lower_code =  char_code + (a_code - get_code('A'));
        return  get_char(lower_code);
    }
    
    return get_char(char_code);
}

bool is_pangram(const char *sentence)
{
    if(sentence == NULL)
    {
        return false;
    }
    
    char unique_letters_found[ALPHABET_LEN] = { get_char(0) };
    size_t len = strlen(sentence);
    
    for(size_t i = 0; i < len; i++)
    {
        char character = sentence[i];
        
        if(!is_letter(character))
        {
            continue;
        }

        character = to_lower(character);

        size_t relative_index = get_code(character) - get_code('a');

        if(unique_letters_found[relative_index] != character)
        {
            unique_letters_found[relative_index] = character;
        }
    }
    
    for(size_t i = 0; i < ALPHABET_LEN; i++)
    {
        if(unique_letters_found[i] == get_char(0))
        {
            return false;
        }
    }

    return true;
}
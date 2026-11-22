#include "isogram.h"

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

bool is_isogram(const char phrase[])
{
    if(phrase == NULL)
    {
        return false;
    }
    
    bool alphabet_checks[26] = { false };
    size_t phrase_len = strlen(phrase);

    for(size_t i = 0; i < phrase_len; i++)
    {
        if(!is_letter(phrase[i]))
        {
            continue;
        }

        char lower = to_lower(phrase[i]);
        uint8_t alphabet_index = get_code(lower) - get_code('a');

        if(alphabet_checks[alphabet_index])
        {
            return false;
        }
        
        alphabet_checks[alphabet_index] = true;
    }

    return true;
}
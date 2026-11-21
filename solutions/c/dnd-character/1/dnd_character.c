#include "dnd_character.h"

int ability(void)
{
    int min = 3;
    int max = 18;
    srand(time(NULL));
    return (rand() % (max - min + 1)) + min;
}

int modifier(int score)
{
    score -= 10;
    float m = score / 2.0F;
    return  floorf(m);
}
    
dnd_character_t make_dnd_character(void)
{
    dnd_character_t character;
    character.strength = ability();
    character.dexterity = ability();
    character.constitution = ability();
    character.intelligence = ability();
    character.wisdom = ability();
    character.charisma = ability();
    character.hitpoints = 10 + modifier(character.constitution);
    return character;
}
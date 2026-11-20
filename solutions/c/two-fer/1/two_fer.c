#include "two_fer.h"

void two_fer(char *buffer, const char *name)
{
    snprintf(buffer, sizeof(char) * BUFFER_SIZE, "One for %s, one for me.", name == NULL || strlen(name) == 0 ? "you" : name);
}
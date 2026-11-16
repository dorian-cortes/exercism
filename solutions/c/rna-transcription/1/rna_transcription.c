#include "rna_transcription.h"

char *to_rna(const char *dna)
{
    size_t len = strlen(dna);
    char *rna = malloc(len);
    
    for(size_t i = 0; i < len; i++)
    {
        char c = dna[i];
        switch (c)
        {
            case 'G':
                rna[i] = 'C';
                break;
            case 'C':
                rna[i] = 'G';
                break;
            case 'T':
                rna[i] = 'A';
                break;
            case 'A':
                rna[i] = 'U';
                break;
        }
    }
    
    return rna;
}
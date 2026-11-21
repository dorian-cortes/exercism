#include "high_scores.h"

int32_t latest(const int32_t *scores, size_t scores_len)
{
    return scores[scores_len - 1];
}

int32_t personal_best(const int32_t *scores, size_t scores_len)
{
    int32_t best = INT32_MIN;
    for(size_t i = 0; i < scores_len; i++)
    {
        if(scores[i] > best)
        {
            best = scores[i];
        }
    }

    return best;
}

size_t personal_top_three(const int32_t *scores, size_t scores_len, int32_t *output)
{    
    if(scores == NULL || scores_len == 0)
    {
        return 0;
    }

    size_t copy_size = scores_len * sizeof(*scores);
    int32_t *scores_copy = malloc(copy_size);
    
    memcpy(scores_copy, scores, copy_size);

    // order desc order
    bool changed;
    do
    {
       changed = false;
        for(size_t i = 1; i < scores_len; i++)
        {
            int32_t left = scores_copy[i - 1];
            int32_t right = scores_copy[i];
            if(right > left)
            {
                scores_copy[i - 1] = right;
                scores_copy[i] = left;
                changed = true; 
            }
        }
        // as long as at least 1 changed go again until no changes
    }
    while(changed);

    size_t w;
    for(w = 0; w < scores_len && w < TOP_SCORES_ARRAY_SIZE; w++)
    {
        output[w] = scores_copy[w];
    }

    free(scores_copy);
    
    return w;
}
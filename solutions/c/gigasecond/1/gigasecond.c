#include "gigasecond.h"

void gigasecond(time_t input, char *output, size_t size)
{
    struct tm *input_utc = gmtime(&input); // parse seconds as utc time
    input_utc->tm_sec += (int) 1e9; // add 1 000 000 000 seconds
    mktime(input_utc); // re-sync time after updating it so it makes sense
    strftime(output, size, "%F %T", input_utc); // %F is for YYYY-MM-dd and %T is for HH:mm:ss with 24H format
}

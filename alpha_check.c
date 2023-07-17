#include "main.h"

int alpha_check(int ch)
{
    if (((ch >= 65) && (ch <= 90)) || ((ch >= 97) && (ch <= 122)))
    {
        return (-1);
    }
    else
    {
        return (0);
    }
}
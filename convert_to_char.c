#include "main.h"
char *convert_to_char(unsigned int number)
{
    int a = 0, length = 0;
    char *str;

    length = length_of_int(number);
    str = malloc(length + 1);
    if (!str)
        return (NULL);
    
    *str = '\0';
    while (number / 10)
    {
        str[a] = (number % 10) + '0';
        number /= 10;
    }
    str[a] = (number % 10) + '0';
    reverse_call(str, length);
    str[a + 1] = '\0';
    return (str);
}

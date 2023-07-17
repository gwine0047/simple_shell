#include "main.h"

int _putchar(char ch)
{
    return (write(1, &ch, 1));
}


void write_in(const char *ch)
{
    write(STDOUT_FILENO, ch, _strlen(ch));
}


int _strlen(const char *str)
{
    int a = 0;

    while (str[a])
    {
        a++;
    }
    return (a);
}

char *_strcpy(char *to, char *from)
{
    int a = 0;

    while (from[a] != '\0')
    {
        to[a] = from[a];
        a++;
    }
    to[a] = '\0';
    return (to);
}

int _strncmp(const char *first, const char *second, size_t n)
{
    size_t a = 0;

    if (first == NULL)
        return (-1);

    while (second[a] && a < n)
    {
        if (first[a] != second[a])
        {
            return (1);
        }
        a++;
    }
    return (0);
}

char *_strdup(char *str)
{
    char *new;
    size_t length, a = 0;

    length = _strlen(str);

    new = malloc(sizeof(char) * (length + 1));
    if (new == NULL)
        return (NULL);
    
    while (a <= length)
    {
        new[a] = str[a];
        a++;
    }
    return (new);
}

char *_strchr(char *string, char ch)
{
    int a = 0;
    do{
        if (string[a] == ch)
            break;
    } while (a++);
    return (string);
}

char *_strcat(char *to, char *from)
{
    char *new;
    
    new = to;

    while (*to)
        to++;
    
    while (*from)
    {
        *to = *from;
        to++;
        from++;
    }
    *to = '\0';
    return (new);
}

int _strcmp(char *first, char *second)
{
    int comparism = 0, first_length, second_length, a = 0;

    first_length = _strlen(first);
    second_length = _strlen(second);

    if (first == NULL || second == NULL)
        return (1);
    
    if (first_length != second_length)
        return (1);
    
    while (first[a])
    {
        if (first[a] != second[a])
        {
            comparism = first[a] - second[a];
            break;
        }
        else
            continue;
    }
    return (comparism);
}
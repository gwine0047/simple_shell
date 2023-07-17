#include "main.h"

void hash(char *store)
{
    int a = 0;

    while (store[a] != '\0')
    {
        if (store[a] == '#')
        {
            store[a] = '\0';
            break;
        }
        a++;
    }
}

char *transfer(char *to, char *from, unsigned int size)
{
    unsigned int a = 0;

    while (a < size)
    {
        from[a] = to[a];
        a++;
    }
    return (to);
}

void *fill(void *ptr, int nil, unsigned int size)
{
    char *rep;
    unsigned int a = 0;

    rep = ptr;
    while (a < size)
    {
        *rep = nil;
        rep++;
        a++;
    }
    return (ptr);
}


int length_of_int(int number)
{
    int length;

    for (length = 0; number != 0; length++)
    {
        number = number / 10;
    }
    return (length);
}


void reverse_call(char *array, int length)
{
    int a = 0, len;
    char temp;

    len = length - 1;
    while (a < (length / 2))
    {
        temp = array[a];
        array[a] = array[len - a];
        array[len - a] = temp;
        a++;
    }
}

void print_positive(unsigned int num)
{
    unsigned int holder;

    holder = num;
    if ((holder / 10) > 0)
        print_positive(holder / 10);

    _putchar(holder % 10 + '0');
}

void print_negative(int num)
{
    unsigned int holder;

    holder = num;
    if (num < 0)
    {
        _putchar('-');
        holder = -holder;
    }
    if ((holder / 10) > 0)
        print_positive(holder / 10);
    
    _putchar(holder % 10 + '0');
}

int _atoi(char *str)
{
    int index1, index2, neg, num;

    index1 = 0;
    num = 0;
    neg = 0;

    while ((str[index1] < '0' || str[index1] > '9') && str[index1] != '\0')
    {
        if (str[index1] == '-')
            neg = neg * (-1);
        index1++;
    }
    index2 = index1;
    while ((str[index2] >= '0') && (str[index2] <= '9'))
    {
        num = (num * 10) + neg * ((str[index2] - '0'));
        index2++;
    }
    return (num);
}
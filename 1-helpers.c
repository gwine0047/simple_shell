#include "main.h"
/**
 * hash - replaces # character with a null terminator.
 * @store: is a pointer to characters to be checked.
 * Return: void.
*/
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

/**
 * transfer - copies a string.
 * @from: string to be copied.
 * @to: newly copied string .
 * @size: the size of characters to be copied.
 * Return: the newly copied string.
*/

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

/**
 * fill - fills up a pointer with a constant byte.
 * @ptr: pointer to be filled.
 * @nil: to be alloted.
 * @size: amount to be alloted.
 * Return: pointer to the filled.
*/

int *fill(void *ptr, int nil, unsigned int size)
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

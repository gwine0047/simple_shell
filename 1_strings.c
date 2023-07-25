#include "main.h"
/**
 * _strcpy - copies a string to another.
 * @to: string to be copied.
 * @from: new string produced.
 * Return: the newly copied string.
*/
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

/**
 * _strncmp - compares two strings
 * @first: first string.
 * @second: second string.
 * @n: the amount of bytes to be copied.
 * Return: 0 if successful.
*/
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

/**
 * _strdup - creates a copy for a given string and allocates a memory
 * @str: copied string.
 * Return: newly copied string.
*/
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

/**
 * _strchr - checks if a character is contained in a string.
 * @string: string.
 * @ch: character.
 * Return: string.
*/
char *_strchr(char *string, char ch)
{
	int a = 0;

	do {
		if (string[a] == ch)
		break;
	} while (a++);
	return (string);
}

/**
 * _strcat - concatenates a string to another.
 * @to: original string.
 * @from: string to be added.
 * Return: newly made string.
*/
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



#include "main.h"
/**
 * _putchar - prints a character to stdin.
 * @ch: character to be printed.
 * Return: the character.
*/

int _putchar(char ch)
{
	return (write(1, &ch, 1));
}

/**
 * write_in - writes an array of characters into the standard output.
 * @ch: string
 * Return: Nothing.
*/
void write_in(const char *ch)
{
	write(STDOUT_FILENO, ch, _strlen(ch));
}

/**
 * _puts - writes a string.
 * @str: string
 * Return: Nothing
*/
void _puts(char *str)
{
	int a = 0;

	for (; str[a]; a++)
	{
		_putchar(str[a]);
	}
}

/**
 * _strlen - computes the length of a string.
 * @str: string.
 * Return: the length.
*/
int _strlen(const char *str)
{
	int a = 0;

	while (str[a])
	{
		a++;
	}
	return (a);
}

/**
 * _strcmp - compares two strings.
 * @first: first string.
 * @second: second string.
 * Return: the difference in comparism
*/
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


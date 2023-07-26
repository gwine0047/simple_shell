#include "main.h"
/**
 * _getline - reads a char from a stream.
 *
 * Return: a pointer to the char read.
 */

char *_getline()
{
	char ch = 0;
	int size = BUFFER_SIZE;
	int a = 0;
	int byte_read;
	char *store;

	store = malloc(size);
	if (store == NULL)
	{
		free(store);
		return (NULL);
	}

	while (ch != '\n' && ch != EOF)
	{
		byte_read = read(STDIN_FILENO, &ch, 1);
		if (byte_read == 0)
		{
			free(store);
			exit(EXIT_SUCCESS);
		}
		store[a] = ch;
		if (store[0] == '\n')
		{
			free(store);
			return ("");
		}
		if (a >= size)
		{
			store = _realloc(store, size, size + 1);
			if (store == NULL)
			{
				return (NULL);
			}
		}
		a++;
	}
	store[a] = '\0';
	hash(store);
	return (store);
}

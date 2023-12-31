#include "main.h"

/**
 * parsing - breaks a pointer to an array of characters into tokens.
 * @command: command sring.
 * Return: an array of strings.
*/

char **parsing(char *command)
{
	char **tokens, *token, *copy;
	int a = 0, token_count = 0;

	if (command == NULL)
		return (NULL);

	copy = strdup(command);
	if (copy == NULL)
		return (NULL);

	token = strtok(copy, "\n ");
	while (token)
	{
		token_count++;
		token = strtok(NULL, "\n ");
	}

	tokens = malloc(sizeof(char *) * BUFFER_SIZE);

	if (tokens == NULL)
	{
		perror("hsh");
		return (NULL);
	}

	token = strtok(command, "\n ");

	while (token != NULL)
	{
		tokens[a] = token;
		token = strtok(NULL, "\n ");
		a++;
	}
	tokens[a] = NULL;
	free(copy);
	return (tokens);
}

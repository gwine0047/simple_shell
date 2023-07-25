#include "main.h"

/**
 * command_path - creates a command path for a command.
 * @command_tokens: command.
 * Return: 0 if successful and 1 if not.
*/
int command_path(char **command_tokens)
{
	char *env_path, *token, *built_path;
	struct stat storage;

	env_path = _getenv("PATH");
	token = strtok(env_path, ":");
	while (token)
	{
		built_path = create_path(*command_tokens, token);

		if (stat(built_path, &storage) == 0)
		{
		*command_tokens = strdup(built_path);
		free(built_path);
		free(env_path);
		return (0);
		}
		free(built_path);
		token = strtok(NULL, ":");

	}
	free(env_path);
	return (1);
}

/**
 * create_path - creates a path for a command token.
 * @command_token: command,
 * @token: command path to be matched.
 * Return: path
*/

char *create_path(char *command_token, char *token)
{
	char *path;
	size_t length;

	length = _strlen(token) + _strlen(command_token) + 2;
	path = malloc(sizeof(char) * length);

	if (path == NULL)
		return (NULL);

	memset(path, 0, length);

	path = _strcat(path, token);
	path = _strcat(path, "/");
	path = _strcat(path, command_token);
	return (path);
}

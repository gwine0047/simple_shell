#include "main.h"

/**
 * if_inbuilt - checks if a command is an inbuilt command.
 * @command_tokens: command.
 * Return: 0 if successful and -1 if not.
*/
int if_inbuilt(char **command_tokens)
{
	int a;
	builtin array[] = {
		{"cd", NULL},
		{"help", NULL},
		{"history", NULL},
		{"echo", NULL},
		{"env", NULL},
		{NULL, NULL}
	};

	if (command_tokens == NULL)
		return (-1);

	for (a = 0; (array + a)->command; a++)
	{
		if (_strcmp(command_tokens[0], (array + a)->command) == 0)
		{
			return (0);
		}
	}
	return (-1);
}

/**
 * command_inbuilt - matches a command with an inbuilt function.
 * @command_tokens: command.
 * @state: integer status.
 * Return: the function if successful and -1 if not.
*/

int command_inbuilt(char **command_tokens, int state)
{
	int a;
	builtin array[] = {
		{"cd", change_dir},
		{"help", command_help},
		{"history", command_history},
		{"echo", command_echo},
		{"env", command_env},
		{NULL, NULL}
	};

	if (command_tokens == NULL)
		return (-1);

	for (a = 0; (array + a)->command; a++)
	{
		if (_strcmp(command_tokens[0], (array + a)->command) == 0)
		{
			return ((array + a)->function(command_tokens, state));
		}
	}
	return (-1);
}

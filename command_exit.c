#include "main.h"

/**
 * command_exit - exits a shell program.
 * @command_tokens: command strings.
 * @command: command.
 * @count: integer status.
 * @argv: commandline arguments.
 * Return: void.
*/
void command_exit(char **command_tokens, char *command, int count, char **argv)
{
	int state, a = 0;

	if (command_tokens[1] == NULL)
	{
		free(command_tokens);
		free(command);
		exit(EXIT_SUCCESS);
	}

	while (command_tokens[1][a])
	{
		if (alpha_check(command_tokens[1][a++]) != 0)
		{
			write_error(argv, count, command_tokens);
			break;
		}
		else
		{
			state = _atoi(command_tokens[1]);
			free(command);
			free(command_tokens);
			exit(state);
		}
	}
}

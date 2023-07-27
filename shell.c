#include "main.h"

/**
 * main - main function.
 * @argc: argument count.
 * @argv: argument vector.
 * Return: status.
*/
int main(__attribute__((unused))int argc, char **argv)
{
	int status = 1, count = 0, state = 0;
	char *command, **command_tokens;

	while (status)
	{
		count++;
		if (isatty(STDIN_FILENO))
			print_prompt();

		command = _getline();
		if (command[0] == '\0')
			continue;
		store_history(command);
		command_tokens = parsing(command);

		if (_strcmp(command_tokens[0], "exit") == 0)
		{
			command_exit(command_tokens, command, count, argv);
		}
		else if (if_inbuilt(command_tokens) == 0)
		{
			state = command_inbuilt(command_tokens, state);
			free(command_tokens);
			free(command);
			command_tokens = NULL;
			command = NULL;
			continue;
		}
		else
			state = execute_command(command_tokens, command, count, argv);
		free(command_tokens);
		free(command);
		command = NULL;
		command_tokens = NULL;
	}
	if (argv[1])
		file_command(argv[1], argv);
	return (state);
}

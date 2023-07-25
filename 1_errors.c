#include "main.h"
/**
 * write_error - writes an error message to the standard output
 * @argv: command argument
 * @count: exit status
 * @command_tokens: command
 * Return : void
*/

void write_error(char **argv, int count, char **command_tokens)
{
	char *converted_char = convert_to_char(count);

	write_in(argv[0]);
	write_in(": ");
	write_in(converted_char);
	write_in(command_tokens[0]);
	write_in(": Illegal number: ");
	write_in(command_tokens[1]);
	write_in("\n");

	free(converted_char);
}

/**
 * print_error - writes an error message to the standard output
 * @argv: command argument
 * @count: exit status
 * @command: command
 * Return : void
*/

void print_error(char *command, int count, char **argv)
{
	char *converted_char;

	write_in(argv[0]);
	write_in(": ");
	converted_char = convert_to_char(count);
	write_in(converted_char);
	free(converted_char);
	write_in(": ");
	write_in(command);
	write_in(": not found\n");
}

#include "main.h"

/**
 * store_history - stores command history.
 * @command: commands.
 * Return: 1 if successful and -1 if not.
*/
int store_history(char *command) /*This is not my command history*/
{
	ssize_t file_desc, write_byte;
	int length =  0;
	char *file = ".simple_shell_history";

	if (!file)
		return (-1);

	file_desc = open(file, O_CREAT | O_RDWR | O_APPEND, 00600);
	if (file_desc < 0)
		return (-1);

	if (command != NULL)
	{
		while (command[length])
		length++;
		write_byte = write(file_desc, command, length);
		if (write_byte < 0)
			return (-1);
	}
	return (1);
}

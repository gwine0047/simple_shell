#include "main.h"
/**
 * _free - frees a memory and assigned it to NULL;
 * @command_tokens: pointer to a string be freed.
 * @command: pointer to a char to be freed.
 * Returns: void.
*/

void _free(char **command_tokens, char *command)
{
    free(command_tokens);
    free(command);

    command_tokens = NULL;
    command = NULL;
}
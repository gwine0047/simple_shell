#include "main.h"
void _free(char **command_tokens, char *command)
{
    free(command_tokens);
    free(command);

    command_tokens = NULL;
    command = NULL;
}
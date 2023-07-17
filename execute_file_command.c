#include "main.h"
void execute_file_command(char *line, int count, FILE *file_ptr, char **argv)
{
    int state = 0;
    char **command_tokens;

    command_tokens = parsing(line);
    if (_strncmp(command_tokens[0], "exit", 4) == 0)
        command_exit_file(command_tokens, line, file_ptr);

    else if (if_inbuilt(command_tokens) == 0)
    {
        state = command_inbuilt(command_tokens, state);
        free(command_tokens);
        command_tokens = NULL;
    }
    else
    {
        state = execute_command(command_tokens, line, count, argv);
        free (command_tokens);
        command_tokens = NULL;
    }
}
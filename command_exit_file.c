#include "main.h"
void command_exit_file(char **command_tokens, char *line, FILE *file_desc)
{
    int a = 0, status;

    if (command_tokens[1] == NULL)
    {
        free(line);
        free(command_tokens);
        fclose (file_desc);
        exit(errno);
    }
    while (command_tokens[1][a])
    {
        if (alpha_check(command_tokens[1][a++]) < 0)
            perror("illegal number");
    }
    status = _atoi(command_tokens[1]);
    free(line);
    free(command_tokens);
    fclose(file_desc);
    exit(status);
}
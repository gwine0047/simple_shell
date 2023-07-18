#include "main.h"

/**
 * execute_command - executes a command.
 * @command_tokens: array of commands
 * @command: command.
 * @count: exit status.
 * @argv: array of commandline argument.
 * Return: 0 if successful.
*/
int execute_command(char **command_tokens, char *command, int count, char **argv)
{
    int status;
    pid_t pid;

    if (*command_tokens ==  NULL)
    {
        return (-1);
    }
    
    pid = fork();

    if (pid == -1)
    {
        perror("Error");
        return (-1);
    }

    else if (pid == 0)
    {
        if (_strncmp(*command_tokens, "./", 2) != 0 && _strncmp(*command_tokens, "/", 1) != 0)
        {
           command_path(command_tokens);
        }
        if (execve(*command_tokens, command_tokens, environ) == -1)
        {
            print_error(command_tokens[0], count, argv);
            free(command);
            free(command_tokens);
            exit(EXIT_FAILURE);
            
        }
        free(command);
        free(command_tokens);
        return (EXIT_SUCCESS);
    }
    wait(&status);
    return (0);
}
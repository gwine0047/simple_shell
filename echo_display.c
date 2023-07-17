#include "main.h"
int echo_display(char **command_tokens)
{
    pid_t pid;
    int status;

    pid = fork();
    if (pid == 0)
    {
        if (execve("/bin/echo", command_tokens, environ) == -1)
        {
            return (-1);
            exit(EXIT_FAILURE);
        }
    }
    else if (pid < 0)
    {
        return (-1);
    }
    else
    {
        do  {
                waitpid(pid, &status, WUNTRACED);
        } while (!WIFEXITED(status) && !WIFSIGNALED(status));
    }
        return (1);
}
#include "main.h"

int change_dir (char **command_tokens, __attribute__((unused))int state)
{
    char cwd[PATH_MAX];
    int flag = -1;

    if (command_tokens[1] == NULL)
        flag = chdir(getenv("HOME"));
    
    else if (_strcmp(command_tokens[1], "-") == 0)
    {
        printf("cd - has been called\n");
        flag = chdir(getenv("OLPWD"));
    }
    else
        flag = chdir(command_tokens[1]);

    if (flag == -1)
    {
        perror("hsh");
        return (-1);
    }
    else if (flag != -1)
    {
        getcwd(cwd, sizeof(cwd));
        setenv("OLDPWD", getenv("PWD"), 1);
        setenv("PWD", cwd, 1);
    }
    return (0);
}

int command_help(char **command_tokens, __attribute__((unused))int state)
{
    int file_desc, read_bytes, write_bytes;
    char ch;

    file_desc = open(command_tokens[1], O_RDONLY);
    if (file_desc < 0)
    {
        perror("Error");
        return (0);
    }
    do  {
            read_bytes = read(file_desc, &ch, 1);
            write_bytes = write(STDOUT_FILENO, &ch, read_bytes);

            if (write_bytes < 0)
            {
                return (-1);
            }
    } while (read_bytes > 0);
    
    _putchar('\n');
    return (0);
}

int command_echo(char **command_tokens, int state)
{
    char *path;
    unsigned int pid;

    pid = getppid();
    if (_strncmp(command_tokens[1], "$?", 2) == 0)
    {
        print_negative(state);
        write_in("\n");
    }
    else if (_strncmp(command_tokens[1], "$$", 2) == 0)
    {
        print_positive(pid);
        write_in("\n");
    }
    else if (_strncmp(command_tokens[1], "$PATH", 5) == 0)
    {
        path = _getenv("PATH");
        write_in(path);
        write_in("\n");
        free(path);
    }
    else
        return (echo_display(command_tokens));
    
    return (1);
}


int command_env(__attribute__((unused))char **command_tokens, __attribute__((unused))int state)
{
    int length;
    size_t a = 0;

    while (environ[a] != NULL)
    {
        length = _strlen(environ[a]);
        write(1, environ[a], length);
        write(STDOUT_FILENO, "\n", 1);
        a++;
    }
    return (0);
}

int command_history(__attribute__((unused))char **command_tokens, __attribute__((unused))int state)
{
    char *filename = ".simple_shell_history", *line = NULL, *converted_char;
    int count = 0;
    size_t length = 0;
    FILE *file_ptr;

    file_ptr = fopen(filename, "r");
    if (!file_ptr)
    {
        return (-1);
    }
    while ((getline(&line, &length, file_ptr)) != -1)
    {
        count++;
        converted_char = convert_to_char(count);
        write_in(converted_char);
        free(converted_char);
        write_in(" ");
        write_in(line);
    }
    if (line)
        free(line);
    fclose(file_ptr);
    return (0);
}
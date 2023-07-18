#include "main.h"

/**
 * file_command - reads a command from a file.
 * @name: name of the file.
 * @command: array of commands.
 * Return: void.
*/

void file_command(char *name, char **commands)
{
    int count = 0;
    size_t length = 0;
    char *line = NULL;
    FILE *file_ptr;

    file_ptr = fopen(name, "r");
    if (file_ptr == NULL)
        exit(EXIT_FAILURE);
    
    while ((getline(&line, &length, file_ptr)) != -1)
    {
        execute_file_command(line, count, file_ptr,commands);
        count++;
    }
    if (line)
        free(line);
    fclose(file_ptr);
    exit(0);
}
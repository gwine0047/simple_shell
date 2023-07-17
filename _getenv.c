#include "main.h"
char *_getenv(char *file)
{
    size_t first_length, second_length;
    char *store;
    int a = 0, b, c;

    first_length = _strlen(file);

    for (; environ[a]; a++)
    {
        if (_strncmp(file, environ[a], first_length) == 0)
        {
            second_length = _strlen(environ[a]) - first_length;

            store = malloc(sizeof(char) * second_length);
            if (store == NULL)
            {
                free (store);
                perror("unable to alloc");
                return (NULL);
            }
            b = 0;
            for (c = first_length + 1; environ[a][c]; c++, b++)
            {
                store[b] = environ[a][c];
            }
            store[b] = '\0';
            return (store);
        }
    }
    return (NULL);
    free (store);
}
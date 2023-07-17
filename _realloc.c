#include "main.h"
void *_realloc(void *pointer, unsigned int old_size, unsigned int new_size)
{
    void *memory;

    if (new_size == old_size)
        return (pointer);

    if (new_size == 0 && pointer!= NULL)
    {
        free(pointer);
        return (NULL);
    }
    memory = malloc(new_size);
    if (memory == NULL)
        return (NULL);

    if (pointer == NULL)
    {
        fill(memory, '\0', new_size);
        free(pointer);
    }
    else
    {
        transfer(memory, pointer, old_size);
        free(pointer);
    }
    free (pointer);
    return (memory);
}
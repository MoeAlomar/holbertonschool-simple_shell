#include "shell.h"

/**
* free_args - Frees the memory allocated for the arguments.
* @args: The arguments to free.
*/
void free_args(char **args)
{
int i = 0;

while (args[i] != NULL)
{
free(args[i]);
i++;
}
free(args);
}

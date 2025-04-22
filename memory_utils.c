#include "shell.h"

/**
* free_args - Frees the memory allocated for the arguments.
* @args: The arguments to free.
*/
void free_args(char **args)
{
	int i = 0;
	/* Loop through each argument and free its memory */
	while (args[i] != NULL)
{
	free(args[i]);
	i++;
}
	/* Free the memory allocated for the arguments array itself */
	free(args);
}

#include "shell.h"

/**
* read_line - Reads a line of input from stdin
*
* Return: The input line, or NULL on failure
*/
char *read_line(void)
{
char *line = NULL;
size_t len = 0;
ssize_t nread;

nread = getline(&line, &len, stdin);
if (nread == -1)
{
free(line);
return (NULL);
}
return (line);
}

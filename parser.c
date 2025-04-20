#include "shell.h"

/**
* split_line - Splits a line into an array of arguments (tokens)
* @line: The input line
*
* Return: NULL-terminated array of strings
*/
char **split_line(char *line)
{
int bufsize = 64, i = 0;
char **tokens = malloc(bufsize * sizeof(char *));
char *token;

if (!tokens || !line)
{

perror("malloc");
return (NULL);
}

token = strtok(line, " \t\r\n");
while (token != NULL)
{
tokens[i] = _strdup(token);
if (!tokens[i])
{
  perror("strdup");
  free_args(tokens);
  return (NULL);
}
i ++;

if (i >= bufsize)
{
bufsize *= 2;
tokens = realloc(tokens, bufsize * sizeof(char *));
if (!tokens)
{
perror("realloc");
return (NULL);
}
}
token = strtok(NULL, " \t\r\n");
}
tokens[i] = NULL;
return (tokens);
}

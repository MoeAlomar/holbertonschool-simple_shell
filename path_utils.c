#include "shell.h"

/**
* find_path - Finds the full path of a command.
* @command: The command to find the path for.
* @env: The environment variables.
*
* Return: The full path of the command if found, otherwise NULL.
*/
char *find_path(char *command, char **env)
{
char *path = NULL, *token, *full_path;
struct stat st;
int i;

if (command[0] == '/' || command[0] == '.')
{
if (stat(command, &st) == 0)
return (_strdup(command));
return (NULL);
}

for (i = 0; env[i]; i++)
{
if (_strncmp(env[i], "PATH=", 5) == 0)
{
path = _strdup(env[i] + 5);
break;
}
}
if (!path)
return (NULL);

token = strtok(path, ":");
while (token)
{
full_path = malloc(_strlen(token) + _strlen(command) + 2);
if (!full_path)
{
free(path);
return (NULL);
}
_strcpy(full_path, token);
_strcat(full_path, "/");
_strcat(full_path, command);

if (stat(full_path, &st) == 0)
{
free(path);
return (full_path);
}
free(full_path);
token = strtok(NULL, ":");
}
free(path);
return (NULL);
}

#include "shell.h"

/**
 * get_env_value - Get the value of an environment variable
 * @name: Name of the variable
 *
 * Return: Pointer to the value, or NULL if not found
 */
char *get_env_value(const char *name)
{
	int i;
	size_t len;

	if (!environ || !name)
		return (NULL);

	len = _strlen(name);

	for (i = 0; environ[i]; i++)
	{
		if (_strncmp(environ[i], name, len) == 0 && environ[i][len] == '=')
			return (environ[i] + len + 1);
	}
	return (NULL);
}

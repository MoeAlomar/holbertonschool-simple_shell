#include "main.h"
#include <string.h>

/**
 * resolve_path - Locates an executable via PATH
 * @cmd: The command name (may be absolute or relative)
 *
 * Return: malloc()’d full path if found, or NULL otherwise.
 *         If cmd contains a slash and is executable, returns cmd itself.
 */
char *resolve_path(char *cmd)
{
	char *path_env, *path_dup, *dir, *fullpath;
	size_t len;

	/* If user gave a path, just check execute permission */
	if (strchr(cmd, '/') != NULL)
	{
		if (access(cmd, X_OK) == 0)
			return (cmd);
		return (NULL);
	}

	/* No PATH in environment? */
	path_env = getenv("PATH");
	if (path_env == NULL)
		return (NULL);

	/* Duplicate PATH so strtok() won’t clobber it */
	path_dup = strdup(path_env);
	if (path_dup == NULL)
		return (NULL);

	dir = strtok(path_dup, ":");
	while (dir != NULL)
	{
		len = strlen(dir) + 1 + strlen(cmd) + 1;
		fullpath = malloc(len);
		if (fullpath == NULL)
		{
			free(path_dup);
			return (NULL);
		}
		strcpy(fullpath, dir);
		strcat(fullpath, "/");
		strcat(fullpath, cmd);

		if (access(fullpath, X_OK) == 0)
		{
			free(path_dup);
			return (fullpath);
		}

		free(fullpath);
		dir = strtok(NULL, ":");
	}

	free(path_dup);
	return (NULL);
}

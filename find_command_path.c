#include "shell.h"

/**
 * find_command_path - Searches for a command in PATH
 * @command: The command to find
 * Return: Full path if found, otherwise NULL
 */
char *find_command_path(char *command)
{
	char *path_env, *path_copy, *dir;
	char full_path[1024];
	struct stat st;

	if (strchr(command, '/'))
	{
		if (stat(command, &st) == 0 && (st.st_mode & S_IXUSR))
			return strdup(command);
		return NULL;
	}

	path_env = get_env_value("PATH");
	if (!path_env || *path_env == '\0')
		return NULL;

	path_copy = strdup(path_env);
	if (!path_copy)
		return NULL;

	dir = strtok(path_copy, ":");
	while (dir)
	{
		snprintf(full_path, sizeof(full_path), "%s/%s", dir, command);
		if (stat(full_path, &st) == 0 && (st.st_mode & S_IXUSR))
		{
			free(path_copy);
			return strdup(full_path);
		}
		dir = strtok(NULL, ":");
	}

	free(path_copy);
	return NULL;
}

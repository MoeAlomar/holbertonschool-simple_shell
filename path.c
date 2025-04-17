#include "main.h"
#include <string.h>

/**
 * resolve_path - Locates an executable via PATH (without getenv)
 * @cmd: The command name (may be absolute or relative)
 *
 * Return: malloc()’d full path if found, or NULL otherwise.
 *         If cmd contains a slash and is executable, returns cmd itself.
 */
char *resolve_path(char *cmd)
{
    char *path_env = NULL, *path_dup, *dir, *fullpath;
    size_t len;
    int i;

    /* If cmd has a slash, accept only if directly executable */
    if (strchr(cmd, '/') != NULL)
    {
        if (access(cmd, X_OK) == 0)
            return (cmd);
        return (NULL);
    }

    /* Manually fetch PATH from environ[] */
    for (i = 0; environ[i] != NULL; i++)
    {
        if (strncmp(environ[i], "PATH=", 5) == 0)
        {
            path_env = environ[i] + 5;
            break;
        }
    }
    if (path_env == NULL)
        return (NULL);

    /* Duplicate PATH so strtok() won’t modify the real env */
    path_dup = strdup(path_env);
    if (path_dup == NULL)
        return (NULL);

    /* Walk each directory in PATH */
    dir = strtok(path_dup, ":");
    while (dir != NULL)
    {
        len = strlen(dir) + 1 + strlen(cmd) + 1;
        fullpath = malloc(len);
        if (fullpath == NULL)
            break;
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

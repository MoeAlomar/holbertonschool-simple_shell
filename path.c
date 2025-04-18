#include "main.h"
#include <string.h>

/**
 * resolve_path - Locate an executable via PATH (empty entries = “.”)
 * @cmd: command name or path
 *
 * Return: malloc()’d full path, or cmd itself if it contains ‘/’ and is exec’able;
 *         NULL if not found.
 */
char *resolve_path(char *cmd)
{
    char *path_env = NULL, *path_dup, *dir, *fullpath;
    size_t len;
    int i;

    /* If command contains slash, try it directly */
    if (strchr(cmd, '/') != NULL)
    {
        if (access(cmd, X_OK) == 0)
            return (cmd);
        return (NULL);
    }

    /* Find PATH in environ[] */
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

    /* Duplicate so strtok doesn’t clobber real PATH */
    path_dup = strdup(path_env);
    if (path_dup == NULL)
        return (NULL);

    /* For each dir in PATH */
    dir = strtok(path_dup, ":");
    while (dir != NULL)
    {
        /* empty entry means current directory */
        if (*dir == '\0')
            dir = ".";

        len = strlen(dir) + 1 /* slash */ + strlen(cmd) + 1 /* NUL */;
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

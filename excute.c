#include "main.h"
#include <string.h>

/**
 * execute_command - Parses, resolves, and runs a command
 * @line: input string with newline stripped
 */
void execute_command(char *line)
{
    pid_t pid;
    int status;
    char *argv[MAX_ARGS];
    char *cmd_path;
    int i = 0;

    /* Tokenize into argv[] */
    argv[i] = strtok(line, " ");
    while (argv[i] != NULL && i + 1 < MAX_ARGS)
    {
        i++;
        argv[i] = strtok(NULL, " ");
    }

    /* Nothing entered? do nothing */
    if (argv[0] == NULL)
        return;

    /* Resolve executable */
    cmd_path = resolve_path(argv[0]);
    if (cmd_path == NULL)
    {
        fprintf(stderr, "./hsh: 1: %s: not found\n", argv[0]);
        exit(127);
    }

    /* Only fork & exec if we have a valid path */
    pid = fork();
    if (pid == 0)  /* child */
    {
        execve(cmd_path, argv, environ);
        perror("./hsh");
        exit(127);
    }
    else if (pid < 0)
    {
        perror("Fork failed");
    }
    else  /* parent */
    {
        waitpid(pid, &status, 0);
    }

    /* free the malloc’d path if it wasn’t argv[0] itself */
    if (cmd_path != argv[0])
        free(cmd_path);
}

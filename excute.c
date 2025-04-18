#include "main.h"
#include <string.h>

/**
 * execute_command - Parses and executes a command, handling PATH & errors
 * @line: Input line (newline already removed)
 */
void execute_command(char *line)
{
    pid_t pid;
    int status;
    char *argv[MAX_ARGS];
    char *cmd_path;
    int i = 0;

    /* Tokenize the input into argv[] */
    argv[i] = strtok(line, " ");
    while (argv[i] != NULL && i + 1 < MAX_ARGS)
    {
        i++;
        argv[i] = strtok(NULL, " ");
    }

    /* Ignore empty or all‑spaces input */
    if (argv[0] == NULL)
        return;

    /* Resolve via PATH or accept direct slash paths */
    cmd_path = resolve_path(argv[0]);
    if (cmd_path == NULL)
    {
        /* Print shell‑style error and exit */
        fprintf(stderr, "./hsh: 1: %s: not found\n", argv[0]);
        exit(127);
    }

    /* Fork and exec the resolved command */
    pid = fork();
    if (pid == 0)
    {
        execve(cmd_path, argv, environ);
        perror("./hsh");
        exit(127);
    }
    else if (pid < 0)
    {
        perror("Fork failed");
    }
    else
    {
        waitpid(pid, &status, 0);
    }

    /* Free malloc’d path if we allocated one */
    if (cmd_path != argv[0])
        free(cmd_path);
}

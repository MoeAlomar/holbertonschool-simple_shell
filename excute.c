#include "main.h"
#include <string.h>

/**
 * execute_command - Forks and executes a command with arguments
 * @line: The command to execute
 */
void execute_command(char *line)
{
    pid_t pid;
    int status;
    char *argv[100];
    int i = 0;

    /* split the input into argv[] */
    argv[i] = strtok(line, " ");
    while (argv[i] != NULL)
    {
        i++;
        argv[i] = strtok(NULL, " ");
    }

    /* if the line was empty or only spaces, do nothing */
    if (argv[0] == NULL)
        return;

    pid = fork();
    if (pid == 0)  /* child */
    {
        if (execve(argv[0], argv, environ) == -1)
        {
            perror("./shell");
            exit(127);
        }
    }
    else if (pid < 0)  /* fork failed */
    {
        perror("Fork failed");
    }
    else  /* parent */
    {
        waitpid(pid, &status, 0);
    }
}

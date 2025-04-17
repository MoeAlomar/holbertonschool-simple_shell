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

    /* Tokenize the input line into command and arguments */
    argv[i] = strtok(line, " ");
    while (argv[i] != NULL)
    {
        i++;
        argv[i] = strtok(NULL, " ");
    }

    pid = fork();  /* Create a new process */

    if (pid == 0)  /* Child process */
    {
        if (execve(argv[0], argv, environ) == -1)
        {
            perror("./shell");  /* Print error if execve fails */
            exit(127);  /* Exit with error code */
        }
    }
    else if (pid < 0)  /* Fork failed */
    {
        perror("Fork failed");
    }
    else  /* Parent process */
    {
        waitpid(pid, &status, 0);  /* Wait for child to finish */
    }
}

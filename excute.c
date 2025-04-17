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
	char *argv[100];  /* Array to hold command and arguments */
	int i = 0;

	/* Tokenize the input line into command and arguments */
	argv[i] = strtok(line, " ");  /* Get the first token (command) */
	while (argv[i] != NULL)
	{
		i++;
		argv[i] = strtok(NULL, " ");  /* Get the next tokens (arguments) */
	}

	/* Fork process */
	pid = fork();

	if (pid == 0) /* Child process */
	{
		/* Execute the command */
		if (execve(argv[0], argv, environ) == -1)
		{
			perror("./shell");  /* Print error if execve fails */
			exit(127);  /* Exit with error code */
		}
	}
	else if (pid < 0) /* Fork failed */
	{
		perror("Fork failed");
	}
	else /* Parent process */
	{
		waitpid(pid, &status, 0);  /* Wait for child to finish */
	}
}

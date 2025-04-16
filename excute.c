#include "main.h"

/**
 * execute_command - Forks and executes a command
 * @line: The command to execute
 */
void execute_command(char *line)
{
	pid_t pid;
	int status;
	char *argv[2];

	pid = fork();

	if (pid == 0)
	{
		argv[0] = line;
		argv[1] = NULL;

		if (execve(argv[0], argv, environ) == -1)
		{
			perror("./shell");
			exit(127);
		}
	}
	else if (pid < 0)
	{
		perror("Fork failed");
	}
	else
	{
		waitpid(pid, &status, 0);
	}
}

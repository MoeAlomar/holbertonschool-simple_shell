#include "main.h"

/**
 * main - Simple UNIX command line interpreter
 *
 * Return: Always 0 on success
 */
int main(void)
{
	char *line = NULL;        /* Pointer to store user input */
	size_t len = 0;           /* Size of the allocated buffer for getline */
	ssize_t read;             /* Number of characters read by getline */
	pid_t pid;                /* Process ID for fork */
	int status;               /* Status of the child process */

	while (1) /* Infinite loop: shell keeps running */
	{
		write(STDOUT_FILENO, "#cisfun$ ", 9); /* Display shell prompt */

		read = getline(&line, &len, stdin); /* Read user input */

		if (read == -1) /* Check for EOF (Ctrl+D) or error */
		{
			free(line);               /* Free allocated memory */
			write(STDOUT_FILENO, "\n", 1); /* Print newline before exit */
			exit(0);                  /* Exit shell */
		}

		/* Remove newline character from input (if exists) */
		if (line[read - 1] == '\n')
			line[read - 1] = '\0';

		pid = fork(); /* Create a new process */

		if (pid == 0) /* This is the child process */
		{
			char *argv[2];

			argv[0] = line;  /* Set command as first argument */
			argv[1] = NULL;  /* Null-terminate the argument list */

			/* Replace child process with new program */
			if (execve(argv[0], argv, environ) == -1)
			{
				/* Print error if execve fails (e.g., command not found) */
				perror("./shell");
				exit(127); /* Exit with error code */
			}
		}
		else if (pid < 0) /* If fork fails */
		{
			perror("Fork failed"); /* Print error message */
		}
		else /* Parent process */
		{
			waitpid(pid, &status, 0); /* Wait for child process to finish */
		}
	}

	free(line); /* Free input buffer (not reached due to infinite loop) */
	return (0);
}

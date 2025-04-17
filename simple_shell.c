#include "main.h"

/**
 * main - simple shell entry point
 *
 * Return: Always 0 on success
 */
int main(void)
{
	char *line = NULL;
	size_t len = 0;
	ssize_t nread;

	while (1)
	{
		/* show prompt in interactive mode only */
		if (isatty(STDIN_FILENO))
			write(STDOUT_FILENO, "#cisfun$ ", 9);

		nread = read_input(&line, &len);
		if (nread == -1)  /* EOF (Ctrl+D) or error */
		{
			free(line);
			if (isatty(STDIN_FILENO))
				write(STDOUT_FILENO, "\n", 1);
			exit(0);
		}

		remove_newline(line);
		execute_command(line);
	}

	free(line);
	return (0);
}

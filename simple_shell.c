#include "main.h"

/**
 * main - Entry point for the simple shell
 *
 * Return: Always 0 on success
 */
int main(void)
{
	char *line = NULL;
	size_t len = 0;
	ssize_t read;

	while (1)
	{
		write(STDOUT_FILENO, "#cisfun$ ", 9);
		read = read_input(&line, &len);

		if (read == -1)
		{
			free(line);
			write(STDOUT_FILENO, "\n", 1);
			exit(0);
		}

		remove_newline(line);
		execute_command(line);
	}

	free(line);
	return (0);
}

#include "shell.h"

int last_status = 0;

/**
 * main - Entry point for the simple shell
 *
 * Return: Always 0
 */
int main(void)
{
	char *line = NULL;
	size_t len = 0;
	char *args[MAX_ARGS];
	ssize_t read;

	if (isatty(STDIN_FILENO))
		write(STDOUT_FILENO, "$ ", 2);

	while ((read = getline(&line, &len, stdin)) != -1)
	{
		if (line[read - 1] == '\n')
			line[read - 1] = '\0';

		if (!only_spaces(line))
		{
			parse_arguments(line, args);
			if (args[0] != NULL)
			{
				if (strcmp(args[0], "exit") == 0)
				{
					free(line);
					exit(last_status);
				}
				handle_command(args);
			}
		}

		if (isatty(STDIN_FILENO))
			write(STDOUT_FILENO, "$ ", 2);
	}

	free(line);
	return (last_status);
}

#include "shell.h"

/**
 * execute_command - Execute the given command
 * @args: Command arguments
 * @status: Previous command status
 * @env: Environment variables
 * @line: Current command line (for freeing in exit)
 *
 * Return: Exit status of executed command
 */
int execute_command(char **args, int status, char **env, char *line)
{
	int exit_code;

	/* Built-in: exit */
	if (strcmp(args[0], "exit") == 0)
	{
		exit_code = status;

		/* If user provided an exit code, use it */
		if (args[1])
			exit_code = atoi(args[1]);

		free(line);
		free_args(args);
		exit(exit_code);
	}
	/* Built-in: env */
	else if (strcmp(args[0], "env") == 0)
	{
		print_env(env);
		return (0);
	}
	else
	{
		/* Execute external command and save its exit status */
		return (execute(args, env));
	}
}

/**
 * process_commands - Processes the user input and executes commands
 * @status: Stores the last command exit status
 * @env: The environment variables
 *
 * Return: The last exit status
 */
int process_commands(int status, char **env)
{
	char *line = NULL;
	char **args = NULL;

	while (1)
	{
		/* Display prompt if interactive */
		if (isatty(STDIN_FILENO))
			write(STDOUT_FILENO, "$ ", 2);

		line = read_line();
		if (!line)
		{
			/* Handle EOF */
			if (isatty(STDIN_FILENO))
				write(STDOUT_FILENO, "\n", 1);
			break;
		}

		args = split_line(line);
		if (!args || !args[0])
		{
			free(line);
			free_args(args);
			continue;
		}

		status = execute_command(args, status, env, line);

		free(line);
		free_args(args);
	}

	return (status);
}

/**
 * main - Entry point for shell
 * @argc: Argument count (unused)
 * @argv: Argument vector (unused)
 * @env: Environment variables
 *
 * Return: Last exit status of executed command or exit code
 */
int main(int argc, char **argv, char **env)
{
	int status = 0; /* Store last command exit status */

	(void)argc;
	(void)argv;

	status = process_commands(status, env);
	return (status);
}

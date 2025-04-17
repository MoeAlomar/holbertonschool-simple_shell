#include "main.h"
#include <string.h>

/**
 * execute_command - Parses, resolves, and runs a command
 * @line: Raw input line (with trailing newline removed)
 */
void execute_command(char *line)
{
	pid_t pid;
	int status;
	char *argv[MAX_ARGS];
	char *cmd_path;
	int i = 0;

	argv[i] = strtok(line, " ");
	while (argv[i] != NULL && i + 1 < MAX_ARGS)
	{
		i++;
		argv[i] = strtok(NULL, " ");
	}

	/* Ignore empty or whitespace-only input */

	if (argv[0] == NULL)
		return;

	/* Resolve via PATH (or accept an absolute/relative path) */
	cmd_path = resolve_path(argv[0]);
	if (cmd_path == NULL)
	{
		fprintf(stderr, "%s: command not found\n", argv[0]);
		return;
	}

	pid = fork();
	if (pid == 0)  /* child */
	{
		execve(cmd_path, argv, environ);
		perror("./shell");
		exit(127);
	}
	else if (pid < 0)  /* fork failed */
	{
		perror("Fork failed");
	}
	else  /* parent */
	{
		waitpid(pid, &status, 0);
	}

	/* free malloc’d path (not needed if cmd_path was argv[0] itself) */
	if (cmd_path != argv[0])
		free(cmd_path);
}

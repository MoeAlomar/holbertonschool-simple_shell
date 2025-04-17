#include "main.h"

/**
 * read_input - Reads a line of input from the user
 * @line: Pointer to the buffer to store input
 * @len:  Pointer to the size of that buffer
 *
 * Return: Number of characters read, or -1 on failure
 */
ssize_t read_input(char **line, size_t *len)
{
	return (getline(line, len, stdin));
}

/**
 * remove_newline - Strips trailing newline, if any
 * @line: The string to sanitize
 */
void remove_newline(char *line)
{
	size_t i = 0;

	while (line[i] != '\0')
	{
		if (line[i] == '\n')
		{
			line[i] = '\0';
			break;
		}
		i++;
	}
}

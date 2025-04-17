#include "main.h"

/**
 * read_input - Reads a line of input from the user
 * @line: Pointer to the buffer to store input
 * @len: Pointer to the size of the buffer
 *
 * Return: Number of characters read, or -1 on failure
 */
ssize_t read_input(char **line, size_t *len)
{
	return (getline(line, len, stdin));  // Read input from stdin
}

/**
 * remove_newline - Removes newline character from end of string
 * @line: The string to modify
 */
void remove_newline(char *line)
{
	size_t i = 0;

	// Find newline character and remove it
	while (line[i])
	{
		if (line[i] == '\n')
		{
			line[i] = '\0';
			break;
		}
		i++;
	}
}

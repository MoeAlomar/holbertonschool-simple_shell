#include "shell.h"

/**
 * only_spaces - Checks if a line contains only whitespace
 * @s: The input string
 *
 * Return: 1 if only spaces, 0 otherwise
 */
int only_spaces(char *s)
{
	while (*s)
	{
		if (*s != ' ' && *s != '\t' && *s != '\n')
			return (0);
		s++;
	}
	return (1);
}

/**
 * read_line - Reads a line from standard input
 *
 * Return: Pointer to the read line (must be freed), or NULL on EOF/empty line
 */
char *read_line(void)
{
	char *line = NULL;
	size_t len = 0;
	ssize_t read;

	read = getline(&line, &len, stdin);
	if (read == -1)
	{
		free(line);
		return (NULL);
	}

	if (line[read - 1] == '\n')
		line[read - 1] = '\0';

	if (only_spaces(line))
	{
	free(line);
	return (NULL);
	}

	return (line);
}

/**
 * parse_arguments - Tokenizes a command line into arguments
 * @line: Input command line
 * @args: Array to store the arguments
 */
void parse_arguments(char *line, char **args)
{
	int i = 0;
	char *token;

	/* تخلص من المسافات في البداية */
	while (*line == ' ' || *line == '\t')
		line++;

	token = tokenize_input(line);
	while (token != NULL && i < MAX_ARGS - 1)
	{
		args[i] = token;
		i++;
		token = tokenize_input(NULL);
	}
	args[i] = NULL;
}


/**
 * tokenize_input - Custom tokenizer function (like strtok)
 * @line: The line to tokenize (or NULL to continue)
 *
 * Return: Pointer to next token, or NULL if no more
 */
char *tokenize_input(char *line)
{
	static char *current;
	char *start;

	if (line)
		current = line;

	while (*current == ' ' || *current == '\t')
		current++;

	if (*current == '\0')
		return (NULL);

	start = current;

	while (*current && *current != ' ' && *current != '\t')
		current++;

	if (*current)
	{
		*current = '\0';
		current++;
	}

	return (start);
}

/**
 * _strlen - Calculates the length of a string (like strlen)
 * @s: The input string
 *
 * Return: Length of the string
 */
int _strlen(const char *s)
{
	int len = 0;

	/* Loop until we reach the null terminator */
	while (s[len])
		len++;

	return (len);
}

/**
 * _strncmp - Compares two strings up to n bytes (like strncmp)
 * @s1: First string
 * @s2: Second string
 * @n: Number of characters to compare
 *
 * Return: 0 if strings are equal up to n, otherwise difference
 */
int _strncmp(const char *s1, const char *s2, size_t n)
{
	size_t i;

	/* Compare character by character until n or difference is found */
	for (i = 0; i < n && s1[i] && s2[i]; i++)
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
	}

	/* If we reached here but one string ended early */
	if (i < n)
		return (s1[i] - s2[i]);

	return (0); /* Strings are equal up to n */
}
/**
 * _strdup - Duplicates a string (like the standard strdup)
 * @str: The input string to duplicate
 *
 * Return: A pointer to the newly allocated copy of the string,
 *         or NULL if memory allocation fails
 */
char *_strdup(const char *str)
{
	char *dup;
	int len = _strlen(str);
	int i;

	/* Allocate memory for the new string (+1 for null terminator) */
	dup = malloc(sizeof(char) * (len + 1));
	if (!dup)
		return (NULL);

	/* Copy characters from original string */
	for (i = 0; i < len; i++)
		dup[i] = str[i];

	dup[i] = '\0'; /* Null-terminate the new string */
	return (dup);
}

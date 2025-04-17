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
        write(STDOUT_FILENO, "#cisfun$ ", 9);  /* Display prompt */
        read = read_input(&line, &len);  /* Read input from user */

        if (read == -1)  /* Handle EOF (Ctrl+D) */
        {
            free(line);
            write(STDOUT_FILENO, "\n", 1);  /* Print newline before exit */
            exit(0);
        }

        remove_newline(line);  /* Remove newline character from input */

        execute_command(line);  /* Execute the input command */
    }

    free(line);
    return (0);
}

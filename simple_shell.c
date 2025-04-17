/* simple_shell.c */
#include "main.h"
#include <unistd.h>  /* for isatty() */

int main(void)
{
    char *line = NULL;
    size_t len = 0;
    ssize_t nread;

    while (1)
    {
        /* only print prompt if we're interactive */
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


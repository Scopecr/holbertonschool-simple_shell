#include "shell.h"
#ifndef SHELL_H
#define SHELL_H

/* ... other includes and definitions ... */

/**
 * _which - searches for a command in the PATH environment variable
 * @command: the command to search for
 * @fullpath: pointer to store the full path of the command (output)
 * @path: the PATH environment variable
 * Return: 1 if found, 0 if not found, -1 on error
 */
int _which(char *command, char **fullpath, char *path);

/* ... other function prototypes ... */

#endif

int main(void)
{
    char *line = NULL;
    size_t len = 0;
    ssize_t read;
    char **tokens = NULL;
    char *fullpath = NULL;
    int status = 1;

    while (status)
    {
        printf(PROMPT);
        read = getline(&line, &len, stdin);
        if (read == -1)
            break;

        tokens = tokenizer(line);
        if (tokens == NULL)
            continue;

        if (_which(tokens[0], &fullpath, getenv("PATH")) == 1)
            status = builtin_execute(tokens);
        else
            status = child(fullpath, tokens);

        free_dp(tokens, _strlen_arr(tokens));
        free(fullpath);
    }

    free(line);
    return EXIT_SUCCESS;
}

#include "shell.h"

/**
 * main - entry point for the shell program
 * @argc: argument count
 * @argv: argument vector
 * @env: environment variables
 * Return: 0 on success
 */
int main(int argc, char *argv[], char **env)
{
    char *line = NULL, **tokens = NULL, *path = NULL;
    struct stat buf;
    size_t len = 0;
    ssize_t read = 0;
    int fd = 0;

    (void)argc;
    (void)argv;
    environ = env;

    /* Set up the PATH */
    path = _getenv("PATH");
    if (!path)
    {
        perror("Failed to retrieve PATH");
        exit(EXIT_FAILURE);
    }

    /* Check if the terminal is interactive */
    if (isatty(STDIN_FILENO))
    {
        prompt(STDOUT_FILENO, buf);
    }

    while ((read = getline(&line, &len, stdin)) != -1)
    {
        fd = STDIN_FILENO;

        /* Handle EOF (Ctrl-D) */
        if (read == 0)
        {
            _puts("\n");
            break;
        }

        /* Remove newline character */
        if (line[read - 1] == '\n')
        {
            line[read - 1] = '\0';
        }

        /* Tokenize the input line */
        tokens = tokenizer(line);

        /* Handle built-in functions or execute external command */
        if (tokens[0])
        {
            char *fullpath = NULL;
            int status = 0;

            if (_which(tokens[0], &fullpath, path) == 1)
            {
                status = builtin_execute(tokens, fullpath);
                free(fullpath);
            }
            else
            {
                status = child(tokens[0], tokens);
            }

            /* Free memory */
            free_dp(tokens);
            free(line);

            if (isatty(STDIN_FILENO))
            {
                prompt(STDOUT_FILENO, buf);
            }

            if (status == -1)
            {
                perror("Error");
            }
        }
    }

    free(path);

    return (0);
}


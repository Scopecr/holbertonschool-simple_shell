#include "shell.h"

int main(void)
{
    char *line = NULL;
    size_t len = 0;
    ssize_t read;
    char **tokens = NULL;
    char *fullpath = NULL;
    int status = TRUE;

    while (status)
    {
        prompt(STDOUT_FILENO, (struct stat){0});
        read = _getline(stdin, &line, &len);
        if (read == -1)
            break;

        tokens = shell_line_splitter(line);
        if (tokens == NULL)
            continue;

        if (_which(tokens[0], &fullpath, _getenv("PATH")) == 1)
            status = builtin_execute(tokens);
        else
            status = child(fullpath, tokens);

        free_dp(tokens, _strlen(tokens));
        free(fullpath);
    }

    free(line);
    return EXIT_SUCCESS;
}

#include "shell.h"

int main(void)
{
    char *line = NULL;
    char **tokens = NULL;
    char *fullpath = NULL;
    int status = TRUE;

    while (status)
    {
        prompt(STDOUT_FILENO, (struct stat){0});
        line = _getline(stdin);

        if (!line)
            break;

        tokens = shell_line_splitter(line);
        if (tokens == NULL)
            continue;

        if (_which(tokens[0], &fullpath, _getenv("PATH")) == 1)
            status = builtin_execute(tokens);
        else
            status = child(fullpath, tokens);

        free_dp(tokens, tokens_count(tokens));
        free(fullpath);
        free(line);
    }

    return EXIT_SUCCESS;
}


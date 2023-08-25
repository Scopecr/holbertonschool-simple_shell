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
        read = getline(&line, &len, stdin);
        if (read == -1)
            break;

        tokens = tokenizer(line);
        if (tokens == NULL)
            continue;

        if (_which(tokens[0], &fullpath, _getenv("PATH")) == 1)
            status = builtin_execute(tokens);
        else
            status = child(fullpath, tokens);

        for (int i = 0; tokens[i] != NULL; i++)
        {
            free(tokens[i]);
        }
        free(tokens);
        free(fullpath);
    }

    free(line);
    return EXIT_SUCCESS;
}

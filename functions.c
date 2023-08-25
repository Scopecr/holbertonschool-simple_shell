#include "shell.h"

/* Implement shell_line_splitter function */
char **shell_line_splitter(char *line)
{
    int buffersize = SHELL_Token_64;
    int position = 0;
    char **tokens = malloc(buffersize * sizeof(char *));
    char *token;

    if (!tokens)
    {
        fprintf(stderr, "lsh: allocation error\n");
        exit(EXIT_FAILURE);
    }

    token = strtok(line, TOKEN_Delimitator);
    while (token != NULL)
    {
        tokens[position] = token;
        position++;

        if (position >= buffersize)
        {
            buffersize += SHELL_Token_64;
            tokens = realloc(tokens, buffersize * sizeof(char *));
            if (!tokens)
            {
                fprintf(stderr, "lsh: allocation error\n");
                exit(EXIT_FAILURE);
            }
        }

        token = strtok(NULL, TOKEN_Delimitator);
    }

    tokens[position] = NULL;
    return tokens;
}

/* Implement tokens_count function */
unsigned int tokens_count(char **tokens)
{
    unsigned int count = 0;
    while (tokens[count] != NULL)
        count++;
    return count;
}

int main(void)
{
    char *line = NULL;
    ssize_t read;
    char **tokens = NULL;
    char *fullpath = NULL;
    int status = TRUE;

    while (status)
    {
        prompt(STDOUT_FILENO, (struct stat){0});
        read = getline(&line, &(size_t){0}, stdin);
        if (read == -1)
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
    }

    free(line);
    return EXIT_SUCCESS;
}

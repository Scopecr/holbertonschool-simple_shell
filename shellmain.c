#include "shell.h"

int main(void)
{
    char *line = NULL, **tokens = NULL, *fullpath = NULL;
    size_t len = 0;
    ssize_t read;
    struct stat buf;

    prompt(STDOUT_FILENO, buf);

    while ((read = getline(&line, &len, stdin)) != -1)
    {
        tokens = tokenizer(line);
        if (!tokens)
            continue;

        if (_which(tokens[0], &fullpath, getenv("PATH")) == 1)
        {
            status = builtin_execute(tokens);
        }
        else
        {
            if (stat(tokens[0], &buf) == 0)
            {
                if (S_ISREG(buf.st_mode) && (buf.st_mode & S_IXUSR))
                    status = child(tokens[0], tokens);
                else
                    status = 126;
            }
            else
            {
                _puts("shell: command not found: ");
                _puts(tokens[0]);
                _puts("\n");
                status = 127;
            }
        }

        free_dp(tokens, _strlen_arr(tokens));
        free(fullpath);
        prompt(STDOUT_FILENO, buf);
    }

    free(line);
    return status;
}

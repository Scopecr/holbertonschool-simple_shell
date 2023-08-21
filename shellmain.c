#include "shell.h"


int main(void)
{
	char *line , *path, *fullpath;
	char **token;
	int flag, builtin_status, child_status;
	struct stat buf;

	while (TRUE)
	{
		prompt(STDIN_FILENO, buf);
		line = _getline(stdin);
		if (_strcmp(line, "\n", 1) == 0)
		{
			free(line);
			continue;
		}
		tokens = tokenizer(line);
		if (tokens[0] == NULL)
				continue;
		builtin_status = builtin_execute(token);
		if (builtin_status == 0 || builtin_status == -1)
				_exit(EXIT_SUCCESS);
		flag = 0 ; /* 0 if full_path is not malloc'd*/
		path = _getenv("PATH");
		fullpath = _which(token[0], fullpath, path);
		if (fullpath == NULL)
				fullpath = tokens[0];
		else
				flag = 1; /* if fullpath was malloc'd, flag to free */
				child_status = child(fullpath, tokens);
				if (child_status == -1)
						errors(2);
				free_all(tokens, path, line, fullpath, flag);
	}
	return (0);
}
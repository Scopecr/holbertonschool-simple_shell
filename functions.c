#include "shell.h"

/**
	* run_programm - run a programm and close it when done.
	* @args: Arguments for the function.
	* Return: 1.
	*/
int run_programm(char **args)
{
	pid_t pid, wpid;
	int status;
	(void)wpid;

	/** forks the parent */
	pid = fork();

	/** checks the fork worked */
	if (pid == 0)
	{
		/** Child */
		if (execvp(args[0], args) == -1)
		{
			perror("lsh");
		}
		exit(EXIT_FAILURE);
	}
	else if (pid < 0)
	{
		/** error in fork */
		perror("lsh");
	}
	/** if it did this runs */
	else
	{
		/** Parent */
		do {
			wpid = waitpid(pid, &status, WUNTRACED);
		} while (!WIFEXITED(status) && !WIFSIGNALED(status));
	}

	/** to keep the shell running */
	return (1);
}

/**
	* run_line_reader - read the input from user.
	* Return: the read input in an pointer.
	*/
char *run_line_reader()
{
	int buffersize = READLINE_Megabite;
	int position = 0;
	char *buffer = malloc(sizeof(char) * buffersize);
	int c;

	/** if malloc fails, exit with error*/
	if (!buffer)
	{
		fprintf(stderr, "lsh: allocation error\n");
		exit(EXIT_FAILURE);
	}

	/** reads the input and puts it in a array */
	while (1)
	{
		/** reads the current character*/
		c = getchar();

		/*
		 * if we hit the end of the file,
		 * we change it for a null and return the array.
		 */
		if (c == EOF || c == '\n')
		{
			buffer[position] = '\0';
			return (buffer);
		}
		else
		{
			buffer[position] = c;
		}

		/** move to next char */
		position++;

		/*
		 * in case we dont have enough space,
		 * we give more space to the buffer.
		 */
		if (position >= buffersize)
		{
			buffersize += READLINE_Megabite;
			buffer = realloc(buffer, buffersize);

			/** if it fails, we print error */
			if (!buffer)
			{
				fprintf(stderr, "lsh: allocation error\n");
				exit(EXIT_FAILURE);
			}
		}
	}
}

/**
	* shell_line_splitter - Split a line into tokens (very naively).
	* @line: The line from run_line_reader.
	* Return: the tokens
	*/
char **shell_line_splitter(char *line)
{
	int buffersize = SHELL_Token_64;
	int position = 0;
	char **tokens = malloc(buffersize * sizeof(char *));
	char *token;

	/** if malloc fails print error */
	if (!tokens)
	{
		fprintf(stderr, "lsh: allocation error\n");
		exit(EXIT_FAILURE);
	}

	token = strtok(line, TOKEN_Delimitator);

	/** creates an array with each token inside of it */
	while (token != NULL)
	{
		tokens[position] = token;
		position++;

		/** allocats more space to tokens array if it doesnt have enough */
		if (position >= buffersize)
		{
			buffersize += SHELL_Token_64;
			tokens = realloc(tokens, buffersize * sizeof(char *));

			/** if malloc fails print error */
			if (!tokens)
			{
				fprintf(stderr, "lsh: allocation error\n");
				exit(EXIT_FAILURE);
			}
		}

		token = strtok(NULL, TOKEN_Delimitator);
	}

	tokens[position] = NULL;
	return (tokens);
}
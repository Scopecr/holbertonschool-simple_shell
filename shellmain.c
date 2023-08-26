#include "shell.h"

/**
	* shell_loop_input - gets the input and runs it with the other functions.
	*/
void shell_loop_input(void)
{
	char *line;
	char **args;
	int status;

	/** prints the $ and receives the input and runs command if any is provided */
	do {
		printf("$ ");
		line = run_line_reader();
		args = shell_line_splitter(line);
		status = run_executer(args);

		free(line);
		free(args);
	} while (status);
}

/**
	* main - runs the program lmao.
	* @argc: number of arguments.
	* @argv: array of arguments.
	* Return: status of the code.
	*/
int main(int argc, char **argv)
{
	char **v = argv;
	int c = argc;
	(void)c;
	(void)v;

	/** determines if its in interactive mode or not */
	if (isatty(0))
	{
		shell_loop_input();
	}
	else
	{
		noninteractive();
	}


	return (EXIT_SUCCESS);
}

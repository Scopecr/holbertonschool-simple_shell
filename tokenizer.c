#include "shell.h"

/**
	* noninteractive - gets the input and runs it with the other functions.
	*/
void noninteractive(void)
{
	char *line;
	char **args;

	line = run_line_reader();
	args = shell_line_splitter(line);
	run_executer(args);

	free(line);
	free(args);
}
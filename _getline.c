#include "shell.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * _getline - take character input and stores it in a pointer
 * @bp: file pointer to read from
 * 
 * Return: line to be stored on getline
*/
char *_getline(FILE *bp)
{
	char *line = NULL;
	size_t len = 0;
	ssize_t read;

	if (bp == NULL)
	{
		fprintf(stderr, "Invalid file pointer\n");
		exit(EXIT_FAILURE);
	}

	read = getline(&line, &len, bp);
	if (read == -1)
	{
		free(line);
		exit(EXIT_SUCCESS);
	}
	else if (read == 0)
	{
		free(line);
		return NULL;
	}

	return line;
}
/**
 * _getline - take character input ans stores it in a pointer
 * @line: pointer that captures the string of characters
 * @read: reads the character input
 * @len: measure the length of line
 * 
 * Return: line to be stored on getline
*/
char *_getline(FILE *bp)
{
	char *line;
	ssize_t read;
	size_t len;

	line = NULL;
	len = 0;
	read = getline(&line, &len, bp);
	if (read == -1)
	{
		free(line);
		exit(EXIT_SUCCESS);
	}
	return (line);
}

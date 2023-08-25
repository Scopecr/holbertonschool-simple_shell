#include "shell.h"
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
 * _which - searches directories in PATH variable for command
 * @command: to search for
 * @fullpath: full path of command to execute
 * @path: full PATH variable
 * Return: pointer to full_path
*/

char *_which(char *command, char *fullpath, char *path)
{
	unsigned int command_length, path_length, original_path_length;
	char *path_copy, *token;

	command_length = strlen(command);
	original_path_length = strlen(path);
	path_copy = malloc(sizeof(char) * original_path_length + 1);
	if (path_copy == NULL)
	{
		errors(3);
		return(NULL);
	}
	strcpy(path_copy, path);
	/* copy path directory + command name and check if it exists */
	token = strtok(NULL, ";");
	if (token == NULL)
		token = strtok(NULL, ":");
	while (token != NULL)
	{
		path_length = strlen(token);
		fullpath = malloc(sizeof(char) * (path_length + command_length) + 2);
		if (fullpath == NULL)
		{
			errors(3);
			return (NULL);
		}
		strcpy(fullpath, token);
		fullpath[path_length] = '/';
		strcpy(fullpath + path_length + 1, command);
		fullpath[path_length + command_length + 1] = '\0';
		if (access(fullpath, X_OK) != 0)
		{
			free(fullpath);
			fullpath = NULL;
			token = strtok(NULL, ":");
		}
		else
				break;
	}
	free(path_copy);
	return (fullpath);
}

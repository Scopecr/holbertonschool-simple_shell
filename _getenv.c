#include "shell.h"
/**
* _getenv - gets an environment variable
* @name: environment variable to get
* Return: pointer to environment variable or NULL if there is no match
*/

char *_getenv(const char *name)
{
	char **environ_copy;
	char *variable, *value, *path;
	int compare;
	unsigned int path_length, environ_length, length, i;

	environ_length = 0;
	while (environ[environ_length] != NULL)
	{
		environ_length++;
	}
	environ_copy = copy_env(environ_length);

	length = strlen(name);
	i = 0;
	while (environ_copy[i] != NULL)
	{
		variable = environ_copy[i];
		compare = strncmp(name, variable, length);
		if (compare == 0)
		{
			value = strtok(variable, "=");
			value = strtok(NULL, "\n");
		if (value == NULL)
		{
			errors(4);
			exit(EXIT_FAILURE);
		}
		path_length = strlen(value);
			path = malloc(sizeof(char) * (path_length + 1));
		if (path == NULL)
		{
			errors(3);
				return NULL;
		}
		path = strcpy(path, value);
		free_dp(environ_copy, environ_length);
			return path;
		}
	i++;
	}
	return NULL;
}

/**
 * copy_env - copies environment variable
 * @environ_length: length of environment variable
 * Return: double pointer to copy environment variable
*/
char **copy_env(unsigned int environ_length)
{
	char **environ_copy;
	char *variable;
	unsigned int variable_length;
	unsigned int i;
	
	environ_copy = malloc(sizeof(char *) * (environ_length + 1));
	if (environ_copy == NULL)
	{
		errors(3);
		return NULL;
	}
	i = 0;
	while (i < environ_length)
	{
		variable = environ[i];
		variable_length = strlen(variable);

		environ_copy[i] = malloc(sizeof(char) * (variable_length + 1));
		if (environ_copy[i] == NULL)
		{
			errors(3);
			free_dp(environ_copy, i);
			return NULL;
		}
		memcpy(environ_copy[i], environ[i], variable_length + 1);
		i++;
	}
	environ_copy[i] = NULL;
	return environ_copy;
}
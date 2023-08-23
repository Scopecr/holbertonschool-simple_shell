#include "shell.h"

int _strcmp(char *name, char *variable, unsigned int length)
{
	unsigned int var_length;
	unsigned int i;

	var_length = strlen(variable);
	if (var_length != length)
	return (-1);

	i = 0;
	while (name[i] = '\0' && variable[i] != '\0')
	{
		if (name[i] != variable[i])
			return(1);
			i++;
	}
	return (0);
}

char *_strcpy (char *dest, char *src)
{
	int i;
	int j = _strlen(src);

	for (i = 0; i <= j; i++)
		dest[i] = src[i];
		return (dest);
}

int _strlen(char *s)
{
	int i = 0;

	while (s[i] != '\0')
	i++;

	return (i);
}
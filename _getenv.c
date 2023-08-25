#include "shell.h"

char *_getenv(const char *name)
{
    char **environ_copy;
    char *variable, *value;
    int compare;
    unsigned int environ_length, length, i;

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
            value = strchr(variable, '=') + 1; // Find the value part after '='
            return value;
        }
        i++;
    }
    return NULL;
}

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
        strcpy(environ_copy[i], environ[i]);
        i++;
    }
    environ_copy[i] = NULL;
    return environ_copy;
}

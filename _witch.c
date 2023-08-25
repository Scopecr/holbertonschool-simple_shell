#include "shell.h"

/**
 * _which - searches for a command in the PATH environment variable
 * @command: the command to search for
 * @fullpath: pointer to store the full path of the command (output)
 * @path: the PATH environment variable
 * Return: 1 if found, 0 if not found, -1 on error
 */
int _which(char *command, char **fullpath, char *path)
{
    unsigned int command_length, path_length;
    char path_copy[PATH_MAX];
    char *token;

    command_length = strlen(command);
    strncpy(path_copy, path, sizeof(path_copy) - 1);
    path_copy[sizeof(path_copy) - 1] = '\0';

    token = strtok(path_copy, ":");
    while (token != NULL)
    {
        path_length = strlen(token);
        *fullpath = (char *)malloc(path_length + command_length + 2);
        if (*fullpath == NULL)
        {
            errors(3);
            return -1;
        }
        strncpy(*fullpath, token, path_length);
        (*fullpath)[path_length] = '/';
        strncpy(*fullpath + path_length + 1, command, command_length);
        (*fullpath)[path_length + command_length + 1] = '\0';
        if (access(*fullpath, X_OK) == 0)
        {
            return 1; /* Found */
        }
        free(*fullpath);
        token = strtok(NULL, ":");
    }

    return 0; /* Not found */
}

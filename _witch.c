#include "shell.h"
#include <limits.h> /* Include for PATH_MAX */

char *_which(char *command, char *fullpath, char *path)
{
    unsigned int command_length, path_length;
    char path_copy[PATH_MAX];
    char *token, *result_fullpath;

    command_length = strlen(command);
    strncpy(path_copy, path, sizeof(path_copy) - 1);
    path_copy[sizeof(path_copy) - 1] = '\0';

    token = strtok(path_copy, ":");
    while (token != NULL)
    {
        path_length = strlen(token);
        result_fullpath = (char *)malloc(path_length + command_length + 2);
        if (result_fullpath == NULL)
        {
            errors(3);
            return NULL;
        }
        strncpy(result_fullpath, token, path_length);
        result_fullpath[path_length] = '/';
        strncpy(result_fullpath + path_length + 1, command, command_length);
        result_fullpath[path_length + command_length + 1] = '\0';
        if (access(result_fullpath, X_OK) == 0)
        {
            return result_fullpath; /* Return the valid fullpath */
        }
        free(result_fullpath);
        token = strtok(NULL, ":");
    }

    return NULL; /* Return NULL if command not found */
}


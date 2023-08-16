#ifndef SHELL_H
#define SHELL_H

/**
 * including std libraries
 */
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <errno.h>
#include <stddef.h>
#include <sys/stat.h>
#include <signal.h>

/**
 * structure to go trough arguments
*/

typedef struct *comm
{
char *comm;
int *comm;
};

#endif

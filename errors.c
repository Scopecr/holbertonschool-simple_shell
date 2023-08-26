#include "shell.h"
/**
 * errors - prints errors based on case
 * @error: error number associated with perror statement
 * Return: void
*/
void errors(int error)
{
	switch (error)
	{
		case 1:
				write(STDERR_FILENO, ERR_FORK, strlen(ERR_FORK));
				perror("Error");
				break;

		case 2:
				perror("Error");
				break;

		case 3:
				write(STDERR_FILENO, ERR_MALLOC, strlen(ERR_MALLOC));
				break;

		case 4:
				write(STDERR_FILENO, ERR_PATH, strlen(ERR_PATH));
				break;

		default:
				return;
	}
}

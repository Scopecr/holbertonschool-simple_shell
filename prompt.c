#include "shell.h"

/**
	* num_of_builtins - gets the number of builtin programs.
	* Return: size of them
	*/
int num_of_builtins(void)
{
	char *programs[] = {"cd", "help", "exit", "aheago", "nekoarc"};

	return (sizeof(programs) / sizeof(char *));
}

/**
	* cd_run - checks for the argument for cd.
	* @args: Arguments for the function.
	* Return: 1.
	*/
int cd_run(char **args)
{
	/** expects argument, else show error */
	if (args[1] == NULL)
	{
		fprintf(stderr, "lsh: expected an argument for \"cd\"\n");
	}
	else
	{
		if (chdir(args[1]) != 0)
		{
			perror("lsh");
		}
	}

	/** to keep the shell running */
	return (1);
}

/**
	* help_run - info for the shell.
	* @args: Arguments for the function.
	* Return: 1.
	*/
int help_run(char **args)
{
	char *programs[] = {"cd", "help", "exit", "aheago", "nekoarc"};
	int i = 0;
	(void)args;

	printf("Programs in the shell:\n");

	/** prints the programms of the shell */
	for (; i < num_of_builtins() ; i++)
	{
		printf("	%s\n", programs[i]);
	}

	/** to keep the shell running */
	return (1);
}

/**
	* exit_run - stops the shell
	* @args: Arguments for the function.
	* Return: 0.
	*/
int exit_run(char **args)
{
	(void)args;
	return (0);
}

/**
	* run_executer - run the shell commands or pass it to run_programm.
	* @args: Arguments for the function to use.
	* Return: 1 or 0
	*/
int run_executer(char **args)
{
	char *programs[] = {"cd", "help", "exit", "aheago", "nekoarc"};
	int i, (*functions[]) (char **) = {&cd_run, &help_run, &exit_run,
	&aheago_run, &nekoarc_run};

	/** if no function dont do anything */
	if (args[0] == NULL)
	{
		return (1);
	}

	/** checks if the function is in the shell */
	for (i = 0; i < num_of_builtins(); i++)
	{
		if (strcmp(args[0], programs[i]) == 0)
		{
			return ((*functions[i])(args));
		}
	}

	/** Else run it from the ones in pc with run_programm */
	return (run_programm(args));
}
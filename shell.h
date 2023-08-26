#ifndef _HEADER_
#define _HEADER_

#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define READLINE_Megabite 1024
#define SHELL_Token_64 64
#define TOKEN_Delimitator " "

int cd_run(char **args);
int help_run(char **args);
int exit_run(char **args);
int aheago_run(char **args);
int nekoarc_run(char **args);
int num_of_builtins(void);
int run_programm(char **args);
int run_executer(char **args);
char *run_line_reader();
char **shell_line_splitter(char *line);
void shell_loop_input(void);
int main(int argc, char **argv);
void noninteractive(void);

#endif
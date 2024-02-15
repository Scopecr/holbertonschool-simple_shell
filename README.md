# Shell
This shell is a simple command line prompt that takes the most basic of commands that are present
in the bash shell and runs them. This shell was build as a project for Holberton School San Juan

The shell works by being compiled using GCC ompailer, the shell can compile using the following command
`gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh`

## How do i run the program?
To run it use `./hsh`. The program will then ask you to enter any command so that it can be displayed on
![showcase] 
## Syntax
The shell works by command given by the user's input. You can use the following syntax for them:

`command name {arguments}`.
The shell executes a command after it is written by user using the command followed by the arguments

`cat shell.h` The above example takes in a command bu the user followed with the arguments.
In this case `shell.h`, which means cat file named `"shell.h"`.
`ls -l` The above example also uses a command but instead of taking an argument, it has options. In this
case `-l` which stands for list files long format (list all files including hidden ones).

For more information on cat, you can use the `man` command which will show a manual of the given command
or any command you wish to know more information. It contains system calls, libreries and other important files.

The shell also contains two builtins whitch are commands that are within the shell itself. The two builtins are `exit`
and `env`. You can use `help` command to know which builtins are provided bu the shell. The `help` command works similatly
to the manual where it provides further detail or information on given builtin.

## Compilation
All files will be compiled with the folling command: `gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c`

### List of commands:
 
- `cat` - prints and concatenates files to the standard output.
- `cp` - copies a file into another file.
- `grep` - helps to search for a file in a specific pattern.
- `less` - will let you go backwards and forward in the files.
- `ls` - will list all files and directories in current working directory.
- `mv` - helps to move one file into another or rename file.
- `pwd` - gives you the current working directory.

 ## Builtins
 There are two builtins programmed into the shell. Bellow is a description and use for each builtin.
 - `env` - The env command is a command that tells the shell program to siaplay al;l of the enviroment
			variables with their values. it is a way to access those values through the shell.
 
 - `exit` - command to leave the shell environment.

### Exiting command and the shell
To exit out of a command or process the user can use the `ctrl c` keys.`Control c` stops a process
and causes it to abort. The user can also utilize the command `ctrl D` which will just exit.
When the command `cntrl D` is used an exit status of 0 is given. Using exit, you can input its exit
status or is defaulted to the status of the last command. 

## Authors
Walter Carrion - https://github.com/Scopecr

Diego Gonzales - https://github.com/daggzu


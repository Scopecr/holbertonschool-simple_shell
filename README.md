#H6Shell
This shell is a simple command line prompt that takes the most basic of commands that are present
in the bash shell and runs them. This shell was build as a project for Holberton School San Juan

The shell works by being compiled using GCC ompailer, the shell can compile using the following command
`gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh`

#####How do i run the program?
To run it use `./hsh`. The program will then ask you to enter any command so that it can be displayed on

#####Syntax
The shell works by command given by the user's input. You can use the following syntax for them:

`command name {arguments}`.
The shell executes a command after it is written by user using the command followed by the arguments

`cat shell.h` The above example takes in a command bu the user followed with the arguments.
In this case `shell.h`, which means cat file named `"shell.h"`.
`ls -l` The above example also uses a command but instead of taking an argument, it has options. In this
case `-l` which stands for list files long format (list all files including hidden ones).




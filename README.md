                                          *** group project: 0x16. C - Simple Shell ***

                                          *** our team: mub2023 && richard579  ***


this project is a simple UNIX command interpreter and this shell should do:

this code should be compiled this way :

gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o {name of file}

1- a beautiful code that passes the Betty checks.


2- shell should:

a- Display a prompt and wait for the user to type a command. A command line always ends with a new line.

b- The prompt is displayed again each time a command has been executed.

c- The command lines are simple, no semicolons, no pipes, no redirections or any other advanced features
.

d- The command lines are made only of one word. No arguments will be passed to programs.

e- If an executable cannot be found, print an error message and display the prompt again.
Handle errors.

f- You have to handle the “end of file” condition (Ctrl+D).

3- Handle command lines with arguments

4- Handle the PATH
a- fork must not be called if the command doesn’t exist

5- Implement the exit built-in, that exits the shell

6- Implement the env built-in, that prints the current environment.

7- our getline function.

a- Use a buffer to read many chars at once and call the least possible the read system call

b- You will need to use static variables

c- we willnot use getline

8- we won't use strtok.

9- handle arguments for the built-in exit

10- Implement the setenv and unsetenv builtin commands

11- Implement the builtin command cd:

a- Changes the current directory of the process.

b- Command syntax: cd [DIRECTORY]

c- If no argument is given to cd the command must be interpreted like cd $HOME

d- You have to handle the command cd -

e- You have to update the environment variable PWD when you change directory.

12- Handle the commands separator ;

13- Handle the && and || shell logical operators.

14- Implement the alias builtin command.
a- Usage: alias [name[='value'] ...]

15- a- Handle variables replacement.

    b-Handle the $? variable

    c-Handle the $$ variable

16- Handle comments (#).

17- Usage: simple_shell [filename]

a- Your shell can take a file as a command line argument.

b- The file contains all the commands that your shell should run before exiting,

c- The file should contain one command per line.

d- In this mode, the shell should not print a prompt and should not read from stdin.

                                     *** our team: mub2023 && richard579  *** 

                                      thats all thanks for checking our project.

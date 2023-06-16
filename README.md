0x16. C - Simple Shell

In this project, we are tasked to come up with our own functional LINUX shell.
The shell should be able to execute similar commands as the linux inbuilt shell.
It should be able to:
i). Display a prompt and wait for the user to type a command.
ii). Display the prompt again after the command has been executed
iii). Execute simple command lines i.e, no semicolons, no pipes, no redirections or any other advanced features.
iv). Execute commandlines made of one word. No arguments
v). If an executable cannot be found, print an error message and display the prompt again.
vi). Handle errors
vii). Handle the “end of file” condition (Ctrl+D).

As the the project expands, our shell should be able to:
i). Handle command lines with arguments
ii). Handle the PATH
iii). fork must not be called if the command doesn’t exist
iv). Implement the exit built-in, that exits the shell
v). Doesn't handle any argument to the built-in exit
vi). Implement the env built-in, that prints the current environment
vii). Write your own getline function
viii).Handle arguments for the built-in exit
ix). Implement the setenv and unsetenv builtin commands
setenv:
        Initialize a new environment variable, or modify an existing one
        Command syntax: setenv VARIABLE VALUE
        Should print something on stderr on failure
unsetenv:
        Remove an environment variable
        Command syntax: unsetenv VARIABLE
        Should print something on stderr on failure
x). Implement the builtin command cd
xi). Handle the commands separator ;
xii). Handle the && and || shell logical operators
xiii). Implement the alias builtin command
xiv). Handle variables replacement
      Handle the $? variable
      Handle the $$ variable
xv). Handle comments (#)
xvi). Your shell can take a file as a command line argument
      The file contains all the commands that your shell should run before exiting
      The file should contain one command per line
      In this mode, the shell should not print a prompt and should not read from stdin

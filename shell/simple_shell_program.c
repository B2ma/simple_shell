#include "shell.h"

/**
* main - simple shell program that run shell commands. The program creates
* a child process when it executes. The getline system call is called to read
* input from stdin and store it in the buffer
* The input should be a path to an executable. This will allow for for
* execution of a specific executable regardless of its location in the
* file system
* @argc: argument count, represents the number of arguments passed to
* the program
* @argv: argument vector, used to acces individual commandline
* arguments using index
* @env: pointerto our defined environment variables
* Return: integer
*/

int main(int argc, char *argv[], char **env)
{
char *inputCmd = NULL, *prompt_string = "$";
size_t inputCmd_size = 0;
ssize_t bytes;
pid_t child;
bool piped = false;
struct stat statbuffer;

/*enter a while loop that will enable the program to loop
* until the exit command CTRL+D is entered
*/
while (1 && !piped)
{

/* check if the command is entered by piping or
* its entered through the terminal
*/
if (isatty(STDIN_FILENO) == 0)
piped = true;
/*print the prompt string "$" on the terminal*/
write(STDOUT_FILENO, prompt_string, 2);

/* Read data from the standard input*/
/* The getline function returns the number of characters
* read including the '\n' but excluding '\0'
*/
bytes = getline(&inputCmd, &inputCmd, stdin);
if (bytes == -1)
{
perrror("Error (getline)");
free(inputCmd);
exit(EXIT_FAILURE);
}

/* Replace newline character with a null terminator */
if (inputCmd[bytes - 1] == '\n')
inputCmd[bytes - 1] = '\0';

/* Create a child process and use it to execute the command.
* The reason for creating a child process is so that we can
* execute the external command in the child process while the
* parent process continues running and waits for the child
* process to complee. The child process is created using fork()*/

child = fork();

/*if it fails to create a child process*/
if (child == -1)
{
perror("Error (fork)");
exit(EXIT_FAILURE);
}
/* if a child process is created...*/
if (child == 0)
execute_cmd(buff, &statbuffer, env);

/* The parent process should wait for the child process
* to complete*/

if (waitpid(child, &wstatus, 0) == -1)
{
perror("Error (wait)");
exit(EXIT_FAILURE);
}
}
free(inputCmd);
return (0);
}

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

while (1 && !piped)
{
	if (isatty(STDIN_FILENO) == 0)
	piped = true;
	write(STDOUT_FILENO, prompt_string, 2);

	bytes = getline(&inputCmd, &inputCmd, stdin);
	if (bytes == -1)
	{
		perrror("Error (getline)");
		free(inputCmd);
		exit(EXIT_FAILURE);
	}

	if (inputCmd[bytes - 1] == '\n')
		inputCmd[bytes - 1] = '\0';
	child = fork();
	if (child == -1)
	{
		perror("Error (fork)");
		exit(EXIT_FAILURE);
	}
	if (child == 0)
		execute_cmd(buff, &statbuffer, env);
	if (waitpid(child, &wstatus, 0) == -1)
	{
		perror("Error (wait)");
		exit(EXIT_FAILURE);
	}
}
free(inputCmd);
return (0);
}

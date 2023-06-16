#include "main.h"

/**
  * _execute_cmd - Executes the command in child process
  * @args: the number of arguments
  * @statbuf: pointer to file information buffer
  * @envp: pointer the strings in environs
  * Return: 0, success
  */
int _execute_cmd(char *args, struct stat *statbuf, char **envp)
{
	int argc;
	char **argv;
	char *exe;

	agv = separateString(args, " ", &argc);
	if (!file_exists(argv[0], statbuf))
	{
		perror("Error (file_exists)");
		exit(EXIT_FAILURE);
	}
	execve(argv[0], argv, envp);
	perror("Error (execev)");
	exit(EXIT_FAILURE);
}

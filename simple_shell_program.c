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
*
* Return: the last executed command
*/

int main(int argc, char *argv[])
{
int rtn_value = 0;
char *newLine = "\n";
int return_n;
int *execRet = &return_n;
char *prompt_string = "$ ";

cmdName = argv[0];
history = 1;
aliases = NULL;
signal(SIGINT, print_prompt);

*execRet = 0;
envn = envCopy();
if (!envn)
exit(-100);

if (argc != 1)
{
rtn_value = process_cmd(argv[1], execRet);
envFree();
freeAliasList(aliases);
return (*execRet);
}

if (!isatty(STDIN_FILENO))
{
while (rtn_value != EOF_CUSTOM && rtn_value != TERMINATE)
rtn_value = argsHandler(execRet);
envFree();
freeAliasList(aliases);
return (*execRet);
}

while (1)
{
write(STDOUT_FILENO, prompt_string, 2);
rtn_value = argsHandler(execRet);
if (rtn_value == EOF_CUSTOM || rtn_value == TERMINATE)
{
if (rtn_value == EOF_CUSTOM)
write(STDOUT_FILENO, newLine, 1);
envFree();
freeAliasList(aliases);
exit(*execRet);
}
}

envFree();
freeAliasList(aliases);
return (*execRet);
}

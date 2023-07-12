#include "shell.h"
/**
* main - simple shell program that run shell commands.
* @argc: argument count
* @argv: argument vector
* Return: the last executed command
*/
int main(int argc, char *argv[])
{
int rtn_value = 0, return_n, *execRet = &return_n;
char *newLine = "\n", *prompt_string = "$ ";

aliases = NULL;
signal(SIGINT, print_prompt);
*execRet = 0;
environ = envCopy();
if (!environ)
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

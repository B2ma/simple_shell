#include "shell.h"

/**
* print_prompt - it prints a new prompt when called
* @sgn: signal prompt
*/
void print_prompt(int sgn)
{
char *prompted = "\n$ ";

(void)sgn;
signal(SIGINT, print_prompt);
write(STDIN_FILENO, prompted, 3);
}
/**
* execute_cmd - a function that xecutes a cmd in a child process.
* @args: An array of arguments.
* @first: A double pointer to the beginning of args.
* Return: corresponding error code O/w - last execute_cmd cmd.
*/
int execute_cmd(char **args, char **first)
{
pid_t child_pid;
int status, flag = 0, rtn_value = 0;
char *cmd = args[0];
alias_t *aliases = NULL;

if (cmd[0] != '/' && cmd[0] != '.')
{
flag = 1, cmd = locate_cmd(cmd);
}
if (!cmd || (access(cmd, F_OK) == -1))
{
if (errno == EACCES)
rtn_value = (write_error(args, 126));
else
rtn_value = (write_error(args, 127));
}
else
{
child_pid = fork();
if (child_pid == -1)
{
if (flag)
free(cmd), perror("Error child:");
return (1);
}
if (child_pid == 0)
{
execve(cmd, args, environ);
if (errno == EACCES)
rtn_value = (write_error(args, 126));
envFree(), argsFree(args, first), freeAliasList(aliases), _exit(rtn_value);
}
else
{
wait(&status), rtn_value = WEXITSTATUS(status);
}
}
if (flag)
free(cmd);
return (rtn_value);
}

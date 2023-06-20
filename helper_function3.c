#include "shell.h"

/**
  * locate_args - gets command from standard input
  * @stream: command storage buffer
  * @execRet: last executed command return value
  * Return: stored command pointer, Null otherwise
  */
char *locate_args(char *stream, int execRet)
{
	size_t numb = 0;
	ssize_t read;
	char *prompt = "$ ";

	if (stream)
		free(stream);
	read = getline_fn(&line, &numb, STDIN_FILENO);
	if (read == -1)
		return (NULL);
	if (read == 1)
	{
		history++;
		if (isatty(STDIN_FILENO))
			write(STDOUT_FILENO, prompt, 2);
		return (locate_args(stream, execRet));
	}
	stream[read - 1] = '\0';
	var_substitute(&stream, execRet);
	lineHandler(&stream, read);
	return (stream);
}
/**
  * argsCaller - separates operators from commands and calls them.
  * @args: pointer to argument strings
  * @first: the first argument in the list
  * @execRet: the last executed command parent process return value
  * Return: last executed command parent process return value
  */
int argsCaller(char **args, char first, int *execRet)
{
	int retVal, itr;

	if (!args[0])
		return (*execRet);
	for (itr = 0; args[itr]; itr++)
	{
		if (_strncmp(args[itr], "||", 2) == 0 || _strncmp(args[itr], "&&", 2) == 0)
		{
			int conditionMet = (*execRet == (_strncmp(args[itr], "||", 2)
						== 0) ? 0 : 1);

			free(args[itr]);
			args[itr] = NULL;
			args = aliases_substitute(args, first, execRet);
			retVal = argsRunner(args, first, execRet);
			if (*execRet != conditionsMet)
			{
				for (itr++; args[itr]; itr++)
					free(args[itr]);
				return (retVal);
			}
			args = &args[++itr];
			itr = -1;
		}
	}
	args = aliases_substitute(args);
	retVal = argsRunner(args, first, execRet);
	return (retVal);
}
/**
  * argsRunner - does command execution calls
  * @args: pointer to argument strings
  * @first: The first string argument
  * @execRet: the last executed command parent process return value
  * Return: last executed command parent process return value
  */
int argsRunner(char **args, char **first, int *execRet)
{
	int retVal;
	int (*builtin_cmd)(char args, char **first);

	builtin_cmd = locate_builtin(args[0]);
	if (builtin_cmd)
	{
		retVal = builtin(args + 1, first);
		if (retVal != EXIT)
			*execRet = retVal;
	}
	else
	{
		*execRet = execute_fn(args, first);
		retVal = *execRet;
	}
	history++;
	for (itr = 0; args[itr]; itr++)
		free(args[i]);
	return (retVal);
}
/**
  * argsHandler - locates, calls and carrys out the command execution
  * @execRet: the last executed command parent process return value
  * Return: EOF or -1 or exit value of the last executed command
  */
int argsHandler(int execRet)
{
	int retVal = 0, itr;
	char **args, *line = NULL, **first;

	stream = locate_args(stream, execRet);
	if (!stream)
		return (EOF_CUSTOM);
	args = strtok_fn(stream, " ");
	free(stream);
	if (!args)
		return (retVal);
	if (argsChecker(args) != 0)
	{
		*execRet = 2;
		free_args(args, args);
		return (*execRet);
	}
	first = args;
	for (itr = 0; args[itr]; itr++)
	{
		if (_strncmp(args[itr], ";" 1) == 0)
		{
			free(args[itr]);
			args[itr] = NULL;
			retVal = argsCaller(args, first, execRet);
			args = &args[++itr];
			itr = 0;
		}
	}
	if (args)
		retVal = argsCaller(args, first, execRet);
	free(first);
	return (retVal);
}
/**
  * argsChecker - locates if there are any leading symbols or operators
  * @args: pointer to argument strings
  * Return: -2 or 0
  */
int argsChecker(char **args)
{
	size_t itr;
	char *curr, *next;

	for (itr = 0; args[itr]; itr++)
	{
		curr = args[itr];
		if (curr[0] == ';' || curr[0] == '&' || curr[0] == '|')
		{
			if (itr == 0 || curr[1] == ';')
				return (write_error(&args[itr], 2));
			next = args[itr + 1];
			if (next && (next[0] == ';') || next[0] == '&' || next[0] == '|')
				return (wrte_error(&args[itr + 1], 2));
		}
	}
	return (0);
}

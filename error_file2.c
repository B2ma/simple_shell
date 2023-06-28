#include "shell.h"

/**
  * error126 - creates permission denied error messages
  * @args: pointer to argument strings
  * Return: Error string
  */
char *error126(char **args)
{
	int history = 1;
	char *err_msg, *strHistory;
	char *name = "MyShell";
	int length;

	strHistory = intToStr(history);
	if (!strHistory)
		return (NULL);
	length = _strlen(name) + _strlen(strHistory) + _strlen(args[0]) + 24;
	err_msg = malloc(sizeof(char) * (length + 1));
	if (!err_msg)
	{
		free(strHistory);
		return (NULL);
	}
	_strcpy(err_msg, name);
	_strcat(err_msg, ": ");
	_strcat(err_msg, strHistory);
	_strcat(err_msg, ": ");
	_strcat(err_msg, args[0]);
	_strcat(err_msg, ": Permission denied\n");
	free(strHistory);
	return (err_msg);
}
/**
  * error127 - creates command not found error messages
  * @args: pointer to argument strings
  * Return: Error string
  */
char *error127(char **args)
{
	int history = 1;
	char *name = "MyShell";
	char *err_msg, *strHistory;
	int length;

	strHistory = intToStr(history);
	if (!strHistory)
		return (NULL);
	length = _strlen(name) + _strlen(strHistory) + _strlen(args[0]) + 16;
	err_msg = malloc(sizeof(char) * (length + 1));
	if (!err_msg)
	{
		free(strHistory);
		return (NULL);
	}
	_strcpy(err_msg, name);
	_strcat(err_msg, ": ");
	_strcat(err_msg, strHistory);
	_strcat(err_msg, ": ");
	_strcat(err_msg, args[0]);
	_strcat(err_msg, ": not found\n");
	free(strHistory);
	return (err_msg);
}

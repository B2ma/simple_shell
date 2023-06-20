#include "shell.h"

/**
  * error126 - creates permission denied error messages
  * @args: pointer to argument strings
  * Return: Error string
  */
char *error126(char **args)
{
	char *err_msg, *strHistory;
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
	_strcat(err_msg, hist_str);
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
	char *err_msg, *strHistory;
	int length;

	strHistory = intToStr(history);
	if (!strHistory)
		return (NULL);
	length = _strlen(name) + _strlen(strHistory) + _strlen(args[0]) + 16;
	err_msg = malloc(sizeof(char) * (length + 1));
	err_msg = malloc(sizeof(char) * (length + 1));
	if (!err_msg)
	{
		free(strHistory);
		return (NULL);
	}
	_strcpy(err_msg, name);
	_strcat(err_msg, ": ");
	_strcat(err_msg, hist_str);
	_strcat(err_msg, ": ");
	_strcat(err_msg, args[0]);
	_strcat(err_msg, ": not found\n");
	free(strHistory);
	return (err_msg);
}

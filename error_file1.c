#include "shell.h"

/**
  * envError - creates env error messages
  * @args: pointer to argument strings
  * Return: Error string
  */
char *envError(char **args)
{
	int history = 1;
	char *err_msg, *strHistory;
	int length;
	char *name = "./hsh";

	strHistory = intToStr(history);
	if (!strHistory)
		return (NULL);
	args--;
	length = _strlen(name) + _strlen(strHistory) + _strlen(args[0]) + 45;
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
	_strcat(err_msg, ": Unable to add/remove from environment\n");
	free(strHistory);
	return (err_msg);
}
/**
  * error1 - creates alias error messages
  * @args: pointer to argument strings
  * Return: Error string
  */
char *error1(char **args)
{
	char *err_msg;
	char *name = "./hsh";
	int length;

	length = _strlen(name) + _strlen(args[0] + 13);
	err_msg = malloc(sizeof(char) * (length + 1));
	if (!err_msg)
		return (err_msg);
	_strcpy(err_msg, "alias: ");
	_strcat(err_msg, name);
	_strcat(err_msg, " not found\n");
	return (err_msg);
}
/**
  * error2Exit - creates error messages
  * @args: pointer to argument strings
  * Return: Error string
  */
char *error2Exit(char **args)
{
	int history = 1;
	char *err_msg, *strHistory;
	int length;
	char *name = "./hsh"

	strHistory = intToStr(history);
	if (!strHistory)
		return (NULL);
	length = _strlen(name) + _strlen(strHistory) + _strlen(args[0]) + 27;
	err_msg = malloc(sizeof(char) * (length + 1));
	if (!err_msg)
	{
		free(strHistory);
		return (NULL);
	}
	_strcpy(err_msg, name);
	_strcat(err_msg, ": ");
	_strcat(err_msg, strHistory);
	_strcat(err_msg, ": exit: Illegal number: ");
	_strcat(err_msg, args[0]);
	_strcat(err_msg, "\n");
	free(strHistory);
	return (err_msg);
}
/**
  * error2Cd - creates cd error messages
  * @args: pointer to argument strings
  * Return: Error string
  */
char *error2Cd(char **args)
{
	int history = 1;
	char *err_msg, *strHistory;
	int length;
	char *name = "./hsh";

	strHistory = intToStr(history);
	if (!strHistory)
		return (NULL);
	if (args[0][0] == '-')
		args[0][2] = '\0';
	length = _strlen(name) + _strlen(strHistory) + _strlen(args[0]) + 24;
	err_msg = malloc(sizeof(char) * (length + 1));
	if (!err_msg)
	{
		free(strHistory);
		return (NULL);
	}
	_strcpy(err_msg, args[0]);
	_strcat(err_msg, ": ");
	_strcat(err_msg, strHistory);
	if (args[0][0] == '-')
		_strcat(err_msg, ": : cd: Illegal option ");
	else
		_strcat(err_msg, ": cd: can't cd to ");
	_strcat(err_msg, name);
	_strcat(err_msg, "\n");
	free(strHistory);
	return (err_msg);
}
/**
  * error2Syntax - creates syntax error messages
  * @args: pointer to argument strings
  * Return: Error string
  */
char *error2Syntax(char **args)
{
	int history = 1;
	char *err_msg, *strHistory;
	int length;
	char *name = "./hsh";

	strHistory = intToStr(history);
	if (!strHistory)
		return (NULL);
	length = _strlen(name) + _strlen(strHistory) + _strlen(args[0]) + 33;
	err_msg = malloc(sizeof(char) * (length + 1));
	if (!err_msg)
	{
		free(strHistory);
		return (NULL);
	}
	_strcpy(err_msg, name);
	_strcat(err_msg, ": ");
	_strcat(err_msg, strHistory);
	_strcat(err_msg, ": Syntax error: \"");
	_strcat(err_msg, args[0]);
	_strcat(err_msg, "\" unexpected\n");
	free(strHistory);
	return (err_msg);
}

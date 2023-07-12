#include "shell.h"

/**
 * error_opening_fn - a function that prints cant open error
 * if file doesnt exist.
 * @file_path: the path to file that cant be opened
 * Return: 127.
 */

int error_opening_fn(char *file_path)
{
	int length;
	char *error;
	char *history_str;
	int history = 0;
	char *name = "./hsh";

	history_str = intToStr(history);
	if (!history_str)
		return (127);

	length = _strlen(name) + _strlen(history_str) + _strlen(file_path) + 16;
	error = malloc(sizeof(char) * (length + 1));
	if (!error)
	{
		free(history_str);
		return (127);
	}

	_strcpy(error, name);
	_strcat(error, ": ");
	_strcat(error, history_str);
	_strcat(error, ": Can't open ");
	_strcat(error, file_path);
	_strcat(error, "\n");

	free(history_str);
	write(STDERR_FILENO, error, length);
	free(error);
	return (127);
}

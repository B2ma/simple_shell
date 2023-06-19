#include "shell.h"

/**
 * process_cmd - a function that attempts to run commands
 * within a file.
 * @file_path: Path to the file.
 * @execRet: this is the last executed command return value.
 * Return: 127 if the file couldnt be opened, -1 if memory
 * allocation fails
 * otherwise the return value of the last command ran.
 */
int process_cmd(char *file_path, int *execRet)
{
	char buffer[120];
	ssize_t file, bytes_read, m;
	unsigned int lineLength = 0;
	int rtn_value;
	char *line, **args, **front;
	unsigned int oldSize = 120;

	history = 0;
	file = open(file_path, O_RDONLY);
	if (file == -1)
	{
		*execRet = error_opening_fn(file_path);
		return (*execRet);
	}
	line = malloc(sizeof(char) * oldSize);
	if (!line)
		return (-1);
	do {
		bytes_read = read(file, buffer, 119);
		if (bytes_read == 0 && lineLength == 0)
			return (*execRet);
		buffer[bytes_read] = '\0';
		lineLength += bytes_read;
		line = _realloc(line, oldSize, lineLength);
		_strcat(line, buffer);
		oldSize = lineLength;
	} while (bytes_read);
	for (m = 0; line[m] == '\n'; m++)
		line[m] = ' ';
	for (; m < lineLength; m++)
	{
		if (line[m] == '\n')
		{
			line[m] = ';';
			for (m += 1; m < lineLength && line[m] == '\n'; m++)
				line[m] = ' ';
		}
	}
	var_substitute(&line, execRet);
	lineHandler(&line, lineLength);
	args = _strtok(line, " ");
	free(line);
	if (!args)
		return (0);
	if (argschecker(args) != 0)
	{
		*execRet = 2;
		argsFree(args, args);
		return (*execRet);
	}
	first = args;

	for (m = 0; args[m]; m++)
	{
		if (_strncmp(args[m], ";", 1) == 0)
		{
			free(args[m]);
			args[m] = NULL;
			rtn_value = argsCaller(args, first, execRet);
			args = &args[++m];
			m = 0;
		}
	}

	rtn_value = argsCaller(args, first, execRet);

	free(first);
	return (rtn_value);
}

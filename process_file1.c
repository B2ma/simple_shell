#include "shell.h"
/**
 * process_cmd - runs commands within a file.
 * @file_path: Path to the file.
 * @execRet: this is the last executed command return value.
 * Return: 127 if the file couldnt be opened, -1 if memory
 * allocation fails or last command ran.
 */
int process_cmd(char *file_path, int *execRet)
{
	char buffer[120], *stream, **args, **first;
	ssize_t file, bytes_read, m;
	unsigned int lineLength = 0, oldSize = 120;
	int rtn_value;

	file = open(file_path, O_RDONLY);
	if (file == -1)
	{
		*execRet = error_opening_fn(file_path);
		return (*execRet);
	}
	stream = malloc(sizeof(char) * oldSize);
	if (!stream)
		return (-1);
	do {
		bytes_read = read(file, buffer, 119);
		if (bytes_read == 0 && lineLength == 0)
			return (*execRet);
		buffer[bytes_read] = '\0', lineLength += bytes_read;
		stream = _realloc(stream, oldSize, lineLength);
		_strcat(stream, buffer), oldSize = lineLength;
	} while (bytes_read);
	for (m = 0; stream[m] == '\n'; m++)
		stream[m] = ' ';
	for (; m < lineLength; m++)
	{
		if (stream[m] == '\n')
		{
			stream[m] = ';';
			for (m += 1; m < lineLength && stream[m] == '\n'; m++)
				stream[m] = ' ';
		}
	}
	var_substitute(&stream, execRet), lineHandler(&stream, lineLength);
	args = strtok_fn(stream, " "), free(stream);
	if (!args)
		return (0);
	if (argsChecker(args) != 0)
	{
		*execRet = 2, argsFree(args, args);
		return (*execRet);
	}
	first = args;
	for (m = 0; args[m]; m++)
	{
		if (_strncmp(args[m], ";", 1) == 0)
		{
			free(args[m]), args[m] = NULL;
			rtn_value = argsCaller(args, first, execRet), args = &args[++m], m = 0;
		}
	}
	rtn_value = argsCaller(args, first, execRet), argsFree(args, first);
	return (rtn_value);
}

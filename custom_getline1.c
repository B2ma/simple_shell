#include "shell.h"
/**
 * getline_fn - a function that reads data_input from a stream.
 * @lineptr: used to store the read data_input data
 * @n:its the size of the lineptr
 * @stream: The stream to read from.
 * Return: bytes read.
 */
ssize_t getline_fn(char **lineptr, size_t *n, FILE *stream)
{
	char character = 'x', *buffer;
	static ssize_t data_input;
	int read_data;
	ssize_t rtn_value;

	if (data_input == 0)
		fflush(stream);
	else
		return (-1);
	data_input = 0;
	buffer = malloc(sizeof(char) * 120);
	if (!buffer)
		return (-1);
	while (character != '\n')
	{
		read_data = read(STDIN_FILENO, &character, 1);
		if (read_data == -1 || (read_data == 0 && data_input == 0))
		{
			free(buffer);
			return (-1);
		}
		if (read_data == 0 && data_input != 0)
		{
			data_input++;
			break;
		}

		if (data_input >= 120)
			buffer = _realloc(buffer, data_input, data_input + 1);
		buffer[data_input] = character;
		data_input++;
	}
	buffer[data_input] = '\0';
	reassign_fn(lineptr, n, buffer, data_input);
	rtn_value = data_input;
	if (read_data != 0)
		data_input = 0;
	return (rtn_value);
}

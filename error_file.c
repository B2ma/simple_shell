#include "shell.h"

/**
* length_of_number - a function that returns the length of a number.
* @number: the number whose length is to be returned.
* Return: length of number.
*/
int length_of_number(int number)
{
	int length = 1;
	unsigned int first_number;


	if (number < 0)
	{
		length++;
		first_number = number * -1;
	}
	else
	{
		first_number = number;
	}
	while (first_number > 9)
	{
		length++;
		first_number /= 10;
	}
	return (length);
}

/**
  * write_error - writes error message to stderr
  * @args: pointer to array of atring arguments
  * @num: value of error
  * Return: error Value
  */
int write_error(char **args, int num)
{
	char *err_info;

	switch (num)
	{
		case -1:
			err_info = envError(args);
			break;
		case 1:
			err_info = error1(args);
			break;
		case 2:
			if (*(args[0]) == 'e')
				err_info = error2Exit(++args);
			else if (args[0][0] == ';' || args[0][0] == '&' || args[0][0] == '|')
				err_info = error2Syntax(args);
			else
				err_info = error2Cd(args);
			break;
		case 126:
			err_info = error126(args);
			break;
		case 127:
			err_info = error127(args);
			break;
	}
	write(STDERR_FILENO, err_info, _strlen(err_info));
	if (err_info)
		free(err_info);
	return (num);
}
/**
* intToStr - a function that converts an integer to a string
* @number: the integer to be converted.
* Return: number
*/
char *intToStr(int number)
{
	unsigned int first_number;
	char *buffer;
	int length = length_of_number(number);

	buffer = malloc(sizeof(char) * (length + 1));
	if (!buffer)
		return (NULL);

	buffer[length] = '\0';
	if (number < 0)
	{
		first_number = number * -1;
		buffer[0] = '-';
	}
	else
	{
	first_number = number;
	}

	length--;
	do {
		buffer[length] = (first_number % 10) + '0';
		first_number /= 10;
		length--;
	} while (first_number > 0);

return (buffer);
}


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
 * intToStr - a function that converts an integer to a string.
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


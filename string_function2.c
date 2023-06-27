#include "shell.h"

/**
 * _strlen -a function that finds and returns
 * the str_length of a string.
 * @s: a pointer to the string characters
 * Return: The str_length of the string.
 */
int _strlen(const char *s)
{
	int str_length = 0;

	if (s == NULL)
		return(0);
	while (s[str_length] != '\0')
		str_length++;
	return (str_length);
}

/**
 * _strcpy - a function that copies the string pointed to by src,
 * including the terminating null byte, to the buffer pointed by des.
 * @dest: Pointer to the destination of copied string.
 * @src: Pointer to the src of the source string.
 * Return: Pointer to dest.
 */
char *_strcpy(char *dest, const char *src)
{
	size_t m;

	for (m = 0; src[m] != '\0'; m++)
		dest[m] = src[m];
	dest[m] = '\0';
	return (dest);
}

/**
 * _strcat - a function that concantenates two strings.
 * @dest: Pointer to destination string.
 * @src: Pointer to source string.
 * Return: Pointer to destination string.
 */
char *_strcat(char *dest, const char *src)
{
	char *temporary_dest;
	const char *temporary_src;

	temporary_dest = dest;
	temporary_src =  src;

	while (*temporary_dest != '\0')
	{
		temporary_dest++;
	}

	while (*temporary_src != '\0')
	{
		*temporary_dest++ = *temporary_src++;
	}
	*temporary_dest = '\0';
	return (dest);
}

/**
 * _strncat - function that concantenates two strings where n number
 * of bytes are copied from source.
 * @dest: Pointer to destination string.
 * @src: Pointer to source string.
 * @n: n bytes to copy from src.
 * Return: Pointer to destination string.
 */
char *_strncat(char *dest, const char *src, size_t n)
{
	size_t dest_length = _strlen(dest);
	size_t m;

	for (m = 0; m < n && src[m] != '\0'; m++)
		dest[dest_length + m] = src[m];
	dest[dest_length + m] = '\0';

	return (dest);
}

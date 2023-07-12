#include "shell.h"

/**
 * _strchr - a function that finds a character in a string.
 * @s: The string to be searched.
 * @c: The character to be located.
 * Return: a pointer to the first character if found or NULL
 * if no character is found
 */
char *_strchr(char *s, char c)
{
	int position;

	for (position = 0; s[position]; position++)
	{
		if (s[position] == c)
			return (s + position);
	}

	return (NULL);
}

/**
 * _strspn - a function that gets the length of a
 * prefix substring.
 * @s: The string to be searched.
 * @accept: The prefix to be measured.
 * Return: The number of bytes in the string which
 * consist only of bytes from accept.
 */
int _strspn(char *s, char *accept)
{
	int bytes = 0;
	int position;

	while (*s)
	{
		for (position = 0; accept[position]; position++)
		{
			if (*s == accept[position])
			{
				bytes++;
				break;
			}
		}
		s++;
	}
	return (bytes);
}

/**
 * _strcmp - a function that compares two strings.
 * @s1: The first string to be compared.
 * @s2: The second string to be compared.
 *
 * Return: if s1 > s2 return the difference, 0 if s1 = s2,
 * negative byte difference if s1 < s2
 */
int _strcmp(char *s1, char *s2)
{
	while (*s1 && *s2 && *s1 == *s2)
	{
		s1++;
		s2++;
	}

	if (*s1 != *s2)
		return (*s1 - *s2);

	return (0);
}

/**
 * _strncmp - a function that compares two strings.
 * @s1: Pointer to the first string.
 * @s2: Pointer to the second string.
 * @n: The first n bytes of the strings to compare.
 * Return: a negative value if s1 < s2.
 * 0 if s1 =  s2
 * a postive value if s1 > s2.
 */
int _strncmp(const char *s1, const char *s2, size_t n)
{
	size_t m;

	for (m = 0; s1[m] && s2[m] && m < n; m++)
	{
		if (s1[m] > s2[m])
			return (s1[m] - s2[m]);
		else if (s1[m] < s2[m])
			return (s1[m] - s2[m]);
	}
	if (m == n)
		return (0);
	else
		return (-15);
}

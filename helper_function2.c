#include "shell.h"

/**
 * lineHandler - a function that divides a line read from stdin.
 * @line: A pointer to the read line.
 * @read: The length of line.
 * Return: nothing
 * Description: Spaces are inserted to separate ";", "||", and "&&".
 *              Replaces "#" with '\0'.
 */
void lineHandler(char **line, ssize_t read)
{
	ssize_t newLength;
	char *oldLine, *newLine;
	size_t m, n;
	char prev, present, new;

	newLength = get_newLength(*line);
	if (newLength == read - 1)
		return;
	newLine = malloc(newLength + 1);
	if (!newLine)
		return;
	n = 0;
	oldLine = *line;
	for (m = 0; oldLine[m]; m++)
	{
		present = oldLine[m];
		new = oldLine[m + 1];
		if (m != 0)
		{
			prev = oldLine[m - 1];
			if (present == ';')
			{
				if (new == ';' && prev != ' ' && prev != ';')
				{
					newLine[n++] = ' ';
					newLine[n++] = ';';
					continue;
				}
				else if (prev == ';' && new != ' ')
				{
					newLine[n++] = ';';
					newLine[n++] = ' ';
					continue;
				}
				if (prev != ' ')
					newLine[j++] = ' ';
				newLine[n++] = ';';
				if (new != ' ')
					newLine[n++] = ' ';
				continue;
			}
			else if (present == '&')
			{
				if (new == '&' && prev != ' ')
					newLine[n++] = ' ';
				else if (prev == '&' && new != ' ')
				{
					newLine[n++] = '&';
					newLine[n++] = ' ';
					continue;
				}
			}
			else if (present == '|')
			{
				if (new == '|' && prev != ' ')
					newLine[n++]  = ' ';
				else if (prev == '|' && new != ' ')
				{
					newLine[n++] = '|';
					newLine[n++] = ' ';
					continue;
				}
			}
		}
		else if (present == ';')
		{
			if (m != 0 && oldLine[m - 1] != ' ')
				newLine[n++] = ' ';
			newLine[n++] = ';';
			if (new != ' ' && new != ';')
				newLine[n++] = ' ';
			continue;
		}
		newLine[n++] = oldLine[m];
	}
	newLine[n] = '\0';

	free(*line);
	*line = newLine;
}

#include "shell.h"

/**
 * get_newLength - a function that gets the new line size. The line
 * is divided by ";", "||", "&&&", or "#".
 * @line: the line to be checked
 * Return: size of new line
 * Description:the function cuts short lines containing '#'
 * comments with '\0'.
 */

ssize_t get_newLength(char *line)
{
	size_t m;
	char present, new;
	ssize_t newLength = 0;

	for (m = 0; line[m]; m++)
	{
		present = line[m];
		new = line[m + 1];
		if (present == '#')
		{
			if (m == 0 || line[m - 1] == ' ')
			{
				line[m] = '\0';
				break;
			}
		}
		else if (m != 0)
		{
			if (present == ';')
			{
				if (new == ';' && line[m - 1] != ' ' && line[m - 1] != ';')
				{
					newLength += 2;
					continue;
				}
				else if (line[m - 1] == ';' && new != ' ')
				{
					newLength += 2;
					continue;
				}
				if (line[m - 1] != ' ')
					newLength++;
				if (new != ' ')
					newLength++;
			}
			else
				check_for_ops(&line[m], &newLength);
		}
		else if (present == ';')
		{
			if (m != 0 && line[m - 1] != ' ')
				newLength++;
			if (new != ' ' && new != ';')
				newLength++;
		}
		newLength++;
	}
	return (newLength);
}
/**
 * check_for_ops - a function that checks a line for
 * logical operators "||" or "&&".
 * @line:a line pointer to be checked for logical operators
 * @newLength: Pointer to newLength in get_newLength function.
 */
void check_for_ops(char *line, ssize_t *newLength)
{
	char prev, present, new;

	prev = *(line - 1);
	present = *line;
	new = *(line + 1);

	if (present == '&')
	{
		if (new == '&' && prev != ' ')
			(*newLength)++;
		else if (prev == '&' && new != ' ')
			(*newLength)++;
	}
	else if (present == '|')
	{
		if (new == '|' && prev != ' ')
			(*newLength)++;
		else if (prev == '|' && new != ' ')
			(*newLength)++;
	}
}

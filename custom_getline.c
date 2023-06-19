#include "shell.h"

/**
 * _realloc - a function that reallocates memory.
 * @ptr: pointer to previous memory location
 * @old_size: The size in bytes of the allocated space for ptr.
 * @new_size: The size in bytes for the new memory block.
 * Return: If new_size == old_size - ptr,
 * if new_size == 0 and ptr is not NULL - NULL.
 * otherwise - a pointer to the reallocated memory block.
 */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	char *temp, *new_node;
	void *memory;
	unsigned int index;

	if (new_size == old_size)
		return (ptr);

	if (ptr == NULL)
	{
		memory = malloc(new_size);
		if (memory == NULL)
			return (NULL);

		return (memory);
	}

	if (new_size == 0 && ptr != NULL)
	{
		free(ptr);
		return (NULL);
	}

	temp = ptr;
	memory = malloc(sizeof(*temp) * new_size);
	if (memory == NULL)
	{
		free(ptr);
		return (NULL);
	}

	new_node = memory;

	for (index = 0; index < old_size && index < new_size; index++)
		new_node[index] = *temp++;

	free(ptr);
	return (memory);
}

/**
 * assign_lineptr - a function that reassigns the
 * linepointer variable for getline_fn.
 * @lineptr:  stores an input string.
 * @n: The size of linepointer
 * @buffer: The string to assign to lineptr.
 * @b: The size of buffer.
 * Return: nothing
 */
void assign_lineptr(char **lineptr, size_t *n, char *buffer, size_t b)
{
	if (*lineptr == NULL)
	{
		if (b > 120)
			*n = b;
		else
			*n = 120;
		*lineptr = buffer;
	}
	else if (*n < b)
	{
		if (b > 120)
			*n = b;
		else
			*n = 120;
		*lineptr = buffer;
	}
	else
	{
		_strcpy(*lineptr, buffer);
		free(buffer);
	}
}

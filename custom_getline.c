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
* reassign_fn - a function that reassigns the
* linepointer variable for getline_fn.
* @str_buff:  stores an input string.
* @p_size: The size of linepointer
* @newStr: The string to assign to str_buff.
* @b_size: The size of new_str.
* Return: nothing
*/
void reassign_fn(char **str_buff, size_t *p_size, char *newStr, size_t b_size)
{
if (*str_buff == NULL)
{
if (b_size > 120)
*p_size = b_size;
else
*p_size = 120;
*str_buff = newStr;
}
else if (*p_size < b_size)
{
if (b_size > 120)
*p_size = b_size;
else
*p_size = 120;
*str_buff = newStr;
}
else
{
_strcpy(*str_buff, newStr);
free(newStr);
}
}

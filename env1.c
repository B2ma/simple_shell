#include "shell.h"

/**
* envFree - a function that is used to free
* the copied environment variable.
* Return: nothing
*/
void envFree(void)
{
int index;

for (index = 0; environ[index]; index++)
free(environ[index]);
free(environ);
}

/**
* locate_env - a function used to get an
* environmental variable from the PATH.
* @var: The environmental variable to get.
* Return: NULL, If the environmental variable is absent
* Otherwise, a pointer to the environmental variable.
*/
char **locate_env(const char *var)
{
int index;
int length;

length = _strlen(var);
for (index = 0; environ[index]; index++)
{
if (_strncmp(var, environ[index], length) == 0)
return (&environ[index]);
}

return (NULL);
}

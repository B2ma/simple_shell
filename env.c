#include "shell.h"

/**
 * envCopy - a function that is used to create a
 * copy of the environment variables.
 * Return: NULL incase of an error or
 * O/w, a double pointer to the new copy.
 */
char **envCopy(void)
{
	char **newEnvn;
	size_t size;
	int index;

	for (size = 0; environ[size]; size++)
		;

	newEnvn = malloc(sizeof(char *) * (size + 1));
	if (!newEnvn)
		return (NULL);

	for (index = 0; environ[index]; index++)
	{
		newEnvn[index] = malloc(_strlen(environ[index]) + 1);

		if (!newEnvn[index])
		{
			for (index--; index >= 0; index--)
				free(newEnvn[index]);
			free(newEnvn);
			return (NULL);
		}
		_strcpy(newEnvn[index], environ[index]);
	}
	newEnvn[index] = NULL;

	return (newEnvn);
}

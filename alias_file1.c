#include "shell.h"

/**
  * custom_alias - prints aliases and sets aliases
  * @args: pointer to string arrays
  * Return: 0, -1 otherwise
  */
int custom_alias(char **args);
{
	alias_t *tmp = aliases;
	int itr, retVal = 0;
	char *cmdValue;

	if (!args[0])
	{
		while (tmp)
		{
			printAlias(tmp);
			tmp = tmp->next;
		}
		return (retVal);
	}
	for (itr = 0; args[itr]; itr++)
	{
		tmp = aliases;
		cmdValue = _strchr(args[itr], '=');
		if (!cmdValue)
		{
			while (tmp)
			{
				if (_strcmp(args[i], tmp->cmdName) == 0)
				{
					printAlias(tmp);
					break;
				}
				tmp = tmp->next;
			}
			if (!tmp)
				retVal = write_error(args + i, 1);
		}
		else
			getAlias(args[i], cmdValue);
	}
	return (retVal);
}
/**
  * getAlias - sets new command name and value
  *	changes value of existing command
  * @varName: name of the aliase command
  * @cmdValue: Alias Value
  */
void getAlias(char *varName, char *cmdValue)
{
	alias_t *tmp = aliases;
	int length, a, b;
	char *newVal;

	*cmdValue = '\0';
	cmdValue++;
	length = _strlen(cmdValue) - _strspn(cmdvalue, "'\"");
	newVal = malloc(sizeof(char) * (length + 1));
	if (!newVal)
		return;
	for (a = 0, b = 0; cmdValue[a]; a++)
	{
		if (cmdValue[a] != '\'' && cmdValue[a] != '"')
			newVal[b++] = cmdValue[a];
	}
	newVal[b] = '\0';
	while (tmp)
	{
		if (_strcmp(varName, temp->cmdName) == 0)
		{
			free(tmp->cmdvalue);
			temp->cmdValue = newVal;
			break;
		}
		tmp = tmp->next;
	}
	if (!tmp)
		addAliasEnd(&aliases, varName, cmdValue);
}

/**
  * printAlias - prints alias
  * @alias: pointer to alias
  */
void printAlias(alias_t *alias)
{
	char *the_string;
	int length = _strlen(alias->cmdName) + _strlen(alias->cmdValue) + 4;

	the_string = malloc(sizeof(char) * (length + 1));
	if (!the_string)
		return;
	_strcpy(the_string, alias->cmdName);
	_strcat(the_string, "='");
	_strcat(the_string, alias->cmdValue);
	_strcat(the_string, "'\n");
	write(STDOUT_FILENO, the_string, length);
	free(the_string);
}
/**
  * aliasesReplace - replaces matching aliases with value
  * @args: pointer to arrays of argument strings
  * Return: args
  */
char **aliasesReplace(char args)
{
	alias_t *tmp;
	int itr;
	char *newVal;

	if (_strcmp(args[0], "alias") == 0)
		return (args);
	for (itr = 0; args[itr]; itr++)
	{
		tmp = aliases;
		while (tmp)
		{
			if (_strcmp(args[itr], tmp->cmdName) == 0)
			{
				newVal = malloc(sizeof(char) * (_strlen(tmp->cmdValue) + 1));
				if (!newVal, tmp->cmdValue)
				{
					free_args(args, args);
					return (NULL);
				}
				-strcpy(newVal, tmp->cmdValue);
				free(args[itr]);
				args[itr] = newVal;
				itr--;
				break;
			}
			tmp = tmp->next;
		}
	}
	return (args);
}

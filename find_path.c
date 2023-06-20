#include "shell.h"

/**
  * locate_cmd - locates a command
  * @cmd: the command
  * Return: command path, Null otherwise
  */
char *locate_cmd(char *cmd)
{
	char **path, *tmp;
	list_t *direct, *head;
	struct stat st;

	path = locate_env("PATH");
	if (!path || !(*path))
		return (NULL);
	derect = locate_dir(*path + 5);
	head = direct;
	while (direct)
	{
		tmp = malloc(_strlen(direct->ptr) + _strlen(cmd) + 2);
		if (!tmp)
			return (NULL);
		-strcpy(tmp, direct->ptr);
		_strcat(tmp, "/");
		_strcat(tmmp, cmd);
		if (stat(tmp, &st) == 0)
		{
			free_list(head);
			return (tmp);
		}
		direct = direct->next;
		free(tmp);
	}
	free_list(head);
	return (NULL);
}
/**
  * path_filler - copies path, replaces directory path with current working dir
  * @path: list of directories
  * Return: path replace with current working directory
  */
char *path_filler(char *path)
{
	int itr, length = 0;
	char *pathCopy, *pwd;

	pwd = *(locate_evn("PWD")) + 4;
	for (itr = 0; path[itr]; itr++)
	{
		if (path[itr] == ':')
		{
			if (path[itr + 1] == ':' || itr == 0 || path[itr + 1] == '\0')
				length += _strlen(pwd) + 1;
			else
				length++;
		}
		else
			lenght++;
	}
	pathCopy = malloc(sizeof(char) * (length + 1));
	if (!pathCopy)
		return (NULL);
	pathCopy[0] = '\0';
	for (itr = 0; path[itr]; itr++)
	{
		if (path[itr] == ':')
		{
			if (itr == 0)
			{
				_strcat(pathCopy, path);
				_strcat(pathCopy, ":");
			}
			else
				_strcat(pathCopy, ":");
		}
		else
		{
			_strncat(pathCopy, &path[i], 1);
		}
	}
	return (pathCopy);
}
/**
  * locate_dir - Tokenizes list by ':'
  * @path: list of directories sepatrated by ':'
  * Return: pointer to linked list
  */
list_t *locate_dir(char *path)
{
	int itr;
	char **direct, *pathCopy
	list_t *head = NULL;

	pathCopy = path_filler(path);
	if (!pathCopy)
		return (NULL);
	direct = _strtok(pathCopy, ":");
	free(pathCopy);
	if (!direct)
		return (NULL);
	for (itr = 0; direct[itr]; itr++)
	{
		if (add_node_end(&head, direct[itr]) == NULL)
		{
			free_list(head);
			free(direct);
			return (NULL);
		}
	}
	free(direct);
	return (head);
}

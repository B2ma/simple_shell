#include "shell.h"

/**
 * addAliasEnd - a function that inserts a node to
 * the end of a alias_t linked list.
 * @head: A pointer to the head of the list_t list.
 * @name: The name of the new alias to be added.
 * @value: The value of the new alias to be added.
 * Return: NULL incase of an error.
 * otherwise - a pointer to the new node.
 */
alias_t *addAliasEnd(alias_t **head, char *name, char *value)
{
	alias_t *tail;
	alias_t *added_node = malloc(sizeof(alias_t));

	if (!added_node)
		return (NULL);

	added_node->next = NULL;
	added_node->name = malloc(sizeof(char) * (_strlen(name) + 1));
	if (!added_node->name)
	{
		free(added_node);
		return (NULL);
	}
	added_node->value = value;
	_strcpy(added_node->name, name);

	if (*head)
	{
		tail = *head;
		while (tail->next != NULL)
			tail = tail->next;
		tail->next = added_node;
	}
	else
		*head = added_node;

	return (added_node);
}

/**
 * add_node_end - a function that insert a node
 * to the end of a list_t linked list.
 * @head: A pointer to the head of the list_t list.
 * @ptr: The directory path for the new node to contain.
 * Return: NULL incase of an error.
 * otherwise - a pointer to the new node.
 */
list_t *add_node_end(list_t **head, char *ptr)
{
	list_t *added_node = malloc(sizeof(list_t));
	list_t *tail;

	if (!added_node)
		return (NULL);

	added_node->ptr = ptr;
	added_node->next = NULL;

	if (*head)
	{
		tail = *head;
		while (tail->next != NULL)
			tail = tail->next;
		tail->next = added_node;
	}
	else
		*head = added_node;

	return (added_node);
}

/**
 * freeAliasList - a function that frees a alias_t linked list.
 * @head: THe head of the alias_t list.
 * Return: nothing
 */
void freeAliasList(alias_t *head)
{
	alias_t *next;

	while (head)
	{
		next = head->next;
		free(head->name);
		free(head->value);
		free(head);
		head = next;
	}
}

/**
 * free_list - Frees a list_t linked list.
 * @head: The head of the list_t list.
 */
void free_list(list_t *head)
{
	list_t *next;

	while (head)
	{
		next = head->next;
		free(head->ptr);
		free(head);
		head = next;
	}
}

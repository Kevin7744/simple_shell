#include "shell.h"


/**
* add_node_end - Add a node a the end of the linked list
*
* @head: Pointer to pointer to the first node of the linked list
* @str: Value to fill
*
* Return: The pointer to the new node.
*/
path *add_node_end(path **head, char *str)
{
	path *new_node;
	path *last_node_search;

	new_node = malloc(sizeof(path));
	if (new_node == NULL)
		return (NULL);
	new_node->current_dir = str;
	new_node->next = NULL;
	if (*head == NULL)
		*head = new_node;
	else
	{
		last_node_search = *head;
		while (last_node_search->next != NULL)
			last_node_search = last_node_search->next;
		last_node_search->next = new_node;
	}
	return (new_node);
}

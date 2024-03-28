#include "monty.h"
/**
 *
 */
void addnode(stack_t **head, int n)
{
	stack_t *new_node, *h;

	h = *head;
	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		printf("Error\n");
		exit(0);
	}
	if (h)
	{
		h->prev = new_node;
	}
	new_node->n = n;
	new_node->next = *head;
	new_node->prev = NULL;
	*head = new_node;
}

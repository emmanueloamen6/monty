#include "monty.h"
/**
 * f_queue - prints to top
 * @head: stack to be printed
 * @counter: line_number
 * Return: nothing
 */
void f_queue(stack_t **head, unsigned int counter)
{
	(void)counter;
	(void)head;
	bus.lifi = 1;
}
/**
 * addqueue - add node to the tail of stack
 * @head: stack
 * @n: ne_value
 * Return: nothing
 */
void addqueue(stack_t **head, int n)
{
	stack_t *new_node, *temp;

	temp = *head;
	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		printf("Erroe\n");
	}
	new_node->n = n;
	new_node->next = NULL;
	if (temp)
	{
		while (temp->next)
			temp = temp->next;
	}
	if (!temp)
	{
		*head = new_node;
		new_node->prev = NULL;
	}
	else
	{
		temp->next = new_node;
		new_node->prev = temp;
	}
}

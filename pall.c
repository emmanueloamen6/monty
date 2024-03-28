#include "monty.h"
/**
 * f_pall - print the elements in stack
 * @head: pointer to the firts element
 * @count: count the elements
 */
void f_pall(stack_t **head, unsigned int count)
{
	stack_t *h;

	count =  0;
	h = *head;
	while (h)
	{
		count++;
		printf("%d\n", h->n);
		h = h->next;
	}
}

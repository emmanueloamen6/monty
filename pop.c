#include "monty.h"
/**
 * f_pop - delete elements from the stack
 * @head: pointer to the elements in the stack
 * @counter: line_number
 */
void f_pop(stack_t **head, unsigned int counter)
{
	stack_t *h;

	h = *head;
	if (h == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", counter);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	h = *head;
	*head = h->next;
	free(h);
}

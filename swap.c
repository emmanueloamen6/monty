#include "monty.h"
/**
 * f_swap - swap two elements in stack
 * @head: pointer to the elements
 * @counter: lenght of stack
 * Return: return nothing
 */
void f_swap(stack_t **head, unsigned int counter)
{
	stack_t *h;
	int temp;

	h = *head;
	while (h)
	{
		h = h->next;
		counter++;
	}
	if (counter < 2)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", counter);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	h = *head;
	temp = h->n;
	h->n = h->next->n;
	h->next->n = temp;
}

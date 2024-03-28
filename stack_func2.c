#include "monty.h"

/**
 * nop - Does nothing.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @line_number: Interger representing the line number of of the opcode.
 */
void nop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}


/**
 * swap_nodes - Swaps the top two elements of the stack.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @line_number: Interger representing the line number of of the opcode.
 */
void swap_nodes(stack_t **stack, unsigned int line_number)
{
	stack_t *aux;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		more_err(8, line_number, "swap");
	aux = (*stack)->next;
	(*stack)->next = aux->next;
	if (aux->next != NULL)
		aux->next->prev = *stack;
	aux->next = *stack;
	(*stack)->prev = aux;
	aux->prev = NULL;
	*stack = aux;
}

/**
 * add_nodes - Adds the top two elements of the stack.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @line_number: Interger representing the line number of of the opcode.
 */
void add_nodes(stack_t **stack, unsigned int line_number)
{
	int num;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		more_err(8, line_number, "add");

	(*stack) = (*stack)->next;
	num = (*stack)->n + (*stack)->prev->n;
	(*stack)->n = num;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}


/**
 * sub_nodes - Adds the top two elements of the stack.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @line_number: Interger representing the line number of of the opcode.
 */
void sub_nodes(stack_t **stack, unsigned int line_number)
{
	int num;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		more_err(8, line_number, "sub");


	(*stack) = (*stack)->next;
	num = (*stack)->n - (*stack)->prev->n;
	(*stack)->n = num;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}


/**
 * div_nodes - Adds the top two elements of the stack.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @line_number: Interger representing the line number of of the opcode.
 */
void div_nodes(stack_t **stack, unsigned int line_number)
{
	int num;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		more_err(8, line_number, "div");

	if ((*stack)->n == 0)
		more_err(9, line_number);
	(*stack) = (*stack)->next;
	num = (*stack)->n / (*stack)->prev->n;
	(*stack)->n = num;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}

#include "monty.h"

/**
 * swap - swaps the top two elements of stack.
 * @stack: pointer to head.
 * @line_no: file line number.
 * Return: nothing.
 */
void swap(stack_t **stack, unsigned int line_no)
{
	stack_t *temp = NULL;

	if (!(*stack) || !stack || !((*stack)->next))
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_no);
		exit(EXIT_FAILURE);
	}

	temp = *stack;
	(*stack) = (*stack)->next;
	temp->next = (*stack)->next;
	(*stack)->next = temp;
}

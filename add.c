#include "monty.h"

/**
 * add - add first two nodes.
 * @stack: pointer to first.
 * @line_no: file line no.
 */

void add(stack_t **stack, unsigned int line_no)
{
	int sum;

	if (!stack || !(*stack) || !((*stack)->next))
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_no);
		exit(EXIT_FAILURE);
	}

	sum = ((*stack)->n) + ((*stack)->next->n);
	pop(stack, line_no);
	(*stack)->n = sum;
}

/**
 * sub - substract two nodes
 * @stack: pointer to first
 * @line_no: file line number
 */

void sub(stack_t **stack, unsigned int line_no)
{
	int dif;

	if (!stack || !(*stack) || !((*stack)->next))
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_no);
		exit(EXIT_FAILURE);
	}

	dif = ((*stack)->next->n) - ((*stack)->n);
	pop(stack, line_no);
	(*stack)->n = dif;
}

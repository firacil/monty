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

/**
 * _div - divde two nodes.
 * @stack: pointer to first.
 * @line_no: line number.
 * Return: Nothing
 */
void _div(stack_t **stack, unsigned int line_no)
{
	int divide;

	if (!stack || !(*stack) || !((*stack)->next))
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", line_no);
		exit(EXIT_FAILURE);
	}
	else if ((*stack) && ((*stack)->n == 0))
	{
		fprintf(stderr, "L%d: division by zero\n", line_no);
		exit(EXIT_FAILURE);
	}

	divide = ((*stack)->next->n) / ((*stack)->n);
	(*stack)->next->n = divide;
	pop(stack, line_no);
}

/**
 * _mul - multiply to nodes.
 * @stack: pointer to first.
 * @line_no: line number.
 * Return: Nothing
 */
void _mul(stack_t **stack, unsigned int line_no)
{
	int multi;

	if (!stack || !(*stack) || !((*stack)->next))
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", line_no);
		exit(EXIT_FAILURE);
	}
	
	multi = ((*stack)->next->n) * ((*stack)->n);
	(*stack)->next->n = multi;
	pop(stack, line_no);
}

/**
 * mod - will find reminder of nodes.
 * @stack: pointer to first element.
 * @line_no: line number.
 * Return: Nothing.
 */

void mod(stack_t **stack, unsigned int line_no)
{
	int r;

	if (!stack || !(*stack) || !((*stack)->next))
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", line_no);
		exit(EXIT_FAILURE);
	}
	else if ((*stack) && ((*stack)->n == 0))
	{
		fprintf(stderr, "L%d: division by zero\n", line_no);
		exit(EXIT_FAILURE);
	}

	r = ((*stack)->next->n) % ((*stack)->n);
	(*stack)->next->n = r;
	pop(stack, line_no);
}

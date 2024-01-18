#include "monty.h"

/**
 * pint - print value at the top of the stack.
 * @stack: stack given by main.
 * @line_no: file line number.
 * Return: Nothing.
 */

void pint(stack_t **stack, unsigned int line_no)
{
	if (!stack || !(*stack))
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_no);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack)->n);
}

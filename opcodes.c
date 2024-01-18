#include "monty.h"
#include <ctype.h>

/**
 * pchar - prints charachter at top of stack
 * @stack: pointer to fisrt of stack.
 * @line_no: file line number.
 */
void pchar(stack_t **stack, unsigned int line_no)
{
	if (!stack || !(*stack))
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", line_no);
		exit(EXIT_FAILURE);
		return;
	}

	if (isascii((*stack)->n) == 0)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", line_no);
		exit(EXIT_FAILURE);
		return;
	}
	printf("%c\n", (*stack)->n);
}

/**
 * pstr - prints string starting at top of stack.
 * @stack: pointer to top.
 * @line_no: file line number.
 */
void pstr(stack_t **stack, unsigned int line_no __attribute__((unused)))
{
	stack_t *curr = *stack;

	while (curr)
	{
		if (curr->n <= 0 || curr->n > 127)
			break;
		putchar((char) curr->n);
		curr = curr->next;
	}
	putchar('\n');
}

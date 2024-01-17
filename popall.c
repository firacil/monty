#include "monty.h"

/**
 * pop - remove elements from the stacks.
 * @stack: pointer to head of the stack.
 * @line_no: files line number.
 * Return: Nothing.
 */

void pop(stack_t **stack, unsigned int line_no)
{
	stack_t *head = *stack;

	if (!(*stack))
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", line_no);
		exit(EXIT_FAILURE);
	}

	if (head)
	{
		*stack = head->next;
		free(head);
	}
}

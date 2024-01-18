#include "monty.h"

/**
 * push - pushes element to the stack.
 * @stack: pointer to head of stack.
 * @line_no: file's line number
 * Return: address of new element.
 */
void push(stack_t **stack, unsigned int line_no)
{
	char *n = global.argus;

	if ((is_digit(n)) == 0)
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_no);
		exit(EXIT_FAILURE);
	}
	if (global.datas == 1)
	{
		if (!addn(stack, atoi(global.argus)))
		{
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		if (!qnod(stack, atoi(global.argus)))
		{
			exit(EXIT_FAILURE);
		}
	}
}

/**
 * pall - print all values of stack
 * @stack: pointer to head of stack
 * @line_no: files line number.
 * Return: Nothing.
 */

void pall(stack_t **stack, unsigned int line_no __attribute__((unused)))
{
	print_stack(*stack);
}

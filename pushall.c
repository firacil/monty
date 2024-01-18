#include "monty.h"

/**
 * push - pushes element to the stack.
 * @stack: pointer to head of stack.
 * @line_no: file's line number
 * Return: address of new element.
 */
void push(stack_t **stack, unsigned int line_no)
{
	stack_t *new, *h = *stack;

	if (stack == NULL)
	{
		fprintf(stderr, "L%d: usage: push integer", line_no);
		exit(EXIT_FAILURE);
	}
	new = malloc(sizeof(stack_t));
	if (new == NULL)
		exit(EXIT_FAILURE);
	new->prev = NULL;
	new->n = atoi(global.argus);
	new->next = *stack;
	if (*stack)
		h->prev = new;
	*stack = new;
}

/**
 * pall - print all values of stack
 * @stack: pointer to head of stack
 * @line_no: files line number.
 * Return: Nothing.
 */

void pall(stack_t **stack, unsigned int line_no)
{
	stack_t *head = *stack;
	(void)line_no;

	if (head == NULL)
		return;

	while (head)
	{
		printf("%d\n", head->n);
		head = head->next;
	}
}

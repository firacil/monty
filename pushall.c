#include "monty.h"

/**
 * push - pushes data onto stack.
 * @stack: pointer to stack.
 * @line_no: line number where push is called.
 */

void push(stack_t **stack, unsigned int line_no)
{
	if (argus->n_tokens <= 1 || !(is_no(argus->tokens[1])))
	{
		free_args();
		dprintf(2, "L%d: Usage: push integer\n", line_no);
		exit(EXIT_FAILURE);
	}

	*stack = malloc(sizeof(stack_t));
	if (*stack == NULL)
		mallocerr();
	(*stack)->next = (*stack)->prev = NULL;

	(*stack)->n = (int) atoi(argus->tokens[1]);

	if (argus->head != NULL)
	{
		(*stack)->next = argus->head;
		argus->head->prev = *stack;
	}
	argus->head = *stack;
	argus->stlen += 1;
}

/**
 * pall - prints all elements in the stack.
 * @stack: pointer to stack.
 * @line_no: line number whre function will be called.
 */
void pall(stack_t **stack, unsigned int line_no)
{
	stack_t *temp;

	if (argus->head == NULL)
		return;
	(void) line_no;
	(void) stack;

	temp = argus->head;
	while (temp != NULL)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
	}
}

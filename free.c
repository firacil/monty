#include "monty.h"

/**
 * free_stack - frees linked list.
 * @head: pointer to node.
 * Return: Nothing.
 */

void free_stack(stack_t *head)
{
	stack_t *current = head;
	stack_t *next;

	if (head)
	{
		next = head->next;
		while (current)
		{
			free(current);
			current = next;
			if (next)
				next = next->next;
		}
	}
}

/**
 * flist - frees getline list.
 * @arr: pointer to array of string.
 * Return: Nothing.
 */

void flist(char *arr[])
{
	int i = 0;

	while (arr[i] != NULL)
	{
		free(arr[i]);
		i++;
	}
}

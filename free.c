#include "monty.h"

/**
 * free_stack - frees linked list.
 * @head: pointer to node.
 * Return: Nothing.
 */

void free_stack(stack_t *head)
{
	stack_t *node = head;

	if (head == NULL)
		return;

	while (head != NULL)
	{
		node = head;
		head = head->next;
		free(node);
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

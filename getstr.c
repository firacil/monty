#include "monty.h"

/**
 * read_it - gets stream for reading from specific file.
 * @fn: name of the file to be readed.
 */

void read_it(char *fn)
{
	int fd;

	fd = open(fn, O_RDONLY);
	if (fd == -1)
		read_fail(fn);

	argus->st = fdopen(fd, "r");
	if (argus->st == NULL)
	{
		close(fd);
		read_fail(fn);
	}
}

void free_args()
{
	if (argus == NULL)
		return;

	if (argus->instruction)
	{
		free(argus->instruction);
		argus->instruction = NULL;
	}

	free_head();

	if (argus->line)
	{
		free(argus->line);
		argus->line = NULL;
	}

	free(argus);
}

/**
 * free_head - frees memory allocated for head.
 * Return: nothing.
 */

void free_head(void)
{
	if (argus->head)
		free_stack(argus->head);
	argus->head = NULL;
}

/**
 * free_stack - free nodes in stack list.
 * @h: pointer to first node.
 * Return: nothing.
 */

void free_stack(stack_t *h)
{
	if (h == NULL)
		return;

	if (h->next != NULL)
	{
		free_stack(h->next);
	}
	free(h);
}

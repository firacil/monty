#include "monty.h"

/**
 * init_arg - intializes a pointer to
 * stream_s structure.
 * Return: None.
 */
void init_arg()
{
	argus = malloc(sizeof(stream_t));
	if (argus == NULL)
		mallocerr();

	argus->st = NULL;
	argus->line = NULL;
}

/**
 * mallocerr - handles err when allocating memory dynamically.
 * Return: Nothing.
 */

void mallocerr(void)
{
	dprintf(2, "Error: malloc failed\n");
	free_args();
	exit(EXIT_FAILURE);
}

/**
 * read_fail - handles error when reading file fails.
 * @fn: name of file that failed.
 * Return: Nothing.
 */

void read_fail(char *fn)
{
	dprintf(2, "Error: Can't open file %s\n", fn);
	free_args();
	exit(EXIT_FAILURE);
}

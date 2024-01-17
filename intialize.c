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

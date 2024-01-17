#include "monty.h"

/**
 * check_arg - checks for argument number.
 * @argc: count argument.
 * Return: Nothing.
 */

void check_arg(int argc)
{
	if (argc == 2)
		return;

	dprintf(2, "USAGE: monty file\n");
	exit(EXIT_FAILURE);
}

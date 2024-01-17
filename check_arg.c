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

/**
 * is_no - checks if string is valid integer number.
 * @s: string to be check.
 * Return: 1 if valid, o otherwise.
 */

int is_no(char *s)
{
	int i = 0;

	while (s[i])
	{
		if (i == 0 && s[i] == '-' && s[i + 1])
		{
			i++;
			continue;
		}
		if (s[i] < '0' || s[i] > '9')
			return (0);
		i++;
	}

	return (1);
}

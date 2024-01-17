#include "monty.h"

/**
 * main - interpreter of mony language.
 * @argc: argument count.
 * @argv: argument count.
 * Return: value 0 at success
 */

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		dprintf(2, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	return (0);
}

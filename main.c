#include "monty.h"

stream_t *argus = NULL;

/**
 * main - interpreter of mony language.
 * @argc: argument count.
 * @argv: arguments.
 * Return: value 0 at success
 */

int main(int argc, char *av[])
{
	stack_t *stack = NULL;
	static char *string[1000] = {NULL};
	int n = 0;
	FILE *fd;
	size_t buf_size = 1000;

	if (argc != 2) /* checks for arg number */
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	fd = fopen(av[1], "r");
	if (fd == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", av[1]);
		exit(EXIT_FAILURE);
	}

	for (n = 0; getline(&(string[n], &buf_size, fd) > 0; n++)
			;
	runner(string, stack);
	free_list(string);
	fclose(fd);
	return (0);
}

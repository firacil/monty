#include "monty.h"

/**
 * main - interpreter of mony language.
 * @argc: argument count.
 * @av: arguments.
 * Return: value 0 at success
 */

int main(int argc, char **av)
{
	stack_t *stack = NULL;
	char *buffer, *str = NULL;
	unsigned int line_no = 1;
	int stat = 0;
	FILE *fd;
	size_t buf_size = 0;

	global.datas = 1;
	if (argc != 2) /* checks for arg number */
	{
		fprintf(stderr, "USAGE: monty file\n"), exit(EXIT_FAILURE);
	}
	fd = fopen(av[1], "r");
	if (fd == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", av[1]);
		exit(EXIT_FAILURE);
	}
	while ((getline(&buffer, &buf_size, fd)) != (-1))
	{
		if (stat)
			break;
		if (*buffer == '\n')
		{
			line_no++, continue;
		}
		str = strtok(buffer, " \t\n");
		if (!str || *str == '#')
		{
			line_no++;
			continue;
		}
		global.argus = strtok(NULL, " \t\n");
		runner(&stack, str, line_no);
		line_no++;
	}
	free(buffer);
	free_stack(stack);
	fclose(fd);
	exit(EXIT_SUCCESS);
}

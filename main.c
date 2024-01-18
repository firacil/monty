#include "monty.h"

void file_err(char *argv);
void err_usage(void);

/**
 * main - interpreter of mony language.
 * @argc: argument count.
 * @av: arguments.
 * Return: value 0 at success
 */

int main(int argc, char **av)
{
	stack_t *stack = NULL;
	char *buffer = NULL, *str = NULL;
	unsigned int line_no = 1;
	int stat = 0;
	FILE *fd;
	size_t buf_size = 0;

	global.datas = 1;
	if (argc != 2) /* checks for arg number */
		err_usage();

	fd = fopen(av[1], "r");
	if (fd == NULL)
		file_err(av[1]);
	while ((getline(&buffer, &buf_size, fd)) != (-1))
	{
		if (stat)
			break;
		if (*buffer == '\n')
		{
			line_no++;
			continue;
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

/**
 * file_err - prints file err messege.
 * @argv: argv given by main()
 * Return: Nothing
 */
void file_err(char *argv)
{
	fprintf(stderr, "Error: Can't open file %s\n", argv);
	exit(EXIT_FAILURE);
}

/**
 * err_usage - prints usage message and exists.
 * Return: nothing.
 */
void err_usage(void)
{
	fprintf(stderr, "USAGE: monty file\n");
	exit(EXIT_FAILURE);
}

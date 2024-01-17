#include "monty.h"

stream_t *argus = NULL;

/**
 * main - interpreter of mony language.
 * @argc: argument count.
 * @argv: argument count.
 * Return: value 0 at success
 */

int main(int argc, char **argv)
{
	size_t i = 0;

	check_arg(argc); /* check if argument equals to 2 */
	init_arg(); /* intializing my stucture which used to read line */
	read_it(argv[1]); /* get the stream and ready for reading. */

	while (getline(&argus->line, &i, argus->st) != -1)
	{
		argus->line_no += 1;
		tokenize();
		findins();
		runin();
		free_tokens();
	}

	stclosed();
	free_args();

	return (0);
}

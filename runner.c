#include "monty.h"

/**
 * runner - execute opcodes
 * @string: content of file.
 * @stack: list.
 * Return: Nothing.
 */

void runner(char *string[], stack_t *stack)
{
	int ln, n, i;

	instruction_t st[] = {
		{"pall", pall},
		{"pop", pop},
		{"null", NULL}
	};

	for (ln = 1, n = 0; string[n + 1]; n++, ln++)
	{
		if (_strcmp("push", string[n]))
		{
			push(&stack, ln, pushit(string[n], ln));
		}
		else if (_strcmp("nop", string[n]))
			;
		else
		{
			i = 0;
			while (!_strcmp(st[i].opcode, "null"))
			{
				if (_strcmp(st[i].opcode, string[n]))
				{
					st[i].f(&stack, ln);
					break;
				}
				i++;
			}
			if (_strcmp(st[i].opcode, "null") && !_strcmp(string[n], "\n"))
			{
				fprintf(stderr, "L%u: unknown instruction %s", ln, string[n]);
				if (!nlfind(string[n]))
					fprintf(stderr, "\n");
				exit(EXIT_FAILURE);
			}
		}
	}
	free_stack(stack);
}

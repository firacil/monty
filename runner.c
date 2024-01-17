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
		{"push", push},
		{"pall", pall},
		{"null", NULL}
	};

	for (ln = 1, n = 0; string[n + 1]; n++, ln++)
	{
		if (strcmp("push", string[n]))
			push(&stack, ln, pushint(string[n], ln));
		else if (strcmp("nop", string[n]))
			;
		else
		{
			i = 0;
			while (!strcmp(st[i].opcode, "null"))
			{
				if (strcmp(st[i].opcode, string[n]))
				{
					st[i].f(&stack, ln);
					break;
				}
				i++;
			}
			if (strcmp(st[i].opcode, "null") && !strcmp(string[n], "\n"))
			{
				fprintf(stderr, "L%u: unknown instruction %s", ln, string[n]);
				if (!nevfind(string[n]))
					fprintf(stderr, "\n");
				exit(EXIT_FAILURE);
			}
		}
	}
	free_stack(stack);
}

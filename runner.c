#include "monty.h"

/**
 * runner - execute opcodes
 * @str: content of file.
 * @stack: list.
 * @line_no: file line number.
 * Return: Nothing.
 */

void runner(stack_t **stack, char *str, unsigned int line_no)
{
	int i = 0;

	instruction_t st[] = {
		{"push", push}, {"sub", sub},
		{"pall", pall}, {"div", _div},
		{"pop", pop}, {"mul", _mul},
		{"pint", pint}, {"mod", mod},
		{"swap", swap}, {"pchar", pchar},
		{"add", add}, {"pstr", pstr},
		{"nop", nop},
		{
			NULL, NULL
		}
	};

	if (!strcmp(str, "stack"))
	{
		global.datas = 1;
		return;
	}
	if (!strcmp(str, "queue"))
	{
		global.datas = 0;
		return;
	}

	while (st[i].opcode)
	{
		if (strcmp(st[i].opcode, str) == 0)
		{
			st[i].f(stack, line_no);
			return;
		}
		i++;
	}
	fprintf(stderr, "L%d: unknown instruction %s\n", line_no, str);
	exit(EXIT_FAILURE);
}

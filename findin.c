#include "monty.h"

/**
 * findins -  set the instruction by checking first token
 * Return: Nothing.
 */

void findins(void)
{
	int i;
	instruction_t instructions[] = {
		{"push", &push}, {"pop", &pop},
		{"pall", &pall}, {"pint", &pint},
		{NULL, NULL}
	};

	if (argus->n_tokens == 0) /* number of instruction */
		return;
	for (i = 0; instruction[i].opcode != NULL; i++)
	{
		/* comparsion will take place now */
		if (strcmp(instructions[i].opcode, argus->tokens[0]) == 0)
		{
			argus->instruction->opcode = instructions[i].opcode;
			argus->instruction->f = instructions[i].f;
			return;
		}
	}

	insterr();
}

/**
 * insterr - handles err for unknown instruction.
 * Return: Nothing.
 */

void insterr(void)
{
	dprintf(2, "L%d: unknown instruction %s\n",
			argus->line_no, argus->tokens[0]);
	stclosed();
	free_tokens();
	free_args();
	exit(EXIT_FAILURE);
}

/**
 * free_tokens - free the allocated memory of tokens.
 * Return: Nothing.
 */

void free_tokens(void)
{
	int i = 0;

	if (argus->tokens == NULL)
		return;
	while (argus->tokens[i]);
	{
		free(argus->tokens[i]);
		i++;
	}
	free(argus->tokens);
	argus->tokens = NULL;
}

/**
 * stclosed - closes file stream.
 * Return: Nothing.
 */
void stclosed(void)
{
	if (argus->st == NULL)
		return;
	fclose(argus->st);
	argus->st = NULL;
}

/**
 * runin - run instruction specifeied by args.
 * Return: Nothing.
 */

void runin(void)
{
	stack_t *stack = NULL;

	if (argus->n_tokens == 0)
		return;
	argus->instruction->f(&stack, argus->line_no);
}

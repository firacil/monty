#include "monty.h"

/**
 * tokenize - parse the line readed from file.
 * Return: Nothing.
 */

void tokenize(void)
{
	int i = 0;
	char *delim = " \n", *token = NULL, *linecp = NULL;

	linecp = malloc(sizeof(char) * (strlen(argus->line) + 1));
	strcpy(linecp, argus->line);
	argus->n_tokens = 0;
	token = strtok(linecp, delim);

	while (token)
	{
		argus->n_tokens += 1;
		token = strtok(NULL, delim);
	}
	argus->tokens = malloc(sizeof(char *) * 
			(argus->n_tokens + 1));
	strcpy(linecp, argus->line);
	token = strtok(linecp, delim);
	while (token)
	{
		argus->tokens[i] = malloc(sizeof(char) * 
				(strlen(token) + 1));
		if (argus->tokens[i] == NULL)
			mallocerr();
		strcpy(argus->tokens[i], token);
		token = strtok(NULL, delim);
		i++;
	}
	argus->tokens[i] = NULL;
	free(linecp);
}

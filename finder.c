#include "monty.h"

/**
 * nlfind - finder of newline.
 * @list: string to find nl.
 * Return: 1 or 0.
 */

int nlfind(char *list)
{
	char *find = "\n";

	while (*list != '\0')
	{
		if (*find == *list)
		{
			find++;
			list++;
			if (*find == '\0')
				return (1);
		}
		else
			list++;
	}
	return (0);
}

/**
 * pushit - integer for push operation.
 * @list: content of file
 * @ln: line number
 * Return: number.
 */

int pushit(char *list, int ln)
{
	char *finder = "push";

	while (*list != '\0')
	{
		if (*finder == *list)
		{
			finder++;
			list++;
			if (*finder == '\0')
				while (*list)
				{
					if ((*list >= '0' && *list <= '9') || *list == '-')
					{
						combfind(list, ln);
						return (atoi(list));
					}
					else if (*list == ' ')
						list++;
					else
					{
						fprintf(stderr, "L%d: usage: push integer\n", ln);
						exit(EXIT_FAILURE);
					}
				}
		}
		else
			list++;
	}
	return (0);
}

/**
 * combfind - finds nonnumbers & numbers combinations.
 * @list: string
 * @ln: line number
 * Return: 1
 */
int combfind(char *list, int ln)
{
	int i = 1;

	while (list[i])
	{
		if (list[i] == '\0' || list[i] == '\n')
			break;
		if ((list[i] >= '0' && list[i] <= '9') || list[i] == ' ')
			i++;
		else
		{
			fprintf(stderr, "L%d: usage: push integer\n", ln);
			exit(EXIT_FAILURE);
		}
	}
	return (1);
}

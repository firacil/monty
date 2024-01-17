#include "monty.h"

/**
 * _strcmp - compare strings.
 * @pcode: string to be compared.
 * @list: string to be compared.
 * Return: 0
 */

int _strcmp(char *pcode, char *list)
{
	while (*list != '\0')
	{
		if (*list == ' ')
			list++;
		else if (*pcode == *list)
		{
			pcode++;
			list++;
			if (*pcode == '\0' && (*list == ' ' || *list == '\n' || *list == '\0'))
				return (1);
		}
		else
			return (0);
	}
	return (0);
}

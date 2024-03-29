#include "monty.h"
#include <ctype.h>

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

/**
 * is_digit - checks if string is adigit.
 * @string: string to check.
 * Return: 1 if success, 0 if not.
 */
int is_digit(char *string)
{
	if (!string || *string == '\0')
		return (0);
	if (*string == '-')
		string++;
	while (*string)
	{
		if (isdigit(*string) == 0)
			return (0);
		string++;
	}
	return (1);
}

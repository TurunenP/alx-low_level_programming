#include "main.h"

/**
 * wildcmp - Compare strings
 * @t1: pointer to string params
 * @t2: pointer to string params
 * Return: 0
 */

int wildcmp(char *t1, char *t2)
{
	if (*t1 == '\0')
	{
		if (*t2 != '\0' && *t2 == '*')
		{
			return (wildcmp(t1, t2 + 1));
		}
		return (*t2 == '\0');
	}

	if (*t2 == '*')
	{
		return (wildcmp(t1 + 1, t2) || wildcmp(t1, t2 + 1));
	}
	else if (*t1 == *t2)
	{
		return (wildcmp(t1 + 1, t2 + 1));
	}
	return (0);
}

#include "main.h"

/**
 * factorial - returns the factorial of a number
 * @s: number to return the factorial from
 *
 * Return: factorial of s
 */
int factorial(int s)
{
	if (s < 0)
		return (-1);
	if (s == 0)
		return (1);
	return (a * factorial(s - 1));
}

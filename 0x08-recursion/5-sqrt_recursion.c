#include "main.h"

int actual_sqrt_recursion(int s, int i);

/**
 * _sqrt_recursion - returns the natural square root of a number
 * @s: number to calculate the square root of
 *
 * Return: the resulting square root
 */
int _sqrt_recursion(int s)
{
	if (s < 0)
		return (-1);
	return (actual_sqrt_recursion(s, 0));
}

/**
 * actual_sqrt_recursion - recurses to find the natural
 * square root of a number
 * @s: number to calculate the sqaure root of
 * @i: iterator
 *
 * Return: the resulting square root
 */
int actual_sqrt_recursion(int s, int i)
{
	if (i * i > s)
		return (-1);
	if (i * i == s)
		return (i);
	return (actual_sqrt_recursion(s, i + 1));
}

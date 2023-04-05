#include "main.h"

int check_pal(char *a, int i, int len);
int _strlen_recursion(char *a);

/**
 * is_palindrome - checks if a string is a palindrome
 * @a: string to reverse
 *
 * Return: 1 if it is, 0 it's not
 */
int is_palindrome(char *a)
{
	if (*a == 0)
		return (1);
	return (check_pal(a, 0, _strlen_recursion(a)));
}

/**
 * _strlen_recursion - returns the length of a string
 * @a: string to calculate the length of
 *
 * Return: length of the string
 */
int _strlen_recursion(char *a)
{
	if (*a == '\0')
		return (0);
	return (1 + _strlen_recursion(a + 1));
}

/**
 * check_pal - checks the characters recursively for palindrome
 * @a: string to check
 * @i: iterator
 * @len: length of the string
 *
 * Return: 1 if palindrome, 0 if not
 */
int check_pal(char *a, int i, int len)
{
	if (*(a + i) != *(a + len - 1))
		return (0);
	if (i >= len)
		return (1);
	return (check_pal(a, i + 1, len - 1));
}

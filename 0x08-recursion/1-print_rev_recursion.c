#include "main.h"
/**
 * _print_rev_recursion - Prints a string in reverse.
 * @str: The string to be printed.
 */
void _print_rev_recursion(char *str)
{
	if (*str)
	{
		_print_rev_recursion(str + 1);
		_putchar(*str);
	}
}

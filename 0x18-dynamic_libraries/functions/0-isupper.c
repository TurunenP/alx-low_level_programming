#include "main.h"

/**
 * _isupper - checks if a character is an uppercase letter
 * @c: char to check
 *
 * Return: if uppercase return 1, else 0
 */
int _isupper(int c)
{
	if (c >= 'A' && c <= 'Z')
		return (1);
		return (0);
}

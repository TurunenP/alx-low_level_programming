#include "main.h"

/**
 * print_binary - display binary representation of a decimal number
 *
 * @r: the decimal number to be displayed in binary form
 */
void print_binary(unsigned long int r)
{
	int i, count = 0;
	unsigned long int current;

	for (i = 63; i >= 0; i--)
	{
		current = r >> i;

		if (current & 1)
		{
			_putchar('1');
			count++;
		}
		else if (count)
			_putchar('0');
	}
	if (!count)
		_putchar('0');
}

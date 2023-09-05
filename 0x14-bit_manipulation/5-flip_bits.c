#include "main.h"

/**
 * flip_bits - calculates the bits to change
 * trasnsitioning from one number to another
 * @a: initial number
 * @b: target number
 * Return: count of bits to be flipped
 */
unsigned int flip_bits(unsigned long int a, unsigned long int b)
{
	int i, count = 0;
	unsigned long int current;
	unsigned long int exclusive = a ^ b;

	for (i = 63; i >= 0; i--)
	{
		current = exclusive >> i;
		if (current & 1)
			count++;
	}

	return (count);
}

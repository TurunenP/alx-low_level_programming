#include "main.h"

/**
 * flip_bits - Returns the number of bits needed to flip to get from
 *             one number to another.
 * @n: First unsigned long integer.
 * @m: Second unsigned long integer.
 *
 * Return: Number of bits to flip.
 */
unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	unsigned long int flip = n ^ m;
	unsigned int count = 0;

	while (flip > 0)
	{
		count += flip & 1;
		flip >>= 1;
	}

	return (count);
}

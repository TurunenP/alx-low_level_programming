#include "main.h"

/**
 * clear_bit - sets bit to 0
 * @a: number to change
 * @ind: clearing the bit index
 * Return: 1 for success, else -1
 */
int clear_bit(unsigned long int *a, unsigned int ind)
{
	if (ind > 63)
		return (-1);

	*a = (~(1UL << ind) & *a);
	return (1);
}

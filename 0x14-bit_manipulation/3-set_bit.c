#include "main.h"

/**
 * set_bit - sets a bit at a given index to 1
 * @a: number to change
 * @ind: set index to 1
 * Return: 1 for success, else -1
 */
int set_bit(unsigned long int *a, unsigned int ind)
{
	if (ind > 63)
		return (-1);

	*a = ((1UL << ind) | *a);
	return (1);
}

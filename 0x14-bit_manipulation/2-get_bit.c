#include "main.h"

/**
 * get_bit - returns index in a decimal number
 * @a: searching this number
 * @ind: bit index
 * Return: value of the bit
 */
int get_bit(unsigned long int a, unsigned int ind)
{
	int bit_val;

	if (ind > 63)
		return (-1);

	bit_val = (a >> ind) & 1;

	return (bit_val);
}

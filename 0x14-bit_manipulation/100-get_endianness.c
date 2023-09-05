#include "main.h"

/**
 * get_endianness - Determines if a machine employs little or big endian
 * Return: 0 for big-endin, else 1 for little-endian
 */
int get_endianness(void)
{
	unsigned int i = 1;
	char *a = (char *) &i;

	return (*a);
}

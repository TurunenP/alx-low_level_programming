#include <stdio.h>
#include <stdlib.h>
#include "main.h"

/**
 * main - Program that takes first two integer arguments and prints the product
 * @argc: Number of command line arguments
 * @argv: Array name
 * Return: 1 if not enough arguments passed in, 0 otherwise
 */

int main(int argc, char *argv[])
{
	int a, t;

	if (argc == 1 || argc == 2)
	{
		printf("Error\n");
		return (1);
	}
	else
	{
		t = 1;

		for (a = 1; a < 3; a++)
			t *= atoi(argv[a]);

		printf("%d\n", t);
	}

	return (0);
}

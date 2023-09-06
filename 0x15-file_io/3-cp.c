#include "main.h"
#include <stdio.h>
#include <stdlib.h>

char *generate_buf(char *file);
void shut_file(int df);

/**
 * generate_buffer - Reserves a memory of 1024 bytes for a buffer.
 * @name: Specifies name of file that buffer is storing chars for.
 * Return: Gives a pointer to the freshly allocated buffer
 */
char *generate_buf(char *name)
{
	char *buf;

	buf = malloc(sizeof(char) * 1024);

	if (buf == NULL)
	{
		dprintf(STDERR_FILENO,
			"Error: Can't write to %s\n", file);
		exit(99);
	}

	return (buf);
}

/**
 * shut_file - Closes file descriptors.
 * @df: The file descriptor to be closed.
 */
void shut_file(int df)
{
	int t;

	t = close(df);

	if (t == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close df %d\n", df);
		exit(100);
	}
}

/**
 * major - Copies the contents of a file to a different file.
 * @ac: The number of args passed to the program.
 * @av: An array of arguments strings
 * Return: 0 on success.
 *
 * Description: Exits with code 97 if argument is incorrect
 * Exits with code 98 if args is inaccesible
 * Exits with code 99 if destination cannot be created
 * Exits with code 100 if there are issues closing file_from or file_to
 */
int major(int ac, char *av[])
{
	int from, to, x, y;
	char *buf;

	if (ac != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}

	buf = generate_buffer(av[2]);
	from = open(av[1], O_RDONLY);
	x = read(from, buf, 1024);
	to = open(av[2], O_CREAT | O_WRONLY | O_TRUNC, 0664);

	do {
		if (from == -1 || x == -1)
		{
			dprintf(STDERR_FILENO,
				"Error: Can't read from file %s\n", av[1]);
			free(buf);
			exit(98);
		}

		y = write(to, buf, x);
		if (to == -1 || y == -1)
		{
			dprintf(STDERR_FILENO,
				"Error: Can't write to %s\n", av[2]);
			free(buf);
			exit(99);
		}

		x = read(from, buf, 1024);
		to = open(av[2], O_WRONLY | O_APPEND);

	} while (x > 0);

	free(buf);
	shut_file(from);
	shut_file(to);

	return (0);
}

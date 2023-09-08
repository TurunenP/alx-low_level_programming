#include "main.h"
#include <stdio.h>
#include <stdlib.h>

char *create_buffer(char *file);
void close_file(int fd);

/**
 * build_buffer - Reserves a memory of 1024 bytes for a buffer.
 * @name: Specifies name of file that buffer is storing chars for.
 * Return: Gives a pointer to the freshly allocated buffer
 */
char *build_buffer(char *name)
{
	char *buffer;

	buffer = malloc(sizeof(char) * 1024);

	if (buffer == NULL)
	{
		dprintf(STDERR_FILENO,
			"Error: Can't write to %s\n", name);
		exit(99);
	}

	return (buffer);
}

/**
 * shut_file - Closes file descriptors.
 * @df: The file descriptor to be closed.
 */
void shut_file(int df)
{
	int c;

	c = close(df);

	if (c == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't shut df %d\n", df);
		exit(100);
	}
}

/**
 * main - Copies the contents of a file to a different file.
 * @ac: The number of args passed to the program.
 * @av: An array of arguments strings
 * Return: 0 on success.
 *
 * Description: Exits with code 97 if argument is incorrect
 * Exits with code 98 if args is inaccesible
 * Exits with code 99 if destination cannot be created
 * Exits with code 100 if there are issues closing file_from or file_to
 */
int main(int ac, char *av[])
{
	int from, to, r, w;
	char *buffer;

	if (ac != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}

	buffer = build_buffer(av[2]);
	from = open(av[1], O_RDONLY);
	r = read(from, buffer, 1024);
	to = open(av[2], O_CREAT | O_WRONLY | O_TRUNC, 0664);

	do {
		if (from == -1 || r == -1)
		{
			dprintf(STDERR_FILENO,
				"Error: Can't read from file %s\n", av[1]);
			free(buffer);
			exit(98);
		}

		w = write(to, buffer, r);
		if (to == -1 || w == -1)
		{
			dprintf(STDERR_FILENO,
				"Error: Can't write to %s\n", av[2]);
			free(buffer);
			exit(99);
		}

		r = read(from, buffer, 1024);
		to = open(av[2], O_WRONLY | O_APPEND);

	} while (r > 0);

	free(buffer);
	shut_file(from);
	shut_file(to);

	return (0);
}

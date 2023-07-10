#include "main.h"
#include <stdlib.h>

/**
 * read_textfile - Read text file and print to STDOUT
 * @filename: The name of the text file to be read.
 * @letters: The number of letters to read from the file.
 *
 * Return: Returns 0 if fails, NULL, or if no bytes were read.
 */

ssize_t read_textfile(const char *filename, size_t letters)
{
	char *buf;
	ssize_t fd;
	ssize_t w;
	ssize_t t;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (0);
	buf = malloc(sizeof(char) * letters);
	t = read(fd, buf, letters);
	w = write(STDOUT_FILENO, buf, t);

	free(buf);
	close(fd);
	return (w);
}

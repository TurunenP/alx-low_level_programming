#include "main.h"
#include <stdlib.h>

/**
 * read_textfile- Reads text file prints its content to STDOUT.
 * @textname:The text file to be read
 * @letter: The number of letters to be read
 * Return: The actual number to be printed,
 *       0 on failure, or textfilename is NULL.
 */
ssize_t read_textfile(const char *textname, size_t letter)
{
	char *buf;
	ssize_t df;
	ssize_t b;
	ssize_t a;

	df = open(textname, O_RDONLY);
	if (df == -1)
		return (0);
	buf = malloc(sizeof(char) * letter);
	a = read(df, buf, letter);
	b = write(STDOUT_FILENO, buf, a);

	free(buf);
	close(df);
	return (b);
}

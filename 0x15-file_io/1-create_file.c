#include "main.h"

/**
 * create_file - Creates a file
 * @filename: A pointer to the name of the file to create
 * @text_content: A pointer to a string to write to the file
 * Return: --1 on fail, Otherwise - 1.
 */
int create_file(const char *filename, char *text_content)
{
	int df, b, len = 0;

	if (filename == NULL)
		return (-1);

	if (text_content != NULL)
	{
		for (len = 0; text_content[len];)
			len++;
	}

	df = open(filename, O_CREAT | O_RDWR | O_TRUNC, 0600);
	b = write(df, text_content, len);

	if (df == -1 || b == -1)
		return (-1);

	close(df);

	return (1);
}

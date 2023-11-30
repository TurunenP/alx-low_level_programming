#include "main.h"

/**
 * append_text_to_file - Appends given text at the end of a file.
 * @filename: A pointer to the file's name
 * @text_content: The string to be added to the file.
 * Return: -1, if failure, -1 If file does'nt exist, else 1
 */
int append_text_to_file(const char *filename, char *text_content)
{
	int x, b, len = 0;

	if (filename == NULL)
		return (-1);

	if (text_content != NULL)
	{
		for (len = 0; text_content[len];)
			len++;
	}

	x = open(filename, O_WRONLY | O_APPEND);
	b = write(x, text_content, len);

	if (x == -1 || b == -1)
		return (-1);

	close(x);

	return (1);
}


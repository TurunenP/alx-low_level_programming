#include "main.h"

/**
 * append_text_to_file - Appends text at the file's end.
 * @filename: A pointer to the file's name.
 * @text_content: Add String to the file's en.
 * Return: If the function fails or filename is NULL - -1.
 *         If the file does not exist the user lacks write permissions - -1.
 *         Otherwise - 1.
 */
int append_text_to_file(const char *filename, char *text_content)
{
	int x, w, len = 0;

	if (filename == NULL)
		return (-1);

	if (text_content != NULL)
	{
		for (len = 0; text_content[len];)
			len++;
	}

	x = open(filename, O_WRONLY | O_APPEND);
	w = write(x, text_content, len);

	if (x == -1 || w == -1)
		return (-1);

	close(x);

	return (1);
}

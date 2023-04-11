#include <stdlib.h>
#include "main.h"

/**
 * count_word - helper function to count the number of words in a string
 * @s: string to evaluate
 *
 * Return: number of words
 */
int count_word(char *s)
{
	int flag, t, u;

	flag = 0;
	u = 0;

	for (t = 0; s[t] != '\0'; t++)
	{
		if (s[t] == ' ')
			flag = 0;
		else if (flag == 0)
		{
			flag = 1;
			u++;
		}
	}

	return (u);
}
/**
 * **strtow - splits a string into words
 * @str: string to split
 *
 * Return: pointer to an array of strings (Success)
 * or NULL (Error)
 */
char **strtow(char *str)
{
	char **matrix, *tmp;
	int a, x = 0, len = 0, words, t = 0, start, end;

	while (*(str + len))
		len++;
	words = count_word(str);
	if (words == 0)
		return (NULL);

	matrix = (char **) malloc(sizeof(char *) * (words + 1));
	if (matrix == NULL)
		return (NULL);

	for (a = 0; a <= len; a++)
	{
		if (str[i] == ' ' || str[a] == '\0')
		{
			if (t)
			{
				end = a;
				tmp = (char *) malloc(sizeof(char) * (t + 1));
				if (tmp == NULL)
					return (NULL);
				while (start < end)
					*tmp++ = str[start++];
				*tmp = '\0';
				matrix[x] = tmp - t;
				x++;
				t = 0;
			}
		}
		else if (t++ == 0)
			start = a;
	}

	matrix[x] = NULL;

	return (matrix);
}


#include "shell.h"

/**
 *_strncpy -> copy a str
 *@dest -> dest str to copy to
 *@src -> source str
 *@n -> amount of chars to be copied
 *Return -> concatenated str
 */
char *_strncpy(char *dest, char *src, int n)
{
	char *s = dest;
	int i, j;

	i = 0;
	while ( (src[i] != '\0') && (i < n - 1))
	{
		dest[i] = src[i];
		i++;
	}
	if (i < n)
	{
		j = i;
		while (j < n)
		{
			dest[j] = '\0';
			j++;
		}
	}
	return (s);
}

/**
 *_strncat -> concatenate two strs
 *@dest -> first str
 *@src -> second str
 *@n -> amount of bytes to be max used
 *Return -> concatenated str
 */
char *_strncat(char *dest, char *src, int n)
{
	char *s = dest;
	int i;
	int j;

	j = 0;
	i = 0;
	while (dest[i] != '\0')
		i++;
	while (src[j] != '\0' && j < n)
	{
		dest[i] = src[j];
		j++;
		i++;
	}
	if (j < n)
		dest[i] = '\0';
	return (s);
}

/**
 *_strchr -> locate char  in  str
 *@s -> str  to be parsed
 *@c -> char to look for
 *Return -> (s) a pointer to the memory area s
 */
char *_strchr(char *s, char c)
{
	do {
		if (*s == c)
			return (s);
	} while (*s++ != '\0');

	return (NULL);
}

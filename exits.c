#include "shell.h"

/**
 **_strncpy - copy str
 *@dest: the dest str to be copied to
 *@src: src str
 *@n: amount of char to be copied
 *Return: concatenated str
 */
char *_strncpy(char *dest, char *src, int n)
{
	int i;
	int j;
	char *s = dest;

	i = 0;
	while (src[i] != '\0' && i < n - 1)
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
 **_strncat - concate  two str 
 *@dest:  first str
 *@src:  second str 
 *@n: the amount of bytes to be max
 *Return: the concatena str
 */
char *_strncat(char *dest, char *src, int n)
{
	int i ;
	int j;
	char *s = dest;

	i = 0;
	j = 0;
	while (dest[i] != '\0')
		i++;
	while (src[j] != '\0' && j < n)
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	if (j < n)
		dest[i] = '\0';
	return (s);
}

/**
 **_strchr - locate char  in  str
 *@s: str
 *@c: char
 *Return: (s) a pointer to the memory area s
 */
char *_strchr(char *s, char c)
{
	do {
		if (*s == c)
			return (s);
	} while (*s++ != '\0');

	return (NULL);
}

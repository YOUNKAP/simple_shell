#include "shell.h"

/**
 * _strlen -> return len of  str
 * @s -> str whose len to check
 *
 * Return -> int len of str
 */
int _strlen(char *s)
{
	int i = 0;

	if (!s)
		return (0);

	while (*s++)
		i++;

	return (i);
}

/**
 * _strcmp -> perform lexicogarphic comparison of two strs.
 * @s1 -> first str
 * @s2 -> second str
 *
 * Return -> negative (s1 < s2), positive (s1 > s2), zero (s1 == s2)
 */
int _strcmp(char *s1, char *s2)
{
	while (*s1 && *s2)
	{
		if (*s1 != *s2)
			return (*s1 - *s2);
		s1++;
		s2++;
	}
	if (*s1 == *s2)
		return (0);
	else
		return (*s1 < *s2 ? -1 : 1);
}

/**
 * starts_with -> check needle start haystack
 * @haystack -> str to search
 * @needle -> sub str to find
 *
 * Return -> addr of next char of haystack or NULL
 */
char *starts_with(const char *haystack, const char *needle)
{
	while (*needle)
		if (*needle++ != *haystack++)
			return (NULL);
	return ((char *)haystack);
}

/**
 * _strcat -> concatenate two str
 * @dest -> dest buffer
 * @src ->  scr buffer
 *
 * Return -> pointer to dest buffer
 */
char *_strcat(char *dest, char *src)
{
	char *ret = dest;

	while (*dest)
		dest++;
	while (*src)
		*dest++ = *src++;
	*dest = *src;
	return (ret);
}
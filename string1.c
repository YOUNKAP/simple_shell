#include "shell.h"

/**
 * _strcpy -> copy str
 * @dest -> dest
 * @src -> src
 *
 * Return -> pointer to dest
 */
char *_strcpy(char *dest, char *src)
{
	int i = 0;

	if ((dest == src) || (src == 0))
		return (dest);
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = 0;
	return (dest);
}

/**
 * _strdup -> duplicate str
 * @str -> str to duplicate
 *
 * Return -> pointer to duplicated str
 */
char *_strdup(const char *str)
{
	char *ret;
	int length = 0;

	if (str == NULL)
		return (NULL);
	while (*str++)
		length++;
	ret = malloc(sizeof(char) * (length + 1));
	if (!ret)
		return (NULL);
	for (length++; length--;)
		ret[length] = *--str;
	return (ret);
}

/**
 *_puts -> print input str
 *@str -> str to be printed
 *
 * Return -> None
 */
void _puts(char *str)
{
	int i = 0;

	if (!str)
		return;
	while (str[i] != '\0')
	{
		_putchar(str[i]);
		i++;
	}
}

/**
 * _putchar -> write char c to stdout
 * @c ->  char to print
 *
 * Return ->  1 (success) , -1 (error)
 */
int _putchar(char c)
{
	static char buf[WRITE_BUF_SIZE];
	static int i;

	if ((c == BUF_FLUSH) || (i >= WRITE_BUF_SIZE))
	{
		write(1, buf, i);
		i = 0;
	}
	if (c != BUF_FLUSH)
		buf[i++] = c;
	return (1);
}


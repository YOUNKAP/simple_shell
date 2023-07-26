#include "shell.h"

/**
 *_eputs -> print string input
 * @str ->  the printed string
 *
 * Return: None
 */
void _eputs(char *str)
{
	int i = 0;

	if (!str)
		return;
	while (str[i] != '\0')
	{
		_eputchar(str[i]);
		i++;
	}
}

/**
 * _eputchar -> write char c to stderr
 * @c -> char to print
 *
 * Return:  1 for success, -1 for error
 */
int _eputchar(char c)
{
	static char buf[WRITE_BUF_SIZE];
	static int i;

	if ((c == BUF_FLUSH) || (i >= WRITE_BUF_SIZE))
	{
		write(2, buf, i);
		i = 0;
	}
	if (c != BUF_FLUSH)
		buf[i++] = c;
	return (1);
}

/**
 * _putfd -> write char c to given fd
 * @c -> char to print
 * @fd -> file descriptor to write to
 *
 * Return -> 1 for success, -1 for error
 */
int _putfd(int fd, char c)
{
	static char buf[WRITE_BUF_SIZE];
	static int i;

	if ((c == BUF_FLUSH) || (i >= WRITE_BUF_SIZE))
	{
		write(fd, buf, i);
		i = 0;
	}
	if (c != BUF_FLUSH)
		buf[i++] = c;
	return (1);
}

/**
 *_putsfd -> print input str
 * @str -> string to print
 * @fd -> file descriptor to write to
 *
 * Return -> numbers of char put
 */
int _putsfd(int fd, char *str)
{
	int i = 0;

	if (!str)
		return (0);
	while (*str)
	{
		i += _putfd(*str++, fd);
	}
	return (i);
}

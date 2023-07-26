#include "shell.h"

/**
 * _erratoi -> convert str to int
 * @s -> str to be converted
 * Return -> 0 if str,-1 on error
 */
int _erratoi(char *s)
{
	unsigned long int result = 0;
	int i = 0;

	if (*s == '+')
		s++;  
	for (i = 0;  s[i] != '\0'; i++)
	{
		if ((s[i] >= '0') && (s[i] <= '9'))
		{
			result *= 10;
			result += (s[i] - '0');
			if (result > INT_MAX)
				return (-1);
		}
		else
			return (-1);
	}
	return (result);
}

/**
 * print_error -> print error
 * @info -> parameter & return info struct
 * @estr -> str error type
 * Return -> 0 if str, -1 on error
 */
void print_error( char *estr, info_t *info)
{
	_eputs(info->fname);
	_eputs(": ");
	print_d(info->line_count, STDERR_FILENO);
	_eputs(": ");
	_eputs(info->argv[0]);
	_eputs(": ");
	_eputs(estr);
}

/**
 * print_d -> funct print decimal (integer) num (base 10)
 * @input -> input
 * @fd -> file descriptor
 *
 * Return -> num of char printed
 */
int print_d(int fd, int input)
{
	int (*__putchar)(char) = _putchar;
	unsigned int _abs_, current;
	int i, count = 0;

	if (fd == STDERR_FILENO)
		__putchar = _eputchar;
	if (input < 0)
	{
		_abs_ = -input;
		__putchar('-');
		count++;
	}
	else
		_abs_ = input;
	current = _abs_;
	for (i = 1000000000; i > 1; i /= 10)
	{
		if (_abs_ / i)
		{
			__putchar('0' + current / i);
			count++;
		}
		current %= i;
	}
	__putchar('0' + current);
	count++;

	return (count);
}

/**
 * convert_number -> convert funct,clone of itoa
 * @num -> number
 * @base -> base
 * @flags -> arg flags
 *
 * Return -> str
 */
char *convert_number(int base, long int num, int flags)
{
	static char buffer[50];
	static char *array;
	char *ptr;
	char sign = 0;
	unsigned long n = num;

	if ((!(flags & CONVERT_UNSIGNED)) && (num < 0))
	{
		sign = '-';
		n = -num;

	}
	array = flags & CONVERT_LOWERCASE ? "0123456789abcdef" : "0123456789ABCDEF";
	ptr = &buffer[49];
	*ptr = '\0';

	do	{
		*--ptr = array[n % base];
		n /= base;
	} while (n != 0);

	if (sign)
		*--ptr = sign;
	return (ptr);
}

/**
 * remove_comments -> funct replace instance of '#' with '\0'
 * @buf -> addr of the str to modify
 *
 * Return -> 0;
 */
void remove_comments(char *buf)
{
	int i;

	for (i = 0; buf[i] != '\0'; i++)
		if (buf[i] == '#' && (!i || buf[i - 1] == ' '))
		{
			buf[i] = '\0';
			break;
		}
}

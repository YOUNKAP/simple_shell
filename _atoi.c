#include "shell.h"

/**
 * interactive - return (true)  if shell is interactive mode
 * @info: struct addr
 *
 * Return: 1  (interactive mode), 0 other)
 */
int interactive(info_t *info)
{
	return (isatty(STDIN_FILENO) && info->readfd <= 2);
}

/**
 * is_delim - check  char delimeter
 * @c:  char to check
 * @delim: the delimeter str
 * Return: 1  (true), 0 (false)
 */
int is_delim(char c, char *delim)
{
	while (*delim)
		if (*delim++ == c)
			return (1);
	return (0);
}

/**
 *_isalpha - checks alphabetic char
 *@c: input char 
 *Return:  1 (c alphabetic), 0 (other)
 */

int _isalpha(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (1);
	else
		return (0);
}

/**
 *_atoi - converts  str to  int
 *@s: str to convert
 *Return: 0  (no num str)
 */

int _atoi(char *s)
{
	int i, sign = 1; 
	unsigned int result = 0;
	int flag = 0, output;

	for (i = 0;  s[i] != '\0' && flag != 2; i++)
	{
		if (s[i] == '-')
			sign *= -1;

		if (s[i] >= '0' && s[i] <= '9')
		{
			flag = 1;
			result *= 10;
			result += (s[i] - '0');
		}
		else if (flag == 1)
			flag = 2;
	}

	if (sign == -1)
		output = -result;
	else
		output = result;

	return (output);
}

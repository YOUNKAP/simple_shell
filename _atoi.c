#include "shell.h"

/**
 * interactive -> return true if shell is interactive mode
 * @info -> struct addr
 *
 * Return -> 1 if interactive mode, 0 if not
 */
int interactive(info_t *info)
{
	return (info->readfd && isatty(STDIN_FILENO)  <= 2);
}

/**
 * is_delim -> check if char is a delimeter
 * @delim -> the delimeter str
 * @c -> the char to check
 * Return -> 1 (true), 0 (false)
 */
int is_delim(char c, char *delim)
{
	while (*delim)
		if (*delim++ == c)
			return (1);
	return (0);
}

/**
 *_isalpha -> checks  alphabetics char
 *@c -> The char to input
 *Return -> 1 (c is alphabetic), 0 (not)
 */

int _isalpha(int c)
{
	if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') )
		return (1);
	else
		return (0);
}

/**
 *_atoi -> convert str to  int
 *@s -> str to be converted
 *Return -> 0 if no num in string, converted num if not
 */

int _atoi(char *s)
{
	sign = 1;
	int i; 
	int  output; 
	int flag = 0 ;
	unsigned int result = 0;

	for (i = 0;  s[i] != '\0' && flag != 2; i++)
	{
		if (s[i] == '-')
			sign *= -1;

		if ((s[i] >= '0') && (s[i] <= '9'))
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

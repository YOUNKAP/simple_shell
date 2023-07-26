#include "shell.h"

/**
 * bfree - frees a point  the addr
 * @ptr: addr  free
 *
 * Return: 1 (freed), 0 (other)
 */
int bfree(void **ptr)
{
	if (ptr && *ptr)
	{
		free(*ptr);
		*ptr = NULL;
		return (1);
	}
	return (0);
}
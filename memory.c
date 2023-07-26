#include "shell.h"

/**
 * bfree -> free pointer and NULL addr
 * @ptr -> addr pointer to free
 *
 * Return -> 1 (success), 0 (other)
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
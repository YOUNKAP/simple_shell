#include "shell.h"

/**
 **_memset -> fill  memory constant byte
 *@s -> pointer to memory area
 *@b -> byte to fill *s with
 *@n -> amount of bytes to be filled
 *Return -> (s) a pointer to memory area s
 */
char *_memset(char *s, char b, unsigned int n)
{
	unsigned int i;

	for (i = 0; i < n; i++)
		s[i] = b;
	return (s);
}

/**
 * ffree -> free str of str
 * @pp -> str of str
 */
void ffree(char **pp)
{
	char **a = pp;

	if (!pp)
		return;
	while (*pp)
		free(*pp++);
	free(a);
}

/**
 * _realloc -> reallocate a block memory
 * @ptr -> pointer to previous malloc'ated block
 * @old_size -> byte size of block
 * @new_size -> byte size of block
 *
 * Return -> pointer to da ol'block
 */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	char *p;

	if (!ptr)
		return (malloc(new_size));
	if (!new_size)
		return (free(ptr), NULL);
	if (new_size == old_size)
		return (ptr);

	p = malloc(new_size);
	if (!p)
		return (NULL);

	old_size = old_size < new_size ? old_size : new_size;
	while (old_size--)
		p[old_size] = ((char *)ptr)[old_size];
	free(ptr);
	return (p);
}
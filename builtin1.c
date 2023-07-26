#include "shell.h"

/**
 * _myhistory -> displays the hist list
 * @info -> Structure containing potential arg
 *  Return -> 0
 */
int _myhistory(info_t *info)
{
	print_list(info->history);
	return (0);
}

/**
 * unset_alias -> set alias  into str
 * @str -> str alias
 * @info -> parameter struct
 *
 * Return -> 0  (success), 1 (errors)
 */
int unset_alias(info_t *info, char *str)
{
	int ret;
	char c;
	char *p;
	
	p = _strchr(str, '=');
	if (!p)
		return (1);
	c = *p;
	*p = 0;
	ret = delete_node_at_index(&(info->alias),
		get_node_index(info->alias, node_starts_with(info->alias, str, -1)));
	*p = c;
	return (ret);
}

/**
 * set_alias -> sets alias to str
 * @str -> the str alias
 * @info -> parameter struct
 *
 * Return -> 0 (success), 1 (error)
 */
int set_alias(info_t *info, char *str)
{
	char *p;

	p = _strchr(str, '=');
	if (!p)
		return (1);
	if (!*++p)
		return (unset_alias(str, info));

	unset_alias(str, info);
	return (add_node_end(&(info->alias), str, 0) == NULL);
}

/**
 * print_alias -> prints alias
 * @node -> alias node
 *
 * Return -> 0 (success), 1 (error)
 */
int print_alias(list_t *node)
{
	char *p = NULL;
	char *a = NULL;

	if (node)
	{
		p = _strchr(node->str, '=');
		for (a = node->str; a <= p; a++)
			_putchar(*a);
		_putchar('\'');
		_puts(p + 1);
		_puts("'\n");
		return (0);
	}
	return (1);
}

/**
 * _myalias -> mimic alias builtin  : man alias
 * @info -> Structure containing potential arg
 *  Return -> 0
 */
int _myalias(info_t *info)
{
	char *p = NULL;
	int i = 0;
	list_t *node = NULL;

	if (info->argc == 1)
	{
		node = info->alias;
		while (node)
		{
			print_alias(node);
			node = node->next;
		}
		return (0);
	}
	for (i = 1; info->argv[i]; i++)
	{
		p = _strchr(info->argv[i], '=');
		if (p)
			set_alias(info, info->argv[i]);
		else
			print_alias(node_starts_with(info->alias, info->argv[i], '='));
	}

	return (0);
}

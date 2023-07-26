#include "shell.h"

/**
 * _myenv -> prints current env
 * @info -> Contain potential arg
 * Return -> 0
 */
int _myenv(info_t *info)
{
	print_list_str(info->env);
	return (0);
}

/**
 * _getenv -> get env var
 * @name -> env var name
 * @info -> Contain potential arg
 *
 * Return -> Value
 */
char *_getenv(info_t *info, const char *name)
{
	char *p;
	list_t *node = info->env;

	while (node)
	{
		p = starts_with(node->str, name);
		if (p && *p)
			return (p);
		node = node->next;
	}
	return (NULL);
}

/**
 * _mysetenv -> Initialize env var 
 * @info -> Structure contain potential arg
 *  Return -> 0
 */
int _mysetenv(info_t *info)
{
	if (info->argc != 3)
	{
		_eputs("Incorrect number of arguements\n");
		return (1);
	}
	if (_setenv(info, info->argv[1], info->argv[2]))
		return (0);
	return (1);
}

/**
 * _mysetenv -> Initialize env var
 * @info -> Structure containing potential arg
 *  Return -> 0
 */
int _myunsetenv(info_t *info)
{
	int i;

	if (info->argc == 1)
	{
		_eputs("Too few arguements.\n");
		return (1);
	}
	for (i = 1; i <= info->argc; i++)
		_unsetenv(info, info->argv[i]);

	return (0);
}

/**
 * populate_env_list -> populates env linked list
 * @info -> Containing potential argument
 * Return -> 0
 */
int populate_env_list(info_t *info)
{
	size_t i;
	list_t *node = NULL;

	for (i = 0; environ[i]; i++)
		add_node_end(&node, environ[i], 0);
	info->env = node;
	return (0);
}

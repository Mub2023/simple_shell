#include "shell.h"
/**
 * _myhistory - display the history list one command by line,
 * preceded with line numbers, starting at 0
 * @info: structure continaing potential argu
 * Return:Always 0 (Success)
 */
int _myhistory(info_t *info)
{
	print_list(info->history);
	return (0);
}
/**
 * unset_alias - sets alias to string.
 * @info: stuct perameter
 * @str: the pointer of the string.
 * Return: Always 0 (Success) or 1 on error.
 */
int unset_alias(info_t *info, char *str)
{
	char *p, c;
	int x;

	p = _strchr(str, '=');
	if (!p)
		return (1);

	c = *p;
	*p = 0;
	x = delete_node_at_index(&(info->alias),
			get_node_index(info->alias, node_starts_with(info->alias, str, -1)));
	*p = c;
	return (x);
}
/**
 * set_alias - sets alias to string.
 * @info: parameter struct
 * @str: the pointer of the string.
 * Return: Always 0(Success) or 1 on error.
 */
int set_alias(info_t *info, char *str)
{
	char *p;

	p = _strchr(str, '=');
	if (!p)
		return (unset_alias(info, str));

	unset_alias(info, str);
	return (add_node_end(&(info->alias), str, 0) == NULL);
}
/**
 * print_alias - prints an alias string
 * @node: the alias node.
 * Return: Always 0 (Suceess) or 1 otherwise
 */
int print_alias(list_t *node)
{
	char *p = NULL, *a = NULL;

	if (node)
	{
		p = _strchr(node->str, '=');
		for (a = node->str; a <= p; a++)
			_putchar(*a);
		_putchar('\'');
		_puts(p + 1);
		puts("'\n");
		return (0);
	}
	return (1);
}
/**
 * _myalias - mimics the alias builtin
 * @info: struct paramter.
 * Return: Always 0 (Success)
 */
int _myalias(info_t *info)
{
	int x = 0;
	char *p = NULL;
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
	for (x = 1; info->argv[x]; x++)
	{
		p = _strchr(info->argv[x], '=');
		if (p)
			set_alias(info, info->argv[x]);
		else
			print_alias(node_starts_with(info->alias, info->argv[x], '='));
	}
	return (0);
}

#include "header.h"

int			check_norm(t_list *list)
{
	if (list->col < SIZE || list->count != SIZE || list->let >= 'Z')
		return (0);
	return (1);
}

int			allocate_mem(t_list **list, int count)
{
	*list = (t_list *)malloc(sizeof(t_list));
	(*list)->str = (char *)malloc(sizeof(char) * 5);
	(*list)->include = (char **)malloc(sizeof(char *) * 5);
	if (!(*list) || !(*list)->str || !(*list)->include)
		return (0);
	(*list)->line = 0;
	(*list)->col = 0;
	(*list)->next = NULL;
	(*list)->count = 0;
	(*list)->x_coord = 0;
	(*list)->y_coord = 0;
	((*list)->let) = 'A' + count;
	return (1);
}

void		if_find_sharp(t_list *list, char *c)
{
	if (*c == '#')
	{
		list->x[list->count] = list->line;
		list->y[list->count] = list->col;
		list->count++;
		*c = list->let;
	}
}

int			makelist(t_list *list, char c)
{
	if_find_sharp((list), &c);
	if (list->col < SIZE)
		if (list->line < SIZE)
		{
			list->str[list->line] = c;
			(list->line)++;
		}
		else
		{
			if (c != '\n')
				return (-1);
			list->str[list->line] = '\0';
			list->include[list->col] = ft_strdup(list->str);
			(list->col)++;
			list->line = 0;
		}
	else
	{
		if (c != '\n')
			return (-1);
		list->include[list->col] = NULL;
		return (1);
	}
	return (0);
}

void		find_prev(t_list *new, t_list **list)
{
	if (new)
	{
		while (new->next)
			new = new->next;
		(*list)->prev = new;
	}
	else
		(*list)->prev = NULL;
}

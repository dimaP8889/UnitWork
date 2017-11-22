/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getmap.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpogrebn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 17:03:09 by dpogrebn          #+#    #+#             */
/*   Updated: 2017/11/17 17:03:10 by dpogrebn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		check_norm(t_list *list)
{
	if (list->col < SIZE || list->count != SIZE || list->let > 'Z')
		return (0);
	return(1);
}

int		allocate_mem(t_list **list, int count)
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
	((*list)->let) = 'A' + count;
	return (1);
}

void	if_find_sharp(t_list *list, char *c)
{
	if (*c == '#')
	{
		list->x[list->count] = list->line;
		list->y[list->count] = list->col;
		list->count++;
		*c = list->let;
	}
}

int		makelist(t_list *list, char c)
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

int		func_ret_one(int *count, t_list	**new, t_list **list)
{
	if(!check_norm(*list) || !check_sharps(*list))
		return (0);
	(*count)++;
	ft_lstaddlast(new, *list);
	if (!allocate_mem(list, *count))
		return (0);
	return (1);
}

t_list		*takelist(int fd, char *c, int func_ret, t_list *list)
{
	t_list	*new;
	int		count;

	count = 0;
	new = NULL;
	while (read(fd, c, 1))
	{
		if (*c != '#' && *c != '.' && *c != '\n')
			return (0);
		func_ret = makelist(list, *c);
		if (func_ret == 1)
		{
			if (!func_ret_one(&count, &new, &list))
				return (0);
		}
		if (func_ret == -1)
			return (0);
	}
	if(!check_norm(list) || !check_sharps(list))
		return (0);
	count++;
	ft_lstaddlast(&new, list);
	return (new);
}

t_list		*getmap(char **argv)
{
	int		fd;
	char	c[1];
	int		func_ret;
	t_list	*list;
	t_list	*new;

	func_ret = 0;
	if (!allocate_mem(&list, 0))
		return (0);
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		return (0);
	new = takelist(fd, c, func_ret, list);
	return (new);
}

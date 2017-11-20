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

int		check_mass_for_sharp(char **mass)
{
	(void)(mass);
	return (0);
}

int 	find_bad(char **mass)
{
	int		col;
	int		line;
	int		count_sharps;

	count_sharps = 0;
	col = 0;
	line = 0;
	while (mass[col])
	{
		while (mass[line])
		{
			if (mass[col][line] == '#')
				if (!check_mass_for_sharp(mass))
					return (0);
				return (1);
			line++;
		}
		col++;
		line = 0;
	}
	return (0);
}

int		check_sharps(t_list *list)
{
	while (list)
	{
		if (find_bad(list->include))
			return (0);
		list = list->next;
	}
	return (1);
}

int		check_norm(t_list *list)
{
	if (list->col < COL || list->count != 4)
		return (0);
	return(1);
}

int		allocate_mem(t_list **list)
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
	return (1);
}


int		makelist(t_list **list, char c)
{
	if (c == '#')
		(*list)->count++;
	if ((*list)->col < COL)
		if ((*list)->line < LINE)
		{
			(*list)->str[(*list)->line] = c;
			((*list)->line)++;
		}
		else
		{
			if (c != '\n')
				return (-1);
			(*list)->str[(*list)->line] = '\0';
			(*list)->include[(*list)->col] = ft_strdup((*list)->str);
			((*list)->col)++;
			(*list)->line = 0;
		}
	else
	{
		if (c != '\n')
			return (-1);
		(*list)->include[(*list)->col] = NULL;
		return (1);
	}
	return (0);
}

t_list		*takelist(int fd, char *c, int func_ret, t_list *list)
{
	t_list	*new;

	new = NULL;
	while (read(fd, c, 1))
	{
		if (*c != '#' && *c != '.' && *c != '\n')
			return (0);
		func_ret = makelist(&list, *c);
		if (func_ret == 1)
		{
			if(!check_norm(list))
				return (0);
			ft_lstaddlast(&new, list);
			if (!allocate_mem(&list))
				return (0);
		}
		if (func_ret == -1)
			return (0);
	}
	if(!check_norm(list))
		return (0);
	ft_lstaddlast(&new, list);
	// if (!check_sharps(new))
	// 	return (0);
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
	if (!allocate_mem(&list))
		return (0);
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		return (0);
	new = takelist(fd, c, func_ret, list);
	return (new);
}
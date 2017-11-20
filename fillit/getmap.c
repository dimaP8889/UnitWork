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

int		makelist(t_list **list, char c)
{
	if ((*list)->col < COL)
	{
		if ((*list)->line < LINE)
		{
			if (c == '\n')
				return (-1);
			(*list)->str[(*list)->line] = c;
			((*list)->line)++;
		}
		else
		{
			if (c != '\n')
				return (-1);
			(*list)->str[(*list)->line] = '\0';
			(*list)->content[(*list)->col] = (*list)->str;
			((*list)->col)++;
			(*list)->line = 0;
		}
	}
	else
	{
		if (c != '\n')
			return (-1);
		(*list)->content[(*list)->col] = NULL;
		(*list)->line = 0;
		(*list)->col = 0;
		return (1);
	}
	return (0);
}

t_list		*getmap(int argc, char **argv)
{
	int		fd;
	int		ret;
	char	c;
	int		func_ret;
	t_list	*list;

	list = (t_list *)malloc(sizeof(t_list));
	fd = open(argv[1], O_RDONLY);
	if (fd == -1 || !list)
		return (0);
	list->str = (char *)malloc(sizeof(char) * 5);
	list->content = (char **)malloc(sizeof(char) * 5);
	while (ret == read(fd, c, 1))
	{
		if (c != '#' || c != '.' || c != '\n')
			return (0);
		func_ret = makelist(&list, c);
		if (func_ret == 1)
		{
			ft_lstadd(&list, list);
			free(list);
		}
		if (func_ret == -1)
			return (0);
		if (func_ret == 0)
			continue ;
	}
	return (list);
}
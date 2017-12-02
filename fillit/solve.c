/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpogrebn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/22 16:19:47 by dpogrebn          #+#    #+#             */
/*   Updated: 2017/11/22 16:19:48 by dpogrebn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	make_square_bigger(char ***mass)
{
	char	**map;
	int		col;
	int		line;
	int		count;

	map = *mass;
	col = 0;
	line = 0;
	while (map[col][line] != ',')
	{
		while (map[col][line] != ',')
			line++;
		map[col][line] = '.';
		col++;
		count = line;
		line = 0;
	}
	while (count > -1)
	{
		map[col][line] = '.';
		count--;
		line++;
	}
	col = 0;
}

int		find_sqrt(int count)
{
	int a;

	a = 0;
	while (a * a < count)
		a++;
	if (a * a != count)
		return (2 * a - 1);
	return (2 * a);
}

char	**makemass(int count)
{
	char	**solve;
	int		line;
	int		col;
	int		min_size;

	line = 0;
	col = 0;
	min_size = find_sqrt(count);
	solve = (char **)malloc(sizeof(char *) * (MAXSIZE + 1));
	while (col < MAXSIZE)
	{
		solve[col] = (char *)malloc(sizeof(char) * (MAXSIZE + 1));
		while (line < MAXSIZE)
		{
			if (col < min_size && line < min_size)
				(solve[col][line++]) = '.';
			else
				(solve[col][line++]) = ',';
		}
		solve[col][line] = '\0';
		line = 0;
		col++;
	}
	solve[col] = NULL;
	return (solve);
}

void	algo(t_list *new, char **mass)
{
	int		res;

	while (new)
	{
		res = ft_make_figure(new, &mass);
		if (!res)
		{
			make_square_bigger(&mass);
			while (new->prev)
				new = new->prev;
		}
		else if (res == -1)
			new = new->prev;
		else
			new = new->next;
	}
}

char	**solve(t_list *list)
{
	char	**mass;
	t_list	*new;
	int		count;

	count = 0;
	new = list;
	while (list)
	{
		make_optimal(list);
		count++;
		list = list->next;
	}
	mass = makemass(count);
	algo(new, mass);
	return (mass);
}

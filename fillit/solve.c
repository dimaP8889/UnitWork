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
#define MAXSIZE 72

void	check_optimal_y(t_list *list, int check)
{
	int		coord;
	int		min;

	min = check;
	coord = 0;
	while (coord < SIZE)
	{
		if (list->y[coord] < min)
			min = list->x[coord];
		coord++;
	}
	coord = 0;
	if (min > 0)
	{
		while (coord < SIZE)
		{
			list->y[coord] = list->y[coord] - min;
			coord++;
		}
	}
}

void	check_optimal_x(t_list *list, int check)
{
	int		coord;
	int		min;

	min = check;
	coord = 0;
	while (coord < SIZE)
	{
		if (list->x[coord] < min)
			min = list->x[coord];
		coord++;
	}
	coord = 0;
	if (min > 0)
	{
		while (coord < SIZE)
		{
			list->x[coord] = list->x[coord] - min;
			coord++;
		}
	}
}

void	make_optimal(t_list *list)
{
	int		x;
	int		y;

	x = list->x[0];
	y = list->y[0];
	check_optimal_x(list, x);
	check_optimal_y(list, y);
}

char	**makemass(void)
{
	char	**mass;
	char	**solve;
	int		line;
	int		col;

	line = 0;
	col = 0;
	solve = (char **)malloc(sizeof(char *) * (MAXSIZE + 1));
	mass = solve;
	while (col < MAXSIZE)
	{
		solve[col] = (char *)malloc(sizeof(char) * (MAXSIZE + 1));
		while (line < MAXSIZE)
			(solve[col][line++]) = '.';
		solve[col][line] = '\0';
		line = 0;
		col++;
	}
	solve[col] = NULL;
	return (mass);
}

char	**solve(t_list *list)
{
	char	**mass;
	int		index;
	int		count;

	count = 1;
	index = 0;
	mass = makemass();
	make_optimal(list);
	//making_figure(list, mass);
	return (NULL);
}

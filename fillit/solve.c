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

int		find_sqrt(int count)
{
	int a;

	a = 0;
	while (a * a < count)
		a++;
	printf("%i\n", 2 * a);
	return (2 * a);
}

char	**makemass(int count)
{
	char	**mass;
	char	**solve;
	int		line;
	int		col;
	int		min_size;

	line = 0;
	col = 0;
	min_size = find_sqrt(count);
	solve = (char **)malloc(sizeof(char *) * (MAXSIZE + 1));
	mass = solve;
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
	return (mass);
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
		//printf("%i\n", list->count_lists);
		list = list->next;
	}
	//printf("%i\n", count);
	mass = makemass(count);
	//making_figure(list, mass);
	ft_make_figure(new, &mass);
	printf("test3\n");
	return (NULL);
}

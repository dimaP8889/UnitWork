#include "header.h"

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

#include "header.h"

int		check_places(t_list *list, char **map, int col, int line)
{
	int count;
	int dif_x;
	int dif_y;

	count = 0;
	dif_x = list->x[0] - 0;
	dif_y = list->y[0] - 0;
	if (dif_x > line || dif_y > col)
		return (0);
	while (count < SIZE)
	{
		if (map[list->y[count] + col - dif_y]
			[list->x[count] + line - dif_x] != '.')
			return (0);
		count++;
	}
	return (1);
}

void	fill_mapp(t_list *list, char **map, int col, int line)
{
	int count;
	int dif_x;
	int dif_y;

	count = 0;
	dif_x = list->x[0] - 0;
	dif_y = list->y[0] - 0;
	while (count < SIZE)
	{
		(map[list->y[count] + col - dif_y]
			[list->x[count] + line - dif_x]) = list->let;
		count++;
	}
}

int		try_figure(t_list *list, char **map, t_mass *nasa)
{
	nasa->col = list->y_coord;
	nasa->line = list->x_coord;
	while (map[nasa->col][nasa->line] != ',')
	{
		while (map[nasa->col][nasa->line] != ',')
		{
			if (map[nasa->col][nasa->line] == '.')
				if (check_places(list, map, nasa->col, nasa->line))
				{
					fill_mapp(list, map, nasa->col, nasa->line);
					list->x_coord = nasa->line;
					list->y_coord = nasa->col;
					return (1);
				}
			nasa->line++;
		}
		list->size = nasa->line;
		nasa->col++;
		nasa->line = 0;
	}
	list->x_coord = 0;
	list->y_coord = 0;
	return (0);
}

void	clean_map(char ***mass, t_list *list)
{
	char	**map;
	int		col;
	int		line;

	map = *mass;
	col = 0;
	line = 0;
	while (map[col][line] != ',')
	{
		while (map[col][line] != ',')
		{
			if (map[col][line] == list->let - 1)
				map[col][line] = '.';
			line++;
		}
		col++;
		line = 0;
	}
}

int		ft_make_figure(t_list *list, char ***mass)
{
	t_mass	*nasa;

	nasa = (t_mass *)malloc(sizeof(t_mass));
	if (try_figure(list, *mass, nasa))
		return (1);
	else
	{
		clean_map(mass, list);
		if (list->prev == NULL)
			return (0);
		if (list->prev)
		{
			list->prev->x_coord++;
			if (list->prev->x_coord == list->size)
			{
				list->prev->x_coord = 0;
				list->prev->y_coord++;
			}
		}
	}
	return (-1);
}

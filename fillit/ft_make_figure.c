#include "header.h"

int		check_places(t_list *list, char **map, int col, int line)
{
	int count;
	int dif;

	count = 0;
	dif = list->x[0] - 0;
	if (dif > line)
		return (0);
	while (count < SIZE)
	{
		if (map[list->y[count] + col][list->x[count] + line - dif] != '.')
			return (0);
		count++;
	}
	return (1);
}

void	fill_mapp(t_list *list, char **map, int col, int line)
{
	int count;
	int dif;

	count = 0;
	dif = list->x[0] - 0;
	while (count < SIZE)
	{
		(map[list->y[count] + col][list->x[count] + line - dif]) = list->let;
		count++;
	}
}

int		try_figure(t_list *list, char **map)
{
	int col;
	int line;

	col = list->y_coord;
	line = list->x_coord;
	while (map[col][line] != ',')
	{
		while (map[col][line] != ',')
		{
			if (map[col][line] == '.')
				if (check_places(list, map, col, line))
				{
					list->x_coord = line;
					list->y_coord = col;
					fill_mapp(list, map, col, line);
					return (1);
				}
			line++;
		}
		col++;
		line = 0;
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

void	make_square_bigger(char ***mass)
{
	char	**map;
	int col;
	int line;
	int	count;

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

void	ft_make_figure(t_list *list, char ***mass)
{
	char	**map;
	int		index;

	index = 0;
	map = *mass;
	if (list == NULL)
		return ;
	if (try_figure(list, *mass))
	{
		list = list->next;
		if (list == NULL)
			return ;
		while (index < 15)
		{
			printf("%s\n", map[index]);
			index++;
		}
		printf("\n");
		ft_make_figure(list, mass);
	}
	else
	{
		clean_map(mass, list);
		printf("back\n");
		while (index < 15)
		{
			printf("%s\n", map[index]);
			index++;
		}
		printf("\n");
		if (list->prev == NULL)
		{
			make_square_bigger(mass);
			ft_make_figure(list, mass);
		}
		if (list->prev)
			list->prev->x_coord++;
		ft_make_figure(list->prev, mass);
	}
}
#include "header.h"

int		check_places(t_list *list, char **map, int col, int line)
{
	int count;

	count = 0;
	while (count < SIZE)
	{
		if (map[list->y[count] + col][list->x[count] + line] != '.')
			return (0);
		count++;
	}
	return (1);
}

void	fill_mapp(t_list *list, char **map, int col, int line)
{
	(void)list;
	int count;

	count = 0;
	while (count < SIZE)
	{
		(map[list->y[count] + col][list->x[count] + line]) = list->let;
		count++;
	}
}

int		try_figure(t_list *list, char **map)
{
	int col;
	int line;

	col = 0;
	line = 0;
	while (map[col][line] != ',')
	{
		while (map[col][line] != ',')
		{
			if (map[col][line] == '.')
			{
				if (check_places(list, map, col, line))
				{
					fill_mapp(list, map, col, line);
					return (1);
				}
			}
			line++;
		}
		col++;
		line = 0;
	}
	return (0);
}

int		ft_make_figure(t_list *list, char ***mass)
{
	char	**map;

	map = *mass;
	if (try_figure(list, map))
	{
		while (*map)
		{
			printf("%s\n", *map);
			map++;
		}
		list = list->next;
		if (list = NULL)
			return (1);
		// ft_make_figure(list, &map);
	}
	else
	{
		printf("loh\n");
		// if(!change_poss(list))
		// 	return (0);
		// ft_make_figure(list, &map);
	}
	return (0);
}
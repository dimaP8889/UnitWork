/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pizza.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpogrebn <dpogrebn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/28 21:22:11 by dpogrebn          #+#    #+#             */
/*   Updated: 2018/02/28 22:45:43 by dpogrebn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pizza.h"

void	ft_count(char **map, t_params	*size)
{
	static int 	T;
	static int	M;
	int x;
	int count;

	count = 0;
	x = 0;
	while (map[count])
	{
		while (map[count][x])
		{
			if (map[count][x] == 'T')
				T++;
			if (map[count][x] == 'M')
				M++;
			x++;
		}
		x = 0;
		count++;
	}
	size->T = T;
	size->M = M;
	printf("T :%i\n", T);
	printf("M :%i\n", M);
}

int ft_find_same(t_params	*size) 
{
    int a;
    int b;
    a = size->T;
    b = size->M;

	while (a && b)
	{
		if (a > b)
			a = a % b;
		if (a < b)
			b = b % a;
		if (a % b == 0 || b % a == 0)
			break;
	}
	if (a > b)
		size->same = a;
	else if (b > a)
		size->same = b;
	else
		size->same = 1;
    //printf("%lu", a | b);

    printf("%i\n", size->same);
    return (0);
}

int	main(int ac, char **av)
{
	char		*line;
	char		**params;
	char		**map;
	int			fd;
	int			count;
	t_params	*size;

	count = 0;
	size = (t_params *)malloc(sizeof(t_params));
	fd = open(av[1], O_RDONLY);
	get_next_line(fd, &line);
	params = ft_strsplit(line, ' ');
	size->rows = ft_atoi(params[0]);
	size->col = ft_atoi(params[1]);
	size->min = ft_atoi(params[2]);
	size->max = ft_atoi(params[3]);
	free(line);
	map = (char **)malloc(sizeof(char *) * size->rows + 1);
	map[count] = ft_strnew(size->col + 1);
	while (get_next_line(fd, &map[count]))
	{
		count++;
		map[count] = ft_strnew(size->col + 1);
	}
	map[count] = NULL;
	count = 0;

	ft_count(map, size);
	ft_find_same(size);
	// while (map[count])
	// {
	// 	printf("%s\n", map[count]);
	// 	count++;
	// }
	// printf("%i\n", size->rows);
	// printf("%i\n", size->col);
	// printf("%i\n", size->min);
	// printf("%i\n", size->max);
}
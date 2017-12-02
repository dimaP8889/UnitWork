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

int			func_ret_one(int *count, t_list **new, t_list **list)
{
	if (!check_norm(*list) || !check_sharps(*list))
		return (0);
	(*count)++;
	find_prev(*new, list);
	ft_lstaddlast(new, *list);
	if (!allocate_mem(list, *count))
		return (0);
	return (1);
}

t_list		*takelist(int fd, char *c, int func_ret, t_list *list)
{
	t_list	*new;
	int		count;

	count = 0;
	new = NULL;
	while (read(fd, c, 1))
	{
		if (*c != '#' && *c != '.' && *c != '\n')
			return (0);
		func_ret = makelist(list, *c);
		if (func_ret == 1)
		{
			if (!func_ret_one(&count, &new, &list))
				return (0);
		}
		if (func_ret == -1)
			return (0);
	}
	if (!check_norm(list) || !check_sharps(list))
		return (0);
	count++;
	find_prev(new, &list);
	ft_lstaddlast(&new, list);
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
	if (!allocate_mem(&list, 0))
		return (0);
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		return (0);
	new = takelist(fd, c, func_ret, list);
	close(fd);
	return (new);
}

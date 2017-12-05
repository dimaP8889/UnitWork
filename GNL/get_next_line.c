/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpogrebn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/04 13:07:42 by dpogrebn          #+#    #+#             */
/*   Updated: 2017/12/04 13:07:43 by dpogrebn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	check_buff(t_gnl *list, char **mass)
{
	int		line;
	int		count;

	line = list->coord[0];
	count = list->count_back_slash[0];
	while ((list->c[line] != '\n' && count >= 0) || list->c[line] = '\0')
	{
		*(mass[line]) = list->c[line];
		line++;
		if (list->c[line] == '\n')
			count--;
	}
	if (list->c[line] = '\0')
		return (1);
	list->coord[0] = line;
	list->count_back_slash[0]++;
	return (0);
}

int get_next_line(const int fd, char **line)
{
	t_gnl	*new;

	new = (t_gnl *)malloc(sizeof(t_gnl));
	listec->list = NULL;
	if (check_buff(new, line))
	{
		read(fd, new->c, )
		new->list = ft_lstnew(new->c, ft_strlen(new->c));
		ft_lstaddlast(&listec->list, new->list);
	}
	return (0);
}

int main(int ac,char **ag)
{
	(void)ac;
	int		fd;
	char	*mass;
	t_gnl	*new;

	fd = open(ag[1], O_RDONLY);
	printf("%i\n", fd);
	get_next_line(fd, &mass);
}
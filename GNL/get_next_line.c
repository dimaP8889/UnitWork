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

int	count_mem(t_gnl *work_list)
{
	int	index;

	index = 0;
	while (work_list->list)
	{
		while (work_list->list->content[index] != '\n' 
		|| work_list->list->content[index] != '\0')
			list->count_size++;
		if (work_list->list->content[index] == '\n')
			return (1);
		return (0);
	}
}

int	check_buff(t_gnl *work_list, char **mass)
{
	int		line;
	int		count_back_slash;
	int		index;

	index = 0;
	line = list->coord[0];
	count = list->count_back_slash[0];
	if (count_mem(work_list))
	{
		*mass = (char *)malloc(sizeof(char) * list->count_size + 1);
		ft_
	}
	// while ((list->c[line] != '\n' && count >= 0) || list->c[line] = '\0')
	// {
	// 	*(mass[line]) = list->c[line];
	// 	line++;
	// 	if (list->c[line] == '\n')
	// 		count--;
	// }
	if (list->c[line] = '\0')
		return (1);
	list->coord[0] = line;
	list->count_back_slash[0]++;
	return (0);
}

int get_next_line(const int fd, char **line)
{
	t_gnl	*new;
	t_gnl	*work_list;

	new = (t_gnl *)malloc(sizeof(t_gnl));
	work_list = NULL;
	if (check_buff(new, line))
	{
		read(fd, new->c, BUFSIZE);
		new->list = ft_lstnew(new->c, ft_strlen(new->c));
		ft_lstaddlast(&work_list->list, new->list);
		//list->count_lists = ft_lstcount(work_list);
		check_buff(work_list, line);
	}
	else
		return (1);
	return (get_next_line(fd, line));
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
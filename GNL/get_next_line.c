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

int	count_mem(t_gnl *new, const int fd)
{
	int	index;

	index = 0;
	read(fd, new->c, BUFSIZE);
	new->c[BUFSIZE] = '\0';
	while (new->c[index] != '\0')
	{
		if (new->c[index] == '\n' 
			&& new->check_back_slash = 1)
		{
			new->count_size = 0;
			new->check_back_slash = 0;
		}
		else if (new->c[index] == '\n' 
			&& new->c = 0)
		{
			new->check_back_slash = 0;
			return (0);
		}
		new->count_size++;
		index++;
	}
	return (1);
}

char	*make_arr(t_gnl *work_list, char *arr)
{

}

int	check_buff(t_gnl *work_list, char **arr, const int fd)
{
	t_gnl *new;

	new = (t_gnl *)malloc(sizeof(t_gnl));
	while (count_mem(work_list, fd))
	{
		new->list = ft_lstnew(new->c, ft_strlen(new->list));
		ft_lstaddlast(&work_list->list, new->list);
	}
	*arr = (char *)malloc(sizeof(char) * work_list->count_size);
	make_arr(work_list, arr);
}

int get_next_line(const int fd, char **line)
{
	static t_gnl *new;

	check_buff(new, line);
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
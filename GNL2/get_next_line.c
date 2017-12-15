/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpogrebn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 17:15:53 by dpogrebn          #+#    #+#             */
/*   Updated: 2017/12/14 17:15:54 by dpogrebn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <string.h>

void	ft_make_buf(t_gnl *new)
{
	char	*str;
	int		index;
	int		num;

	index = 0;
	num = new->ret;
	str = new->c;
	while (*str != '\n' && *str != '\0')
	{
		num--;
		str++;
	}
	str++;
	while (num > 0)
	{
		new->c[index] = *str;
		index++;
		str++;
		num--;
	}
	while (index < BUFF_SIZE + 1)
	{
		new->c[index] = '\0';
		index++;
	}
}

void	ft_lback(t_gnl **lst, t_gnl **work, int fd, char **line)
{
	t_gnl *new;
	t_gnl *elem;

	*work = (t_gnl *)malloc(sizeof(t_gnl));
	*line = (char *)malloc(sizeof(char) + 1);
	ft_memset((*work)->c, '\0', ft_strlen((*work)->c));
	elem = *work;
	elem->fd = fd;
	new = *lst;
	if ((*lst) && elem && lst)
	{
		while (new->next)
			new = new->next;
		new->next = elem;
	}
	if (*lst == NULL && elem != NULL && lst != NULL)
		*lst = elem;
}

int		ft_make_str(t_gnl *new, char **line)
{
	int		len;

	if (new->ret == 0)
		return (ft_strcmp(*line, "") ? 1 : 0);
	if (new->ret != BUFF_SIZE && new->str == NULL)
	{
		*line = ft_strdup(new->c);
		ft_make_buf(new);
		return (1);
	}
	len = new->str - new->c;
	if (new->str != NULL && new->ret != BUFF_SIZE)
	{
		len = 0;
		while (new->c[len] != '\n' && new->c[len] != '\0')
			len++;
	}
	new->str = ft_strsub(new->c, 0, len);
	new->str1 = *line;
	*line = ft_strjoin(new->str1, new->str);
	ft_make_buf(new);
	return (1);
}

int		ft_iter(t_gnl *new, char **line, int fd)
{
	char	*str;

	while (!(new->str = ft_strchr(new->c, '\n')) && new->ret != 0)
	{
		str = *line;
		*line = ft_strjoin(str, new->c);
		free(str);
		new->ret = read(fd, new->c, BUFF_SIZE);
		new->c[new->ret] = '\0';
		if (new->ret < 0)
			return (0);
	}
	return (1);
}

int		get_next_line(const int fd, char **line)
{
	static	t_gnl	*list;
	t_gnl			*new;

	if (fd < 0 || BUFF_SIZE < 0)
		return (-1);
	if (!list)
	{
		list = (t_gnl *)malloc(sizeof(t_gnl));
		*line = (char *)malloc(sizeof(char));
		list->fd = fd;
		list->ret = 1;
	}
	new = list;
	while (new && new->fd != fd)
		new = new->next;
	if (!new)
	{
		ft_lback(&list, &new, fd, line);
		new->ret = 1;
	}
	*line = ft_memset(*line, '\0', ft_strlen(*line));
	if (!ft_iter(new, line, fd))
		return (-1);
	return (ft_make_str(new, line));
}

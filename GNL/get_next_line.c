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

void	ft_make_line(t_gnl *new, char *buf, int len)
{
	int		index;

	index = 0;
	new->size = ft_strlen(buf);
	new->last_str = (char *)malloc(sizeof(char) * new->size + 1);
	new->last_str = ft_strncpy(new->last_str, buf, len);
}

int get_next_line(const int fd, char **line)
{
	int				count_it;
	int				ret;
	char			*str;
	static t_gnl	*new;

	count_it = 0;
	new = (t_gnl *)malloc(sizeof(t_gnl));
	*line = (char *)malloc(sizeof(char) * BUFSIZE + 1);
	while (!(str = ft_strchr(new->c, '\n')))
	{
		printf("lol: %s\n", new->c);
		*line = ft_strjoin(*line, new->c);
		 	count_it++;
		ret = read(fd, new->c, BUFSIZE);
		if (ret == -1)
			return (0);
	}
	ft_make_line(new, new->c, str - new->c);
	if (count_it == 0)
	{
		*line = (char *)malloc(sizeof(char) * new->size + 1);
		free(*line);
	}
	*line = ft_strjoin(*line, new->last_str);
	ft_bzero(new->c, str - new->c);
	return (ret);
}

int main(int ac,char **ag)
{
	(void)ac;
	int		fd;
	char	*mass;

	fd = open(ag[1], O_RDONLY);
	get_next_line(fd, &mass);
	printf("%s\n", mass);
	get_next_line(fd, &mass);
	printf("%s\n", mass);
	get_next_line(fd, &mass);
	printf("%s\n", mass);
}
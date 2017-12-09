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

void	ft_make_buf(t_gnl *new)
{
	char	*str;
	int		index;
	int		num;

	index = 0;
	num = BUFSIZE;
	str = new->c;
	while (*str != '\n')
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
	while (index < BUFSIZE)
	{
		new->c[index] = '\0';
		index++;
	}
	//free(str);
}

void	ft_free_list(t_gnl *new)
{
	new->size = 0;
	new->count_it--;
	free(new->last_str);
}

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
	static t_gnl	*new;

	if (new == NULL)
	{
		new = (t_gnl *)malloc(sizeof(t_gnl));
		//new->count_it = -1;
		*line = (char *)malloc(sizeof(char) * BUFSIZE + 1);
	}
	//printf("it :%i\n", new->count_it);
	*line = ft_bzero(*line, ft_strlen(*line));
	while (!(new->str = ft_strchr(new->c, '\n')))
	{
		*line = ft_strjoin(*line, new->c);
		 	//new->count_it++;
		new->ret = read(fd, new->c, BUFSIZE);
		new->c[BUFSIZE] = '\0';
		printf("buf :%s\n", new->c);
		if (new->ret == -1 || new->ret != BUFSIZE)
			return (0);
	}
	//printf("buf :%s\n", new->c);
	ft_make_line(new, new->c, new->str - new->c);
	// if (new->count_it == 0)
	// {
	// 	free(*line);
	// 	*line = (char *)malloc(sizeof(char) * new->size + 1);
	// }
	*line = ft_strjoin(*line, new->last_str);
	ft_make_buf(new);
	ft_free_list(new);
	//new->count_it = 0;
	return (new->ret);
}

int main(int ac,char **ag)
{
	(void)ac;
	int		fd;
	char	*mass;

	fd = open(ag[1], O_RDONLY);
	get_next_line(fd, &mass);
	printf("str: %s\n", mass);
	get_next_line(fd, &mass);
	printf("str: %s\n", mass);
	get_next_line(fd, &mass);
	printf("str: %s\n", mass);
	get_next_line(fd, &mass);
	printf("str: %s\n", mass);
	get_next_line(fd, &mass);
	printf("str: %s\n", mass);
	get_next_line(fd, &mass);
	printf("str: %s\n", mass);
	//sleep(15);
}

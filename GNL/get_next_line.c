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

void	ft_free_list(t_gnl *new)
{
	new->size = 0;
	new->last_str = ft_memset(new->last_str, '\0', ft_strlen(new->last_str));
	new->count_it = 0;
}

void	ft_make_line(t_gnl *new, char *buf, int len)
{
	int		index;

	index = 0;
	new->size = ft_strlen(buf);
	new->last_str = (char *)malloc(sizeof(char) * new->size);
	new->last_str = ft_memset(new->last_str, '\0', ft_strlen(new->last_str));
	new->last_str = ft_strncpy(new->last_str, buf, len);
	new->last_str[len] = '\0';
}

int		find_fd(t_gnl *new, int fd)
{
	while (new)
	{
		if (new->file_descriptor = fd)
			return (1);
		new = new->next;
	}
	return (0);
}

int get_next_line(const int fd, char **line)
{
	static t_gnl	*new;
	char			*str;
	int				len;
	int				file;

	file = find_fd(new, fd);
	if (file)
	{
		while ()
	}
	*line = (char *)malloc(sizeof(char) * BUFF_SIZE + 1);
	if (new == NULL)
	{
		new = (t_gnl *)malloc(sizeof(t_gnl));
		new->count_it = -1;
		new->ret = BUFF_SIZE;
	}
	else
		*line = ft_memset(*line, '\0', ft_strlen(*line));
	while (!(new->str = ft_strchr(new->c, '\n')) && new->ret != 0)
	{
		str = *line;
		*line = ft_strjoin(str, new->c);
		free(str);
		new->count_it++;
		new->ret = read(fd, new->c, BUFF_SIZE);
		new->c[new->ret] = '\0';
	}
	new->count_it++;
	len = new->str - new->c;
	if (new->ret == -1)
		return (-1);
	if (new->ret == 0 && new->count_it == 1)
	{
		len = 0;
		*line = ft_bzero(*line, ft_strlen(*line));
		new->count_it = 0;

		return (0);
	}
	if (new->ret != BUFF_SIZE)
	{
		len = 0;
		while (new->c[len] != '\n' && new->c[len] != '\0')
			len++;
	}
	ft_make_line(new, new->c, len);
	if (new->count_it == 1)
	{
		free(*line);
		*line = (char *)malloc(sizeof(char) * new->size);
		*line = ft_strcpy(*line, new->last_str);
	}
	else
	{
		str = *line;
		*line = ft_strjoin(*line, new->last_str);
		free(str);
	}
	ft_make_buf(new);
	ft_free_list(new);
	if (!ft_strcmp(*line, ""))
		return (0);
	return (1);
}

// int main(int ac,char **ag)
// {
// 	(void)ac;
// 	int		fd;
// 	char	*mass;

// 	fd = open(ag[1], O_RDONLY);
// 	get_next_line(fd, &mass);
// 	printf("str: %s\n", mass);
// 	get_next_line(fd, &mass);
// 	printf("str: %s\n", mass);
// 	get_next_line(fd, &mass);
// 	printf("str: %s\n", mass);
// 	get_next_line(fd, &mass);
// 	printf("str: %s\n", mass);
// 	get_next_line(fd, &mass);
// 	printf("str: %s\n", mass);
// 	get_next_line(fd, &mass);
// 	printf("str: %s\n", mass);
// 	get_next_line(fd, &mass);
// 	printf("str: %s\n", mass);
// 	get_next_line(fd, &mass);
// 	printf("str: %s\n", mass);
// 	get_next_line(fd, &mass);
// 	printf("str: %s\n", mass);
// 	get_next_line(fd, &mass);
// 	printf("str: %s\n", mass);
// 	//while (1);
// 	//sleep(15);
// }

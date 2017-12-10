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
	//printf("bef:%s\n", new->c);
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
	//printf("1 :%s\n", new->c);
}

void	ft_free_list(t_gnl *new)
{
	new->size = 0;
	//new->count_it--;
	new->last_str = ft_memset(new->last_str, '\0', ft_strlen(new->last_str));
	//free(new->last_str);
}

void	ft_make_line(t_gnl *new, char *buf, int len)
{
	int		index;

	// if (len == 0)
	// {
	// 	//new->last_str = NULL;
	// 	return ;
	// }
	//printf("%i\n", len);
	index = 0;
	new->size = ft_strlen(buf);
	//printf("%i\n", new->size);
	new->last_str = (char *)malloc(sizeof(char) * new->size);
	new->last_str = ft_memset(new->last_str, '\0', ft_strlen(new->last_str));
	//printf("%i\n", len);
	//printf("str :%s\n", new->last_str);
	new->last_str = ft_strncpy(new->last_str, buf, len);
	new->last_str[len] = '\0';
	//printf("last :%s\n", new->last_str);
	//printf("test\n");
	//printf("%s\n", new->last_str);
}

int get_next_line(const int fd, char **line)
{
	static t_gnl	*new;
	char			*str;
	int				len;
	int				index;

	index = 0;
	//printf("end\n\n");
	//printf("buf :%s\n", new->c);
	*line = (char *)malloc(sizeof(char) * BUFF_SIZE + 1);
	if (new == NULL)
	{
		new = (t_gnl *)malloc(sizeof(t_gnl));
		new->count_it = -1;
		new->ret = BUFF_SIZE;
	}
	else
		*line = ft_memset(*line, '\0', ft_strlen(*line));
	//new->ret = BUFF_SIZE;
	while (!(new->str = ft_strchr(new->c, '\n')) && new->ret != 0)
	{
		//printf("test\n");
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
	{
		return (-1);
	}
	//printf("coun: %i\n", new->count_it);
	if (new->ret == 0 && new->count_it == 1)
	{
		//printf("test\n");
		len = 0;
		//printf("test\n");
		*line = ft_bzero(*line, ft_strlen(*line));
		// while (new->c[len])
		// {
		// 	new->c[len] = '\0';
		// 	len++;
		// }
		//read(fd, new->c, BUFF_SIZE);
		new->count_it = 0;
		return (0);
	}
	if (new->ret != BUFF_SIZE)
	{
		len = 0;
		while (new->c[len] != '\n' && new->c[len] != '\0')
			len++;
		//printf("%s\n", new->c);
	}
	ft_make_line(new, new->c, len);
	if (new->count_it == 1)
	{
		//printf("test\n");
		free(*line);
		*line = (char *)malloc(sizeof(char) * new->size);
		*line = ft_strcpy(*line, new->last_str);
		//printf("%s\n", *line);
		//*line[new->size - 1] = '\0';
	}
	else
	{
		str = *line;
		//printf("test\n");
		*line = ft_strjoin(*line, new->last_str);
		//printf("test\n");
		free(str);
		//printf("test\n");
	}
	//printf("test\n");
	ft_make_buf(new);
	//printf("test\n");
	ft_free_list(new);
	new->count_it = 0;
	return (1);
}

int main(int ac,char **ag)
{
	(void)ac;
	int		fd;
	char	*mass;

	fd = open(ag[1], O_RDONLY);
	printf("%i\n", get_next_line(fd, &mass));
	printf("str: %s\n", mass);
	printf("%i\n", get_next_line(fd, &mass));
	printf("str: %s\n", mass);
	printf("%i\n", get_next_line(fd, &mass));
	printf("str: %s\n", mass);
	printf("%i\n", get_next_line(fd, &mass));
	printf("str: %s\n", mass);
	printf("%i\n", get_next_line(fd, &mass));
	printf("str: %s\n", mass);
	printf("%i\n", get_next_line(fd, &mass));
	printf("str: %s\n", mass);
	printf("%i\n", get_next_line(fd, &mass));
	printf("str: %s\n", mass);
	printf("%i\n", get_next_line(fd, &mass));
	printf("str: %s\n", mass);
	printf("%i\n", get_next_line(fd, &mass));
	printf("str: %s\n", mass);
	printf("%i\n", get_next_line(fd, &mass));
	printf("str: %s\n", mass);
	//while (1);
	//sleep(15);
}

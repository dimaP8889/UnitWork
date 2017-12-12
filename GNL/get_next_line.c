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

void	ft_lback(t_gnl **lst, t_gnl *elem)
{
	t_gnl *new;

	new = *lst;
	//printf("%i\n", elem->);
	if ((*lst) && elem && lst)
	{
		while (new->next)
			new = new->next;
		new->next = elem;
	}
	if (*lst == NULL && elem != NULL && lst != NULL)
		*lst = elem;
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
		//printf("files :%i ", new->file_descriptor);
		if (new->file_descriptor == fd)
			return (1);
		new = new->next;
	}
	//printf("\n");
	return (0);
}

int get_next_line(const int fd, char **line)
{
	static t_gnl	*list;
	t_gnl			*new;
	char			*str;
	int				len;
	int				file;

	new = list;
	file = find_fd(list, fd);
	if (fd < 0)
		return (-1);
	if (file)
	{
		while (new->file_descriptor != fd)
			new = new->next;
	}
	*line = (char *)malloc(sizeof(char) * BUFF_SIZE + 1);
	if (new == NULL || !file)
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
		if (new->ret < 0)
		return (-1);
	}
	new->count_it++;
	len = new->str - new->c;
	if (new->ret == 0 && new->count_it == 1)
	{
		len = 0;
		*line = ft_bzero(*line, ft_strlen(*line));
		new->count_it = 0;
		if (!file)
		{
			new->file_descriptor = fd;
			ft_lback(&list, new);
		}
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
	if (!file)
	{
		new->file_descriptor = fd;
		ft_lback(&list, new);
	}
	if (!ft_strcmp(*line, ""))
		return (0);
	return (1);
}

int				main(void)
{
	char		*line1;
	char		*line2;
	char		*line3;
	int			fd1;
	int			fd2;
	int			fd3;
	int			ret1;
	int			ret2;
	int			ret3;
	char		*filename1;
	char		*filename2;
	int			errors;

	filename1 = "./gnl11_1.txt";
	filename2 = "./gnl11_2.txt";
	fd1 = open(filename1, O_RDONLY);
	fd2 = open(filename2, O_RDONLY);
	fd3 = -1;
	if (fd1 > 2 && fd2 > 2)
	{
		errors = 0;
		line1 = NULL;
		line2 = NULL;
		line3 = NULL;

		ret1 = get_next_line(fd1, &line1);
		if (ret1 != 1 || strcmp(line1, "The getdelim() function reads a line from stream, delimited by the character") != 0)
		{
			printf("-> must have returned '1' and read line #1 \"The getdelim() function reads a line from stream, delimited by the character\" from file %s\n", filename1);
			errors++;
		}

		ret1 = get_next_line(fd1, &line1);
		if (ret1 != 1 || strcmp(line1, "delimiter.  The getline() function is equivalent to getdelim() with the new-") != 0)
		{
			printf("-> must have returned '1' and read line #2 \"delimiter.  The getline() function is equivalent to getdelim() with the new-\" from file %s\n", filename1);
			errors++;
		}

		ret1 = get_next_line(fd1, &line1);
		if (ret1 != 1 || strcmp(line1, "line character as the delimiter.  The delimiter character is included as") != 0)
		{
			printf("-> must have returned '1' and read line #3 \"line character as the delimiter.  The delimiter character is included as\" from file %s\n", filename1);
			errors++;
		}

		ret1 = get_next_line(fd1, &line1);
		if (ret1 != 1 || strcmp(line1, "part of the line, unless the end of the file is reached.") != 0)
		{
			printf("-> must have returned '1' and read line #4 \"part of the line, unless the end of the file is reached.\" from file %s\n", filename1);
			errors++;
		}

		ret2 = get_next_line(fd2, &line2);
		if (ret2 != 1 || strcmp(line2, "The Festival de Radio France et Montpellier is a summer festival of opera and other music held in Montpellier.") != 0)
		{
			printf("-> must have returned '1' and read line #1 \"The Festival de Radio France et Montpellier is a summer festival of opera and other music held in Montpellier.\" from file %s\n", filename2);
			errors++;
		}

		ret2 = get_next_line(fd2, &line2);
		if (ret2 != 1 || strcmp(line2, "The festival concentrates on classical music and jazz with about 150 events, including opera, concerts, films, and talks. ") != 0)
		{
			printf("-> must have returned '1' and read line #2 \"The festival concentrates on classical music and jazz with about 150 events, including opera, concerts, films, and talks. \" from file %s\n", filename2);
			errors++;
		}

		ret2 = get_next_line(fd2, &line2);
		if (ret2 != 1 || strcmp(line2, "Most of these events are free and are held in the historic courtyards of the city or in the modern concert halls of Le Corum. ") != 0)
		{
			printf("-> must have returned '1' and read line #3 \"Most of these events are free and are held in the historic courtyards of the city or in the modern concert halls of Le Corum. \" from file %s\n", filename2);
			errors++;
		}

		ret2 = get_next_line(fd2, &line2);
		if (ret2 != 1 || strcmp(line2, "Le Corum cultural and conference centre contains 3 auditoriums. ") != 0)
		{
			printf("-> must have returned '1' and read line #4 \"Le Corum cultural and conference centre contains 3 auditoriums. \" from file %s\n", filename2);
			errors++;
		}
		ret3 = get_next_line(fd3, &line3);
		if (ret3 != -1)
		{
			printf("-> must have returned '-1' with invalid file descriptor\n");
			errors++;
		}

		ret1 = get_next_line(fd1, &line1);
		if (ret1 != 1 || strcmp(line1, "") != 0)
		{
			printf("-> must have returned '1' and read line #5 \"\" from file %s\n", filename1);
			errors++;
		}

		ret1 = get_next_line(fd1, &line1);
		if (ret1 != 1 || strcmp(line1, "The caller may provide a pointer to a malloced buffer for the line in") != 0)
		{
			printf("-> must have returned '1' and read line #6 \"The caller may provide a pointer to a malloced buffer for the line in\" from file %s\n", filename1);
			errors++;
		}

		ret1 = get_next_line(fd1, &line1);
		if (ret1 != 1 || strcmp(line1, "*linep, and the capacity of that buffer in *linecapp.  These functions") != 0)
		{
			printf("-> must have returned '1' and read line #7 \"*linep, and the capacity of that buffer in *linecapp.  These functions\" from file %s\n", filename1);
			errors++;
		}

		ret1 = get_next_line(fd1, &line1);
		if (ret1 != 1 || strcmp(line1, "expand the buffer as needed, as if via realloc().  If linep points to a NULL") != 0)
		{
			printf("-> must have returned '1' and read line #8 \"expand the buffer as needed, as if via realloc().  If linep points to a NULL\" from file %s\n", filename1);
			errors++;
		}

		ret1 = get_next_line(fd1, &line1);
		if (ret1 != 1 || strcmp(line1, "pointer, a new buffer will be allocated.  In either case, *linep and") != 0)
		{
			printf("-> must have returned '1' and read line #9 \"pointer, a new buffer will be allocated.  In either case, *linep and\" from file %s\n", filename1);
			errors++;
		}
		printf("test\n");
		ret1 = get_next_line(fd1, &line1);
		if (ret1 != 1 || strcmp(line1, "*linecapp will be up-dated accordingly.") != 0)
		{
			printf("-> must have returned '1' and read line #10 \"*linecapp will be up-dated accordingly.\" from file %s\n", filename1);
			errors++;
		}

		ret2 = get_next_line(fd2, &line2);
		if (ret2 != 1 || strcmp(line2, "The city is a center for cultural events since there are many students. ") != 0)
		{
			printf("-> must have returned '1' and read line #5 \"The city is a center for cultural events since there are many students. \" from file %s\n", filename2);
			errors++;
		}

		ret2 = get_next_line(fd2, &line2);
		if (ret2 != 1 || strcmp(line2, "Montpellier has two large concerts venues: Le Zenith Sud (7.000 seats) and L'Arena (14.000 seats).") != 0)
		{
			printf("-> must have returned '1' and read line #6 \"Montpellier has two large concerts venues: Le Zenith Sud (7.000 seats) and L'Arena (14.000 seats).\" from file %s\n", filename1);
			errors++;
		}

		ret1 = get_next_line(fd1, &line1);
		if (ret1 != 0)
		{
			printf("-> must have returned '0' at the end of file %s\n", filename1);
			errors++;
		}

		ret2 = get_next_line(fd2, &line2);
		if (ret2 != 0)
		{
			printf("-> must have returned '0' at the end of file %s\n", filename2);
			errors++;
		}

		close(fd1);
		close(fd2);
		if (errors == 0)
			printf("OK\n");
	}
	else
		printf("An error occured while opening files %s and/or %s\n", filename1, filename2);
	return (0);
}

// int main(int ac,char **ag)
// {
// 	(void)ac;
// 	int		fd1;
// 	int		fd2;
// 	char	*mass;

// 	fd1 = open(ag[1], O_RDONLY);
// 	fd2 = open(ag[2], O_RDONLY);
// 	get_next_line(fd1, &mass);
// 	printf("str1: %s\n", mass);
// 	get_next_line(fd1, &mass);
// 	printf("str1: %s\n", mass);
// 	//get_next_line(fd2, &mass);
// 	// printf("str2: %s\n", mass);
// 	// get_next_line(fd2, &mass);
// 	// printf("str2: %s\n", mass);
// 	// get_next_line(fd1, &mass);
// 	// printf("str1: %s\n", mass);
// 	// get_next_line(fd2, &mass);
// 	// printf("str2: %s\n", mass);
// 	// get_next_line(fd2, &mass);
// 	// printf("str2: %s\n", mass);
// 	// get_next_line(fd1, &mass);
// 	// printf("str1: %s\n", mass);
// 	// get_next_line(fd2, &mass);
// 	// printf("str2: %s\n", mass);
// 	// get_next_line(fd1, &mass);
// 	// printf("str1: %s\n", mass);
// 	//while (1);
// 	//sleep(15);
// }

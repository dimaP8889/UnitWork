/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpogrebn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/04 13:07:50 by dpogrebn          #+#    #+#             */
/*   Updated: 2017/12/04 13:07:50 by dpogrebn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#define BUFF_SIZE 100

#ifndef _GET_NEXT_LINE_H_
# define _GET_NEXT_LINE_H_

# include "./libft/libft.h"
# include <stdio.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

typedef struct			s_gnl
{
	char				c[BUFF_SIZE + 1];
	int					count_size;
	char				*last_str;
	int					size;
	int					file_num;
	int					count_it;
	int					ret;
	int					file_descriptor;
	char				*str;
	t_list				*list;
}						t_gnl;
int get_next_line(const int fd, char **line);

#endif

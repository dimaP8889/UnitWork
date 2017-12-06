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

#ifndef _GET_NEXT_LINE_H_
# define _GET_NEXT_LINE_H_

# include "./libft/libft.h"
# include <stdio.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

# define BUFSIZE 100

typedef struct			s_gnl
{
	char				c[BUFSIZE + 1];
	int					*count_back_slash[1];
	int					check_back_slash;
	char				str_join[BUFSIZE + 1];
	int					count_lists;
	int					count_size;
	int					*files;
	int					file_num;
	t_list				*list;
	t_s_back_slashes	**num;
}						t_gnl;

typedef struct s_back_slashes
{
	int			count_back_slash;
}				t_s_back_slashes;

typedef struct s_files
{
	int			count_files;
}				t_files;
#endif

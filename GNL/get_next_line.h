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

# define BUFSIZE 5

typedef struct			s_gnl
{
	char				c[BUFSIZE + 1];
	int					count_size;
	char				*last_str;
	int					size;
	int					file_num;
	t_list				*list;
}						t_gnl;

#endif

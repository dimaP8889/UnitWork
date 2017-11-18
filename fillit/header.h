/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpogrebn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 15:10:57 by dpogrebn          #+#    #+#             */
/*   Updated: 2017/11/17 15:10:57 by dpogrebn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _HEADER_H_
# define _HEADER_H_

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

# define LINE 4
# define COL 4

typedef struct		s_list
{
	char			**content;
	char			*str;
	int				col;
	int				line;
	struct s_list	*next;
	str = (char *)malloc(sizeof(char) * 5);
	content = (char **)malloc(sizeof(char) * 5);
}					t_list;

int		main(int argc, char **argv);


#endif

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

#ifndef _HEADER_H
# define _HEADER_H

# include <stdio.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include "./libft/libft.h"

# define MAXSIZE 72
# define SIZE 4

typedef struct		s_mass
{
	int				col;
	int				line;

}					t_mass;

void				make_optimal(t_list *list);
int					main(int argc, char **argv);
t_list				*getmap(char **argv);
int					check_sharps(t_list *list);
char				**solve(t_list *list);
int					ft_make_figure(t_list *map, char ***mass);
void				ft_print(char **mass);
void				ft_clean(t_list **list);
void				find_prev(t_list *new, t_list **list);
int					check_norm(t_list *list);
int					allocate_mem(t_list **list, int count);
void				if_find_sharp(t_list *list, char *c);
int					makelist(t_list *list, char c);
#endif

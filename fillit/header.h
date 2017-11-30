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
# include "./libft/libft.h"

# define SIZE 4

int					main(int argc, char **argv);
t_list				*getmap(char **argv);
int					check_sharps(t_list *list);
char				**solve(t_list *list);
void				ft_make_figure(t_list *list, char ***mass);
void				ft_print(char **mass);

#endif

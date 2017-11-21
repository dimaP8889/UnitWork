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

# define LINE 4
# define COL 4

int					main(int argc, char **argv);
t_list				*getmap(char **argv);
int					check_sharps(t_list *list);


#endif

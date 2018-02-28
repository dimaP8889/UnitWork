/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pizza.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpogrebn <dpogrebn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/28 21:22:54 by dpogrebn          #+#    #+#             */
/*   Updated: 2018/02/28 22:42:19 by dpogrebn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIZZA_H
# define PIZZA_H

# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include "libft/includes/libft.h"
# include "libft/includes/get_next_line.h"
# include "libft/ft_printf/ft_printf.h"

typedef	struct 		s_params
{
	int		rows;
	int		col;
	int		min;
	int		max;
	int		y;
	int		x;
	int 	T;
	int		M;
	int 	same;
}					t_params;

#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_sharps.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpogrebn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/21 18:16:56 by dpogrebn          #+#    #+#             */
/*   Updated: 2017/11/21 18:16:56 by dpogrebn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		check_near_sharpes(t_list *list, int line, int col)
{
	int		count;

	count = 0;
	if (line + 1 < 3)
		if (list->include[col][line + 1] == list->let)
			count++;
	if (line - 1 >= 0)
		if (list->include[col][line - 1] == list->let)
			count++;
	if (col + 1 < 3)
		if (list->include[col + 1][line] == list->let)
			count++;
	if (col - 1 >= 0)
		if (list->include[col - 1][line] == list->let)
			count++;
	return(count);
}

int		check_sharps(t_list *list)
{
	int		col;
	int		line;
	int		max;
	int		check;

	max = 0;
	col = list->y_first;
	line = 0;
	while (col < list->y_last)
	{
		while (line < LINE)
		{
			if (list->include[col][line] == list->let)
			{
				check = check_near_sharpes(list, line, col);
				if (check > max)
					max = check;
				else
					if (check == 0)
						return (0);
			}

			line++;
		}
		line = 0;
		col++;
	}
	if (max < 2)
		return (0);
	return(1);
}

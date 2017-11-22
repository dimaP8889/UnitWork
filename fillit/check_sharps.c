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

int		check_near_sharpes(t_list *list)
{
	int		count;

	count = 0;
	if (list->x[list->count] + 1 < 3)
		if (list->x[list->count] + 1 == list->x[list->count + 1])
			count++;
	if (list->x[list->count] - 1 >= 0)
		if (list->x[list->count] - 1 == list->x[list->count - 1])
			count++;
	if (list->y[list->count] + 1 < 3)
		if (list->y[list->count] + 1 == list->y[list->count + 1])
			count++;
	if (list->y[list->count] - 1 >= 0)
		if (list->y[list->count] - 1 == list->y[list->count - 1])
			count++;
	return(count);
}

int		check_sharps(t_list *list)
{
	int		max;
	int		check;

	list->count = 0;
	while (list->count < SIZE)
	{
		check = check_near_sharpes(list);
		if (check > max)
			max = check;
		else
			if (check == 0)
				return (0);
		(list->count)++;
	}
	if (max < 2)
		return (0);
	return(1);
}

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
	if (list->x[list->count] + 1 < 4)
		if (list->include[list->y[list->count]]
			[list->x[list->count] + 1] == list->let)
			count++;
	if (list->x[list->count] - 1 >= 0)
		if (list->include[list->y[list->count]]
			[list->x[list->count] - 1] == list->let)
			count++;
	if (list->y[list->count] + 1 < 4)
		if (list->include[list->y[list->count] + 1]
			[list->x[list->count]] == list->let)
			count++;
	if (list->y[list->count] - 1 >= 0)
		if (list->include[list->y[list->count] - 1]
			[list->x[list->count]] == list->let)
			count++;
	return (count);
}

int		check_sharps(t_list *list)
{
	int		max;
	int		check;

	max = 0;
	list->count = 0;
	while (list->count < SIZE)
	{
		check = check_near_sharpes(list);
		if (check > max)
			max = check;
		else if (check == 0)
			return (0);
		(list->count)++;
	}
	if (max < 2)
		return (0);
	return (1);
}

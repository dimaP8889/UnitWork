/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   making_figure.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpogrebn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/22 16:19:47 by dpogrebn          #+#    #+#             */
/*   Updated: 2017/11/22 16:19:48 by dpogrebn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		find_place_for_figure(t_list *list, char **mass)
{
	t_mass	*new;

	//new = (t_mass)malloc(sizeof(t_mass))
	if ()
}

int		check_place_for_figure(t_list *list, char **mass)
{
	int		count;

	count = 0;
	if (!find_place_for_figure(list, mass))
		return (0);
	while (count < SIZE)
	{

	}
}

void	list_change(t_list *list, t_list *list_change)
{
	if (list_change && list)
	{
		while (list->next)
		{
			if (list->next->content == list_change->content)
				list->next = list->next->next;
			list = list->next;
		}
		list->next = list_change;
		list->next->next = NULL;
	}
}

char	**making_figure(t_list *list, char **mass)
{
	t_list *list1;

	list1 = list;
	if (!list)
		check_square(list);
	if (!check_place_for_figure(list, &mass))
		making_figure(list_change(list1, list), mass);
	else
		list = list->next;
	return (NULL);
}


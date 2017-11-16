/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_addlstlast.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpogrebn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 20:02:32 by dpogrebn          #+#    #+#             */
/*   Updated: 2017/11/14 20:02:33 by dpogrebn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstaddlast(t_list *lst, t_list *elem)
{
	if (lst && elem)
	{
		while (lst->next)
			lst = lst->next;
		lst->next = elem;
	}
	return ;
}

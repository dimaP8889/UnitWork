/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpogrebn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 16:53:07 by dpogrebn          #+#    #+#             */
/*   Updated: 2017/11/17 16:53:07 by dpogrebn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		main(int argc, char **argv)
{
	t_list		*new;
	t_list		*list;
	int			i;
	int			count;

	count = 0;

	i = 0;
	if (argc != 2)
		return (0);
	new = getmap(argv);
	list = new;
	while (new)
	{
		while (new->include[i])
		{
			printf("%s\n", new->include[i]);
			i++;
		}
		while (count < SIZE)
			{
				//printf("x :%i\n", new->x[count]);
				//printf("y :%i\n", new->y[count]);
				//printf("\n");
				count++;
			}
			count = 0;
		printf("\n");
		i = 0;
		new = new->next;
	}
	solve(list);
}
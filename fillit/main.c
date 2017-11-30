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
	char		**final;

	count = 0;

	i = 0;
	if (argc != 2)
		return (0);
	new = getmap(argv);
	list = new;
	final = solve(list);
	ft_print(final);
	// while (*final)
	// {
	// 	printf("%s\n", *final);
	// 	final++;
	// }
}
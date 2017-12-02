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
	char		**final;

	if (argc != 2)
	{
		ft_putstr("usage: ./fillit target_file\n");
		return (0);
	}
	new = getmap(argv);
	ft_clean(&new);
	final = solve(new);
	if (!new || !(final))
	{
		ft_putstr("error\n");
		return (0);
	}
	ft_print(final);
}

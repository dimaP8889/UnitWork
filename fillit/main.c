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
//#include "./libft/libft.h"

void	del(void	*str, size_t	num)
{
	free(str);
	(void)num;
}

int		main(int argc, char **argv)
{
	t_list		*new;
	int			i;

	i = 0;
	if (argc != 2)
		return (0);
	new = getmap(argv);
	while (new)
	{
		while (new->include[i])
		{
			printf("%s\n", new->include[i]);
			i++;
		}
		printf("\n");
		i = 0;
		new = new->next;
	}
	//validation();
}
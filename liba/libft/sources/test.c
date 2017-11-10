/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpogrebn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/01 05:37:44 by dpogrebn          #+#    #+#             */
/*   Updated: 2017/11/01 05:37:44 by dpogrebn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int		main(void)
{
	char *data = "hello, i'm a data";
	t_list *l = ft_lstnew(data, strlen(data) + 1);
	if (!l)
		printf("maladec\n");
	printf("loh\n");
	printf("%s\n", (char *)l);
	printf("%s\n", l->content);
}

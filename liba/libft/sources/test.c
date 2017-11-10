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
	char		*str = "Hello les genw";

	printf("def: %s\n", strnstr(str, "les genw", 7));
	printf("my: %s\n", ft_strnstr(str, "les genw", 7));
}

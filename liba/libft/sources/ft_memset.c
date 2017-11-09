/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpogrebn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/02 17:12:28 by dpogrebn          #+#    #+#             */
/*   Updated: 2017/11/02 17:12:29 by dpogrebn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	char	*str;
	int		index;

	index = 0;
	str = (char *)b;
	while (len > 0)
	{
		str[index] = c;
		index++;
		len--;
	}
	return (str);
}

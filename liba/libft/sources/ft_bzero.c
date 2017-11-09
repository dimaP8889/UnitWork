/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpogrebn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/02 22:11:33 by dpogrebn          #+#    #+#             */
/*   Updated: 2017/11/02 22:11:39 by dpogrebn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	*ft_bzero(void *b, size_t len)
{
	char	*str;
	int		index;

	index = 0;
	str = (char *)b;
	while (len > 0)
	{
		str[index] = '\0';
		index++;
		len--;
	}
	return (str);
}

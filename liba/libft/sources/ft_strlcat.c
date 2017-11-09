/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpogrebn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/01 07:10:15 by dpogrebn          #+#    #+#             */
/*   Updated: 2017/11/01 07:10:16 by dpogrebn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	index;
	int		i;

	i = (size_t)dstsize;
	index = 0;
	while (*src)
	{
		src++;
		index++;
	}
	while (*dst && i > 0)
	{
		dst++;
		index++;
		i--;
	}
	return (index);
}

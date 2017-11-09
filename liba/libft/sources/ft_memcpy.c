/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpogrebn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/03 17:00:13 by dpogrebn          #+#    #+#             */
/*   Updated: 2017/11/03 17:00:14 by dpogrebn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t len)
{
	unsigned char	*str;
	unsigned char	*src1;
	unsigned char	*str1;

	str = (unsigned char *)dst;
	src1 = (unsigned char *)src;
	str1 = str;
	while (*src1 && len-- > 0)
		*(str++) = *(src1++);
	if (*str1 != '\0')
		*str = '\0';
	return (str1);
}

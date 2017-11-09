/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpogrebn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/02 22:46:13 by dpogrebn          #+#    #+#             */
/*   Updated: 2017/11/02 22:46:14 by dpogrebn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	*ft_memchr(const void *s, int c, size_t len)
{
	char *str;

	str = (char *)s;
	while (len-- > 0 && *(str++))
		if (*str == c)
			return (str);
	if (c == '\0')
		return (str);
	return (NULL);
}

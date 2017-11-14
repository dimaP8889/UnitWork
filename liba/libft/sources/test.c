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

t_list	*f(t_list *lst)
{
	(void)(lst);
	t_list *l = ft_lstnew((char *)"privet", 228);
	return (l);
}

void			lstdel_f(void *lst, size_t s) {
	(void)lst;
	(void)s;
	//__delNum++;
}

t_list *		lstmap_f(t_list *m)
{
	t_list *	r = ft_lstnew("OK !", 5);
	(void)m;
	return (r);
}

int		main(void)
{
	t_list	*l = ft_lstnew((char *)"loleckapec", 26);
	t_list	*s = ft_lstnew((char *)"lalalal", 20);
	t_list	*k = ft_lstnew((char *)"lololo", 12);
	t_list	*z;


	ft_lstadd(&l, s);
	ft_lstadd(&l, k);
	z = ft_lstmap(l, f);
	while (z)
	{
		printf("%s %zu\n", (char *)z->content, z->content_size);
		z = z->next;
	}
}


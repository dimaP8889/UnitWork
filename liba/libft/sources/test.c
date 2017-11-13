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

void	del(void *str, size_t size)
{
	free(str);
	(void)size;
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
			t_list	*l = ft_lstnew(strdup(" 1 2 3 "), 8);
			t_list	*ret;

			l->next = ft_lstnew(ft_strdup("ss"), 3);
			l->next->next = ft_lstnew(ft_strdup("-_-"), 4);
			ret = ft_lstmap(l, lstmap_f);
			//if (!ft_strcmp(ret->content, "OK !") && !ft_strcmp(ret->next->content, "OK !") && !strcmp(ret->next->next->content, "OK !") && !strcmp(l->content, " 1 2 3 ") && !strcmp(l->next->content, "ss") && !strcmp(l->next->next->content, "-_-"))
				printf("%zu\n", ret->content_size);
			printf("loh\n");
}


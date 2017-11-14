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
	t_list *l;
	(void)(lst);
	if (lst->content_size == 26)
		l = ft_lstnew((char *)"privet", 228);
	else
		l = ft_lstnew((char *)"poka", 22);
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

t_list		*uf_testmap(t_list *elem)
{
	t_list	*new;
	char	*content;
	size_t	i;

	content = ft_strdup((char *)(elem->content));
	i = 0;
	while (i < ft_strlen(content))
	{
		content[i] += 1;
		++i;
	}
	new = ft_lstnew((void const *) content, 5);
	free(content);
	return (new);
}

// int		main(void)
// {
//  	t_list			*lst_initial;
//     t_list			*lst;
//     char			*content;
//     t_list			*(*f)(t_list *);

// 	content = "toto";
// 	lst_initial = ft_lstnew((void const *) content, 5);
// 	content = "tata";
// 	lst_initial->next = ft_lstnew((void const *) content, 5);
// 	content = "tutu";
// 	lst_initial->next->next = ft_lstnew((void const *) content, 5);
// 	f = &uf_testmap;
// 	lst = ft_lstmap(lst_initial, f);
// 	// printf("%i\n", strcmp((const char *) lst->content, (const char *) lst_initial->content));
// 	// printf("%i\n", strcmp((const char *) lst->content, "upup"));

// 	printf("%s\n", (const char *) lst_initial->content);
// 	if (!strcmp((const char *) lst->content, (const char *) lst_initial->content) || strcmp((const char *) lst->content, "upup"))
//         printf("lol\n");
//     if (!strcmp((const char *) lst->next->content, (const char *) lst_initial->next->content) || strcmp((const char *) lst->next->content, "ubub"))
//         printf("lol1\n");
//     if (!strcmp((const char *) lst->next->next->content, (const char *) lst_initial->next->next->content) || strcmp((const char *) lst->next->next->content, "uvuv"))
//          printf("lol2\n");
//     return (1);
// }

int		main(void)
{
	static	char	**tt;

	tt = ft_strsplit("coucouwdfdwu", '*');
	printf("%s\n", tt[0]);
	//(strcmp(tt[0], "coucou"));
}


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
	t_list *list = NULL;
	t_list *list1;
	t_list *list2;
	t_list *list3;
	t_list *list4;
	t_list *list5;
	t_list *mainlist;

	list = ft_lstnew("", 0);
	list1 = ft_lstnew("bfdbfdbdf", 233);
	list2 = ft_lstnew("mtmumu", 37);
	list3 = ft_lstnew("eopet", 35);
	list4 = ft_lstnew("cwpicjrw", 90);
	list5 = ft_lstnew("ccs[sc", 56);
	ft_lstaddlast(list, list1);
	ft_lstaddlast(list, list2);
	ft_lstaddlast(list, list3);
	ft_lstaddlast(list, list4);
	ft_lstaddlast(list, list5);
	mainlist = list;
	printf("before:\n");
	while (list)
	{
		printf("%s\n", list->content);
		list = list->next;
	}
	mainlist = ft_lstsortcontent(mainlist);
	printf("\n");
	printf("after:\n");
	while (mainlist)
	{
		printf("%s\n", mainlist->content);
		mainlist = mainlist->next;
	}
	printf("\n");
}
// int main (void)
// {
// 	const char **s;

// 	s = (const char **)malloc(sizeof(char *) * 10);
// 	s[0] = "hello";
// 	s[1] = "PASHA";
// 	s[2] = "LOL";
// 	s[3] = NULL;
	
// 	printf("%s\n", ft_str_gather(s, ' '));
//}


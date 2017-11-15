/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_postorder.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpogrebn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 01:32:54 by dpogrebn          #+#    #+#             */
/*   Updated: 2017/11/16 01:32:55 by dpogrebn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	ft_postoder(t_btree *tree, void (*f)(void *))
{
	if (!tree)
		return (0);
	if (tree->left)
		ft_proder(tree->left, f);
	if (tree->right)
		ft_proder(tree->right, f);
	f(tree->content);
}

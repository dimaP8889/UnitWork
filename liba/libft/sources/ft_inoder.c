/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_inoder.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpogrebn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 01:16:53 by dpogrebn          #+#    #+#             */
/*   Updated: 2017/11/16 01:16:54 by dpogrebn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	ft_inoder(b_tree *tree, void *(f)(void *))
{
	if (!tree)
		return (0);
	if (tree->left)
		ft_proder(tree->left, f);
	f(tree->content);
	if (tree->right)
		ft_proder(tree->right, f);
}

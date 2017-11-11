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
//char			str[] = "  \t    \t\nBon\t \njour\t\n  \n     ";
	char			str2[] = "Bonjourw";
	//char			str3[] = "  \t\t\t   ";
	char			*r;
	//char			*str3 = NULL;

	// ft_strtrim(NULL);
	// r = ft_strtrim(str);
	// if (strcmp(r, "Bon\t \njour"))
	// {
	
	// 	printf("Error Line %d, Funct %s : \n\033[31mft_strstrim(\"  \t    \t\nBon\t \njour\t\n  \n     \").\nExpected ret = \"Bon\t \njour\" \
	// 		   but have ret = \"%s\"\033[0m\n", __LINE__ - 2, __func__, r);
	// 	free(r);
	// 	return (0);
	// }
	// free(r);
	r = ft_strtrim(str2);
	printf("r: %s\n", r);
	//str3 = strcpy(str3, "Bonjour");
   if (ft_strcmp(r, "Bonjourw") || (str2 == r))
    {
        /*printf("Error Line %d, Funct %s : \n\033[31mft_strs
        trim(\"Bonjour\").\nExpected ret = \"Bonjour\" and differents pointers\
			   but have ret = \"%s\" and our: %p / your: %p\033[0m\n", __LINE__ - 2, __func__, r, str2, r);*/
		free(r);
        return (0);
    }
    free(r);
// 	r = ft_strtrim(str3);
//     if (strcmp(r, "") || (str3 == r))
//     {
//         printf("Error Line %d, Funct %s : \n\033[31mft_strstrim(\"  \t\t\t  \").\nExpected ret = \"\" and different\
// s pointers but have ret = \"%s\" and our: %p / your: %p\033[0m\n", __LINE__ - 2, __func__, r, str3, r);
// 		free(r);
//         return (0);
//     }
    free(r);
	return (1);
}


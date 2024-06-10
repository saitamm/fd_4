/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sait-amm <sait-amm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 09:43:19 by sait-amm          #+#    #+#             */
/*   Updated: 2024/06/10 15:25:31 by sait-amm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include_file/fdf.h"

// void ft_strlen_2(char *str)
// {
// 	int i = 0;
//     while (str[i])
//     {
// 	    printf(">>>>>>>>>>..%c>>>>>>>>>>>..\n", str[i]);
//         i++;
//     }
// 	// while (str[i])
// 	// 	i++;
// 	// return (i);
// }

int   not_same_colone(t_map map)
{
    int i;
    char **str;

    i = 0;
    str = ft_split(map.buff, '\n');
    // l = ft_strlen_2(str[0]);
    while (str[i])
    {
    // printf(":::::::::::::%zu\n", k);
        if ((int  )ft_strlen(str[i]) != map.colone)
        {
            ft_free_double(str, ft_str_len(str));
            return (0);
        }
        i++;
    }
    ft_free_double(str, ft_str_len(str));
    return (1);
}
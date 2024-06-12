/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sait-amm <sait-amm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 09:43:19 by sait-amm          #+#    #+#             */
/*   Updated: 2024/06/12 12:53:52 by sait-amm         ###   ########.fr       */
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

int check_file(char *str)
{
    int i;

    i = 0;
    if (str[i] == '.' && str[i + 1] == 'f' && str[i + 2] == 'd' && str[i + 3] == 'f')
        return (1);
    while (str[i])
        i++;
    i--;
    if (str[i] == 'f')
    {
        i--;
        if (str[i] == 'd')
        {
            i--;
            if (str[i] == 'f')
            {
                i--;
                if (str[i] == '.')
                    return (0);
            }
        }
    }
    return (1);
}

int   not_same_colone(t_map map)
{
    int i;
    char **str;
    size_t l;
    
    i = 0;
    str = ft_split(map.buff, '\n');
    l = ft_strlen(str[0]);
    while (str[i])
    {
    // printf(":::::::::::::%zu\n", k);
        if (ft_strlen(str[i]) != l)
        {
            ft_free_double(str, ft_str_len(str));
            return (0);
        }
        i++;
    }
    ft_free_double(str, ft_str_len(str));
    return (1);
}
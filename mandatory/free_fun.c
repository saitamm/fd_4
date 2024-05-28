/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_fun.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sait-amm <sait-amm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 10:28:57 by sait-amm          #+#    #+#             */
/*   Updated: 2024/05/28 10:41:03 by sait-amm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include_file/header.h"


int ft_str_len(char **str)
{
    int i;

    i = 0;
    while (str[i])
        i++;
    return (i);
}

void	ft_free_double(char	**str, int i)
{
	while (i > 0)
		free(str[--i]);
	free(str);
}

void    free_map(t_map map)
{
    free(map.buff);
}
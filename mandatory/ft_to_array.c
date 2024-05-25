/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_to_array.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sait-amm <sait-amm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 10:23:38 by sait-amm          #+#    #+#             */
/*   Updated: 2024/05/24 11:23:12 by sait-amm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include_file/header.h"

t_point **ft_to_array(t_map *map)
{
    int         i;
    t_point **tab;
    char *cpy;

    i = 0;
    tab = (t_point **) malloc(map->line * sizeof(t_point *));
    if (!tab)
        return (NULL);
    while (i < map->line)
    {
        cpy = ft_strcpy(map->buff);
        map->buff = map->buff + ft_strlen(cpy) + 1;
        tab[i] = sub_array(i, map->colone,cpy);
        free(cpy);
        i++;
    }
    return (tab);
}

t_point  *sub_array(int pos_y, int colone, char *buff)
{
    t_point *array;
    char    **sp;
    int i;
    array = (t_point *)malloc(sizeof(t_point) * colone);
    if (!array)
        return(NULL);
    sp = ft_split(buff, ' ');
    i = 0;
    while (sp[i])
    {
        if (ft_strchr(sp[i], ',') == 0)
            whithout_color(pos_y, i, &array[i], sp[i]);
        else
            whith_color(pos_y, i, &array[i], sp[i]);
        i++;
    }
    return (array);
}
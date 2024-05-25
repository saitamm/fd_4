/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sait-amm <sait-amm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 11:37:00 by sait-amm          #+#    #+#             */
/*   Updated: 2024/05/25 12:43:09 by sait-amm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include_file/header.h"

t_point **rotation_x(t_point **tab, t_map *map, double angle)
{
    int i;
    int j;
    int tmp;
    double alpha;
    

    i = 0;
    j = 0;
    alpha = angle * (PI / 180.0);
    while (i < map->line)
    {
        j = 0;
        while (j < map->colone)
        {
            tab[i][j].x_ind = tab[i][j].x_ind;
            tmp = tab[i][j].y_ind;
            tab[i][j].y_ind = tab[i][j].y_ind * sin(alpha) - sin(alpha) * tab[i][j].z;
            tab[i][j].z = tmp * cos(alpha) + cos(alpha)  * tab[i][j].z;
            j++;
        }
        i++;
    }
    return (tab);
}


t_point **rotation_y(t_point **tab, t_map *map, double angle)
{
    int i;
    int j;
    int tmp;
    double alpha;
    

    i = 0;
    j = 0;
    alpha = angle * PI / 180;
    while (i < map->line)
    {
        j = 0;
        while (j < map->colone)
        {
            tab[i][j].y_ind = tab[i][j].y_ind;
            tmp = tab[i][j].x_ind;
            tab[i][j].x_ind = tab[i][j].x_ind * cos(alpha) + sin(alpha) * tab[i][j].z;
            tab[i][j].z = tmp * sin(alpha) + cos(alpha)  * tab[i][j].z;
            j++;
        }
        i++;
    }
    return (tab);
}

t_point **rotation_z(t_point **tab, t_map *map, double angle)
{
    int i;
    int j;
    double alpha;
    int tmp;
    

    i = 0;
    j = 0;
    alpha = angle * PI / 180;
    while (i < map->line)
    {
        j = 0;
        while (j < map->colone)
        {
            tab[i][j].x_ind -= 450;
            tab[i][j].y_ind -= 275; 
            tmp = tab[i][j].x_ind;
            tab[i][j].x_ind = (double)tab[i][j].x_ind - sin(alpha) * (double)tab[i][j].y_ind;
            tab[i][j].y_ind = (double)tmp * sin(alpha) + cos(alpha) * (double)tab[i][j].y_ind ;
            
            // if (tab[i][j].z < 10)
            //     tab[i][j].z = tab[i][j].z * 10;
            // else 
                tab[i][j].z = tab[i][j].z * 3;
            tab[i][j].x_ind += 900;
            tab[i][j].y_ind += 700;
            j++;
        }
        i++;
    }
    return (tab);
}

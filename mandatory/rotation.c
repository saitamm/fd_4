/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sait-amm <sait-amm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 11:37:00 by sait-amm          #+#    #+#             */
/*   Updated: 2024/05/28 10:24:36 by sait-amm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include_file/header.h"

t_point **rotation_x(t_point **tab, t_map map, double angle)
{
    int i;
    int j;
    int tmp;
    double alpha;
    

    i = 0;
    j = 0;
    alpha = angle * (PI / 180.0);
    while (i < map.line)
    {
        j = 0;
        while (j < map.colone)
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


t_point **rotation_y(t_point **tab, t_map map, double angle)
{
    int i;
    int j;
    int tmp;
    double alpha;
    

    i = 0;
    j = 0;
    alpha = angle * PI / 180;
    while (i < map.line)
    {
        j = 0;
        while (j < map.colone)
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

t_point rot_z(t_point **tab, t_map map)
{
    int i;
    int j;

    i = 0;
    while (i < map.line)
    {
        j = 0;
        while (j < map.colone)
        {
            if (i == map.line / 2 && j == map.colone / 2)
                return(tab[i][j]);
            j++;
        }
        i++;
    }
    return(tab[i][j]);
}
t_point **rotation_z(t_point **tab, t_map map, double angle)
{
    int i;
    int j;
    double alpha;
    int tmp;
    t_point midle;
    

    i = 0;
    j = 0;
    alpha = angle * PI / 180;
    midle = rot_z(tab, map);
    while (i < map.line)
    {
        j = 0;
        while (j < map.colone)
        {
            tab[i][j].x_ind -= midle.x_ind;
            tab[i][j].y_ind -= midle.y_ind; 
            tmp = tab[i][j].x_ind;
            tab[i][j].x_ind = (double)tab[i][j].x_ind - sin(alpha) * (double)tab[i][j].y_ind;
            tab[i][j].y_ind = (double)tmp * sin(alpha) + cos(alpha) * (double)tab[i][j].y_ind;
            tab[i][j].z  *= 5;
            tab[i][j].x_ind += 900;
            tab[i][j].y_ind += 900;
            j++;
        }
        i++;
    }
    return (tab);
}


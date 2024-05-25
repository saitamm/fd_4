/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_pixel.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sait-amm <sait-amm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 09:40:39 by sait-amm          #+#    #+#             */
/*   Updated: 2024/05/23 10:45:57 by sait-amm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include_file/header.h"

float ft_spole(t_point *point_1, t_point *point_2)
{
    int dx;
    int dy;

    dx  = point_2->x_ind -point_1->x_ind;
    dy  = point_2->y_ind -point_1->y_ind;
    return (dy / dx);
}

void draw_point(t_point x,void *mlx_ptr, void *window)
{
    int color;

    color = x.red * 256 * 256 + x.green * 256 + x.blue;
    mlx_pixel_put(mlx_ptr, window, x.x_ind, x.y_ind, color);
}

void draw_line(t_point **tab, t_map *map,void *mlx_ptr, void *win_ptr, t_mlx *mlx)
{
    int i;
    int j;

    i = 0;
    j = 0;
    while (i < map->line)
    {
        j = 0;
        while (j < map->colone)
        {
            if (i + 1 < map->line)
                bresenham(tab[i][j], tab[i + 1][j], mlx_ptr, win_ptr, mlx);
            if (j + 1 < map->colone)
                bresenham(tab[i][j], tab[i][j+1], mlx_ptr, win_ptr, mlx);
            j++; 
        }
        i++;
    }

}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fun_initial.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sait-amm <sait-amm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 12:00:42 by sait-amm          #+#    #+#             */
/*   Updated: 2024/05/25 20:06:59 by sait-amm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include_file/header.h"

void    whithout_color(int i, int j, t_point *tab, char *str)
{
    tab->y = i;
    tab->x = j;
    tab->blue = 255;
    tab->green = 255;
    tab->red = 255;
    tab->z = ft_atoi(str);
}

void    whith_color(int i, int j, t_point *tab, char *str)
{
    tab->y = i;
    tab->x = j;
    tab->z = ft_atoi(str);
    while (str && str[0] != 'x')
        str++;
    str++;
    tab->red = ft_atoi_base(str, 16, 0);
    str = str+2;
    tab->green = ft_atoi_base(str, 16, 0);
    str = str + 2;
    tab->blue = ft_atoi_base(str, 16, 0);
}

void    ft_init_map(int fd, t_map *map)
{
    map->buff = ft_read_map(fd);
    map->line = num_line(map->buff);
    map->colone = num_colone(map->buff);
    map->point_num = map->line * map->colone;
}

int max(int a, int b)
{
    if ( a < b)
        return (b);
    return (a);
}
void   ft_init_mlx(t_map *map, t_mlx *mlx)
{
    int pixels_x;

    mlx->x_index = INT_START_X;
    mlx->y_index = INT_START_Y;
    mlx->x_max = L_WIN - 100;
    mlx->y_max = LE_WIN - 100;
    pixels_x = mlx->x_max - mlx->x_index;
    mlx->step  = pixels_x /  max(map->line, map->colone) * 0.4;
    if (mlx->step < 1)
        mlx->step = 1;
    else if (mlx->step > 50)
        mlx->step = 50;
}

t_point **ft_index_window(t_point **tab, t_mlx *mlx, t_map *map)
{
    int i;
    int j;

    i = 0;
    j = 0;
    
    while(i < map->line )
    {
        j = 0;
        while(j < map->colone)
        {
            tab[i][j].x_ind = j * mlx->step + mlx->x_index;
            tab[i][j].y_ind = i * mlx->step + mlx->y_index;
            j++;
        }
        i++;
    }
    return (tab);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_mouse.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sait-amm <sait-amm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 08:51:13 by sait-amm          #+#    #+#             */
/*   Updated: 2024/05/29 09:02:54 by sait-amm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include_file/header.h"

t_point **update_coordinates(t_point **tab, t_map map)
{
    int i;
    int j;

    i = 0;
    while (i < map.line)
    {
        j = 0;
        while (j < map.colone)
            {
                tab[i][j].x_ind *= ZOOM_FAC;
                tab[i][j].y_ind *= ZOOM_FAC;
                j++;
            }
        i++;
    }
    return (tab);
}
t_point **zoom_int(t_data *data, t_point **tab, t_map map)
{
    int new_width;
    int new_height;
    void    *new_img;
    char *new_data;

    data->zoom_level = 1;
    data->zoom_level *= ZOOM_FAC;
    tab = update_coordinates(tab, map);
    new_width = L_WIN / data->zoom_level;
    new_height = LE_WIN / data->zoom_level;
    new_img = mlx_new_image(data->mlx, new_width, new_height);
    new_data = mlx_get_data_addr(new_img, &data->bpp, &data->size_line, &data->endian);
    mlx_destroy_image(data->mlx, data->img);
    data->img = new_img;
    data->img_data = new_data;
    mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
    return (tab);
}

int handle_key(int keycode, t_data *data) 
{
    if (keycode == ESC_KEY) {
        mlx_destroy_window(data->mlx, data->win);
        exit(0);
    }
    return 0;
}

int handle_close(t_data *data)
{
    mlx_destroy_window(data->mlx, data->win);
    exit(0);
    return (0);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rot_xyz.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sait-amm <sait-amm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 16:58:38 by sait-amm          #+#    #+#             */
/*   Updated: 2024/05/30 17:20:13 by sait-amm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include_file/header.h"


void update_data_rot(t_data **data)
{
    (*data)->img = mlx_new_image((*data)->mlx, L_WIN, LE_WIN);
    (*data)->img_data = mlx_get_data_addr((*data)->img, &(*data)->bpp, &(*data)->size_line, &(*data)->endian);
    (*data)->tab = ft_index_window(ft_to_array((*data)->map), (*data)->stp, (*data)->map);
    (*data)->tab = rotation_z((*data)->tab, (*data)->map, (*data)->angle.angle_z);
    (*data)->tab = rotation_x((*data)->tab, (*data)->map, (*data)->angle.angle_x);
    (*data)->tab = rotation_y((*data)->tab, (*data)->map, (*data)->angle.angle_y);
}
void rot_x(t_data *data)
{
    mlx_clear_window(data->mlx, data->win);
    mlx_destroy_image(data->mlx, data->img);
    data->angle.angle_x += 5;
    update_data_rot(&data);
    draw_line(data->tab, data->map, data);
    mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
}

void rot_y(t_data *data)
{
    mlx_clear_window(data->mlx, data->win);
    mlx_destroy_image(data->mlx, data->img);
    data->angle.angle_y += 5;
    update_data_rot(&data);
    draw_line(data->tab, data->map, data);
    mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
}

void rot_z(t_data *data)
{
    mlx_clear_window(data->mlx, data->win);
    mlx_destroy_image(data->mlx, data->img);
    data->angle.angle_z += 5;
    update_data_rot(&data);
    draw_line(data->tab, data->map, data);
    mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
}
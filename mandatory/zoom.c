/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sait-amm <sait-amm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 08:51:13 by sait-amm          #+#    #+#             */
/*   Updated: 2024/05/30 17:50:12 by sait-amm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include_file/header.h"

// t_point **zoom_int(t_data *data, t_point **tab, t_map map)
// {
//     int new_width;
//     int new_height;
//     void    *new_img;
//     char *new_data;

//     data->zoom_level = 1;
//     data->zoom_level *= ZOOM_FAC;
//     tab = update_coordinates(tab, map);
//     new_width = L_WIN / data->zoom_level;
//     new_height = LE_WIN / data->zoom_level;
//     new_img = mlx_new_image(data->mlx, new_width, new_height);
//     new_data = mlx_get_data_addr(new_img, &data->bpp, &data->size_line, &data->endian);
//     mlx_destroy_image(data->mlx, data->img);
//     data->img = new_img;
//     data->img_data = new_data;
//     mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
//     return (tab);
// }

int handle_close(t_data *data)
{
    mlx_destroy_window(data->mlx, data->win);
    exit(0);
    return (0);
}

void update_data(t_data **data)
{
(*data)->img = mlx_new_image((*data)->mlx, L_WIN, LE_WIN);
(*data)->img_data = mlx_get_data_addr((*data)->img, &(*data)->bpp, &(*data)->size_line, &(*data)->endian);
(*data)->tab = ft_index_window(ft_to_array((*data)->map), (*data)->stp, (*data)->map);
(*data)->tab = rotation_z((*data)->tab, (*data)->map, (*data)->angle.angle_z);
(*data)->tab = rotation_x((*data)->tab, (*data)->map, (*data)->angle.angle_x);
}
void draw_image_in(t_data *data)
{
    mlx_clear_window(data->mlx, data->win);
    mlx_destroy_image(data->mlx, data->img);
    data->stp.step += data->zoom_level;
    update_data(&data);
    draw_line(data->tab, data->map, data);
    mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
}

void draw_image_out(t_data *data)
{
    mlx_clear_window(data->mlx, data->win);
    mlx_destroy_image(data->mlx, data->img);
    data->stp.step -= data->zoom_level;
    update_data(&data);
    draw_line(data->tab, data->map, data);
    mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
}

int handle_key(int keycode, t_data *data) 
{
    // printf("&&&&&&&&&%d\n", keycode);
    if (keycode == 53)
    {
        mlx_destroy_window(data->mlx, data->win);
        exit(0);
    }
    if (keycode == 65451) 
    {
        data->zoom_level++;
        draw_image_in(data);
    }
    if (keycode == 65453 && data->stp.step != 1) 
    {
        data->zoom_level--;
        draw_image_out(data);
    }
    if (keycode == 120)
        rot_x(data);
    if (keycode == 121)
        rot_y(data);
    if (keycode == 122)
        rot_z(data);
    return (0);
}
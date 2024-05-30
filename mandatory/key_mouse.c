/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_mouse.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sait-amm <sait-amm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 08:51:13 by sait-amm          #+#    #+#             */
/*   Updated: 2024/05/30 12:51:30 by sait-amm         ###   ########.fr       */
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

// int handle_key(int keycode, t_data *data) 
// {
//     if (keycode == ESC_KEY) {
//         mlx_destroy_window(data->mlx, data->win);
//         exit(0);
//     }
//     return 0;
// }

int handle_close(t_data *data)
{
    mlx_destroy_window(data->mlx, data->win);
    exit(0);
    return (0);
}

// int handle_key(int keycode, t_data *data, t_point **tab, t_map map)
// {
//     if (keycode == 53) {
//         mlx_destroy_window(data->mlx, data->win);
//         exit(0);
//     }
//     if (keycode == 69) {
//         data->zoom_level++;
//         draw_image(data, tab, map);
//     }
//     if (keycode == 78) {
//         data->zoom_level = data->zoom_level > 1 ? data->zoom_level - 1 : 1;
//         draw_image(data, tab, map);
//     }
//     return (0);
// }
void update_data(t_data **data)
{
(*data)->img = mlx_new_image((*data)->mlx, L_WIN, LE_WIN);
(*data)->img_data = mlx_get_data_addr((*data)->img, &(*data)->bpp, &(*data)->size_line, &(*data)->endian);
(*data)->tab = ft_index_window(ft_to_array((*data)->map), (*data)->stp, (*data)->map);
(*data)->tab = rotation_z((*data)->tab, (*data)->map, -45);
    (*data)->tab = rotation_x((*data)->tab, (*data)->map, 30);
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
    if (data->zoom_level != 0 && data->stp.step > 1)
        data->stp.step /= data->zoom_level;
    update_data(&data);
    draw_line(data->tab, data->map, data);
    mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
}

int handle_key(int keycode, t_data *data) 
{
    if (keycode == 53) {
        mlx_destroy_window(data->mlx, data->win);
        exit(0);
    }
    if (keycode == 65362) 
    {
    printf("::%d\n", keycode);
        data->zoom_level += 2;
        draw_image_in(data);
    }
    if (keycode == 65364) 
    {
    printf("::%d\n", keycode);
        data->zoom_level--;
        printf("^^^^%d\n", data->zoom_level);
        draw_image_out(data);
    }
    return (0);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   translation.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sait-amm <sait-amm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 18:23:14 by sait-amm          #+#    #+#             */
/*   Updated: 2024/06/01 12:02:19 by sait-amm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include_file/header.h"

void update_data_left(t_data **data)
{
    int i;
    int j;

    i = 0;

    (*data)->img_data = mlx_get_data_addr((*data)->img, &(*data)->bpp, &(*data)->size_line, &(*data)->endian);
    // (*data)->tab = ft_index_window(ft_to_array((*data)->map), (*data)->stp, (*data)->map);
    while (i < (*data)->map.line)
    {
        j = 0;
        while (j < (*data)->map.colone)
        {
            (*data)->tab[i][j].x_ind += 10;
            j++;
        }
        i++;
    }
}

void update_data_right(t_data **data)
{
    int i;
    int j;

    i = 0;
    (*data)->img_data = mlx_get_data_addr((*data)->img, &(*data)->bpp, &(*data)->size_line, &(*data)->endian);
    while (i < (*data)->map.line)
    {
        j = 0;
        while (j < (*data)->map.colone)
        {
            (*data)->tab[i][j].x_ind -= 10;
            j++;
        }
        i++;
    }
}

void update_data_up(t_data **data)
{
    int i;
    int j;

    i = 0;
    (*data)->img_data = mlx_get_data_addr((*data)->img, &(*data)->bpp, &(*data)->size_line, &(*data)->endian);
    while (i < (*data)->map.line)
    {
        j = 0;
        while (j < (*data)->map.colone)
        {
            (*data)->tab[i][j].y_ind -= 10;
            j++;
        }
        i++;
    }
}
void update_data_down(t_data **data)
{
    int i;
    int j;

    i = 0;
    (*data)->img_data = mlx_get_data_addr((*data)->img, &(*data)->bpp, &(*data)->size_line, &(*data)->endian);
    while (i < (*data)->map.line)
    {
        j = 0;
        while (j < (*data)->map.colone)
        {
            (*data)->tab[i][j].y_ind += 10;
            j++;
        }
        i++;
    }
}
void trans_left(t_data *data)
{
    draw_image(data);
    update_data_left(&data);
    draw_line(data->tab, data->map, data);
    mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
}
void trans_right(t_data *data)
{
    draw_image(data);
    update_data_right(&data);
    draw_line(data->tab, data->map, data);
    mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
}
void trans_down(t_data *data)
{
    draw_image(data);
    update_data_down(&data);
    draw_line(data->tab, data->map, data);
    mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
}

void trans_up(t_data *data)
{
    draw_image(data);
    update_data_up(&data);
    draw_line(data->tab, data->map, data);
    mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
}
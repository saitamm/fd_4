/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sait-amm <sait-amm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 08:51:13 by sait-amm          #+#    #+#             */
/*   Updated: 2024/06/04 20:00:38 by sait-amm         ###   ########.fr       */
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
//     new_data = mlx_get_data_addr(new_img, &data->bpp, &data->size_line,
		// &data->endian);
//     mlx_destroy_image(data->mlx, data->img);
//     data->img = new_img;
//     data->img_data = new_data;
//     mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
//     return (tab);
// }

int	handle_close(t_data *data)
{
	mlx_destroy_window(data->mlx, data->win);
	exit(0);
	return (0);
}

void		update_data(t_data **data)
{
	(*data)->img_data = mlx_get_data_addr((*data)->img, &(*data)->bpp,
			&(*data)->size_line, &(*data)->endian);
	free_tab((*data)->tab, (*data)->map);
	(*data)->tab = ft_index_window(ft_to_array((*data)->map), (*data)->stp,
			(*data)->map);
	(*data)->tab = rotation_z((*data)->tab, (*data)->map,
			(*data)->angle.angle_z);
	(*data)->tab = rotation_x((*data)->tab, (*data)->map,
			(*data)->angle.angle_x);
}
void	draw_image_in(t_data *data)
{
	int	i;
	int	j;

	draw_image(data);
	data->stp.step = data->stp.step + 2;
	update_data(&data);
	i = 0;
	while (i < data->map.line)
	{
		j = 0;
		while (j < data->map.colone)
		{
			data->tab[i][j].x_ind += 500;
			data->tab[i][j].y_ind += 500;
			j++;
		}
		i++;
	}
	draw_line(data->tab, data->map, data);
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
}

void	zoom_out_z(t_data **data)
{
	int	i;
	int	j;

	i = 0;
	while (i < (*data)->map.line)
	{
		j = 0;
		while (j < (*data)->map.colone)
		{
			(*data)->tab[i][j].z -= 6;
			j++;
		}
		i++;
	}
}
void	draw_image_out(t_data *data)
{
	int	i;
	int	j;

	draw_image(data);
	data->stp.step -= 2;
	update_data(&data);
	i = 0;
	while (i < data->map.line)
	{
		j = 0;
		while (j < data->map.colone)
		{
			data->tab[i][j].x_ind += 500;
			data->tab[i][j].y_ind += 500;
			j++;
		}
		i++;
	}
	draw_line(data->tab, data->map, data);
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
}

int	handle_key(int keycode, t_data *data)
{
	if (keycode == ESC_KEY)
	{
		ft_free_data(data);
		exit(0);
	}
	if (keycode == ZOOM_IN)
		draw_image_in(data);
	if (keycode == ZOOM_OUT && data->stp.step > 1)
		draw_image_out(data);
	if (keycode == ROT_X)
		rot_x(data);
	if (keycode == ROT_Y)
		rot_y(data);
	if (keycode == KEY_L)
		trans_left(data);
	if (keycode == KEY_R)
		trans_right(data);
	if (keycode == KEY_D)
		trans_down(data);
	if (keycode == KEY_W)
		trans_up(data);
	if (keycode == KEY_P)
		press_p(data);
	if (keycode == KEY_I)
		press_i(data);
	return (0);
}
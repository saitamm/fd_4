/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rot_xyz.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sait-amm <sait-amm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 16:58:38 by sait-amm          #+#    #+#             */
/*   Updated: 2024/06/03 20:32:15 by sait-amm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include_file/header.h"

void	update_data_rot(t_data **data)
{
	// (*data)->img = mlx_new_image((*data)->mlx, L_WIN, LE_WIN);
	(*data)->img_data = mlx_get_data_addr((*data)->img, &(*data)->bpp,
			&(*data)->size_line, &(*data)->endian);
	free_tab((*data)->tab, (*data)->map);
	(*data)->tab = ft_index_window(ft_to_array((*data)->map), (*data)->stp,
			(*data)->map);
	center_point(data);
	(*data)->tab = rotation_z((*data)->tab, (*data)->map,
			(*data)->angle.angle_z);
	(*data)->tab = rotation_x((*data)->tab, (*data)->map,
			(*data)->angle.angle_x);
	(*data)->tab = rotation_y((*data)->tab, (*data)->map,
			(*data)->angle.angle_y);
}
void	rot_x(t_data *data)
{
	int	i;
	int	j;

	draw_image(data);
	data->angle.angle_x += 5;
	update_data_rot(&data);
	i = 0;
	// data->tab = rotation_z(data->tab, data->map, 30);
    // data->tab = rotation_x(data->tab, data->map, 25);
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

void	rot_y(t_data *data)
{
	int	i;
	int	j;

	draw_image(data);
	data->angle.angle_y += 5;
	update_data_rot(&data);
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

void	rot_z(t_data *data)
{
	draw_image(data);
	data->angle.angle_z += 5;
	update_data_rot(&data);
	int i;
	int j;
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
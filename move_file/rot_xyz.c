/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rot_xyz.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sait-amm <sait-amm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 16:58:38 by sait-amm          #+#    #+#             */
/*   Updated: 2024/06/05 12:00:51 by sait-amm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include_file/fdf.h"

void	rot_x(t_data *data)
{
	int	i;
	int	j;

	draw_image(data);
	data->angle.angle_x += 5;
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
	int	i;
	int	j;

	draw_image(data);
	data->angle.angle_z += 5;
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

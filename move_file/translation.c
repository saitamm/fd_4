/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   translation.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sait-amm <sait-amm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 18:23:14 by sait-amm          #+#    #+#             */
/*   Updated: 2024/06/05 12:09:16 by sait-amm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include_file/fdf.h"

void	trans_right(t_data *data)
{
	draw_image(data);
	update_data_right(&data);
	draw_line(data->tab, data->map, data);
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
}

void	trans_down(t_data *data)
{
	draw_image(data);
	update_data_down(&data);
	draw_line(data->tab, data->map, data);
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
}

void	trans_up(t_data *data)
{
	draw_image(data);
	update_data_up(&data);
	draw_line(data->tab, data->map, data);
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
}

void	press_p(t_data *data)
{
	draw_image(data);
	update_data_p(&data);
	draw_line(data->tab, data->map, data);
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
}

void	press_i(t_data *data)
{
	draw_image(data);
	update_data_i(&data);
	draw_line(data->tab, data->map, data);
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
}

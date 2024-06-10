/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sait-amm <sait-amm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 08:51:13 by sait-amm          #+#    #+#             */
/*   Updated: 2024/06/07 09:40:11 by sait-amm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include_file/fdf.h"

void	draw_image_in(t_data *data)
{
	draw_image(data);
	data->stp.step = data->stp.step + 2;
	update_data(&data);
	data->img_data = mlx_get_data_addr(data->img, &data->bpp, &data->size_line,
			&data->endian);
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
	draw_image(data);
	data->stp.step -= 2;
	update_data(&data);
	draw_line(data->tab, data->map, data);
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
}

int	handle_key(int keycode, t_data *data)
{
	printf("^^^^^^^^^^^^^^%d\n", keycode);
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
	if (keycode == KEY_Z)
		bonus_choice(data);
	return (0);
}

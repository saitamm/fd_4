/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   translation.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sait-amm <sait-amm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 18:23:14 by sait-amm          #+#    #+#             */
/*   Updated: 2024/06/03 20:34:01 by sait-amm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include_file/header.h"

void	update_data_left(t_data **data)
{
	int	i;
	int	j;

	i = 0;
	(*data)->img_data = mlx_get_data_addr((*data)->img, &(*data)->bpp,
			&(*data)->size_line, &(*data)->endian);
	// (*data)->tab = ft_index_window(ft_to_array((*data)->map), (*data)->stp,
			// (*data)->map);
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

void	update_data_right(t_data **data)
{
	int	i;
	int	j;

	i = 0;
	(*data)->img_data = mlx_get_data_addr((*data)->img, &(*data)->bpp,
			&(*data)->size_line, &(*data)->endian);
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

void	update_data_up(t_data **data)
{
	int	i;
	int	j;

	i = 0;
	(*data)->img_data = mlx_get_data_addr((*data)->img, &(*data)->bpp,
			&(*data)->size_line, &(*data)->endian);
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
void	update_data_down(t_data **data)
{
	int	i;
	int	j;

	i = 0;
	(*data)->img_data = mlx_get_data_addr((*data)->img, &(*data)->bpp,
			&(*data)->size_line, &(*data)->endian);
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
void	trans_left(t_data *data)
{
	draw_image(data);
	update_data_left(&data);
	draw_line(data->tab, data->map, data);
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
}
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

void	update_data_p(t_data **data)
{
	int	i;
	int	j;

	(*data)->img_data = mlx_get_data_addr((*data)->img, &(*data)->bpp,
			&(*data)->size_line, &(*data)->endian);
	free_tab((*data)->tab, (*data)->map);
	(*data)->tab = ft_index_window(ft_to_array((*data)->map), (*data)->stp,
			(*data)->map);
	i = 0;
	while (i < (*data)->map.line)
	{
		j = 0;
		while (j < (*data)->map.colone)
		{
			(*data)->tab[i][j].x_ind += 250;
			(*data)->tab[i][j].y_ind += 250;
			j++;
		}
		i++;
	}
}
void	press_p(t_data *data)
{
	draw_image(data);
	update_data_p(&data);
	draw_line(data->tab, data->map, data);
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
}

void	update_data_i(t_data **data)
{
	int	i;
	int	j;

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
	i = 0;
	while (i < (*data)->map.line)
	{
		j = 0;
		while (j < (*data)->map.colone)
		{
			(*data)->tab[i][j].x_ind += 500;
			(*data)->tab[i][j].y_ind += 500;
			j++;
		}
		i++;
	}
}
void	press_i(t_data *data)
{
	draw_image(data);
	update_data_i(&data);
	draw_line(data->tab, data->map, data);
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
}
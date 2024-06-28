/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   updat_data.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sait-amm <sait-amm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 08:45:48 by sait-amm          #+#    #+#             */
/*   Updated: 2024/06/27 20:08:45 by sait-amm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include_file/fdf.h"

void	update_data_rot(t_data **data)
{
	free_tab((*data)->tab, (*data)->map);
	(*data)->tab = ft_index_window(ft_to_array((*data)->map), (*data)->stp,
			(*data)->map);
	center_point(data);
	(*data)->tab = rotation_z_bonus((*data)->tab, (*data)->map,
			-(*data)->angle.angle_z);
	(*data)->tab = rotation_x((*data)->tab, (*data)->map,
			-(*data)->angle.angle_x);
	(*data)->tab = rotation_y((*data)->tab, (*data)->map,
			(*data)->angle.angle_y);
}

void	update_data_left(t_data **data)
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

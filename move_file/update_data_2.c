/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_data_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sait-amm <sait-amm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 08:47:54 by sait-amm          #+#    #+#             */
/*   Updated: 2024/06/10 10:27:42 by sait-amm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include_file/fdf.h"

void	update_data_p(t_data **data)
{
	int	i;
	int	j;

	(*data)->img_data = mlx_get_data_addr((*data)->img, &(*data)->bpp,
			&(*data)->size_line, &(*data)->endian);
	free_tab((*data)->tab, (*data)->map);
	(*data)->tab = ft_index_window(ft_to_array((*data)->map), (*data)->stp,
			(*data)->map);
	center_point(data);
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
	(*data)->tab = rotation_z_bonus((*data)->tab, (*data)->map,
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

void	update_data(t_data **data)
{
	int	i;
	int	j;

	(*data)->img_data = mlx_get_data_addr((*data)->img, &(*data)->bpp,
			&(*data)->size_line, &(*data)->endian);
	free_tab((*data)->tab, (*data)->map);
	(*data)->tab = ft_index_window(ft_to_array((*data)->map), (*data)->stp,
			(*data)->map);
	(*data)->tab = rotation_z_bonus((*data)->tab, (*data)->map,
			(*data)->angle.angle_z);
	(*data)->tab = rotation_x((*data)->tab, (*data)->map,
			(*data)->angle.angle_x);
	(*data)->tab = rotation_y((*data)->tab, (*data)->map,
			(*data)->angle.angle_y);
	i = 0;
	center_point(data);

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

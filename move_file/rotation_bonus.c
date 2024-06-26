/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sait-amm <sait-amm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 09:34:34 by sait-amm          #+#    #+#             */
/*   Updated: 2024/06/26 21:17:47 by sait-amm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include_file/fdf.h"

int	ft_help_z_bonus(int z, int max, int min)
{
	if (max < 10 && min >= 0)
		z *= 25;
	else if (max > 10 && max <= 20 && min > 0)
		z *= 15;
	else
		z *= 3;
	return (z);
}

t_point	**rotation_z_bonus(t_point **tab, t_map map, double angle)
{
	int	i;
	int	j;
	int	tmp;
	t_z	z;

	z.max_z = max_z(tab, map);
	z.min_z = min_z(tab, map);
	i = 0;
	angle = angle * PI / 180;
	while (i < map.line)
	{
		j = 0;
		while (j < map.colone)
		{
			tmp = tab[i][j].x_ind;
			tab[i][j].x_ind = (double)tab[i][j].x_ind - sin(angle)
				* (double)tab[i][j].y_ind;
			tab[i][j].y_ind = (double)tmp * sin(angle) + cos(angle)
				* (double)tab[i][j].y_ind;
			tab[i][j].z = ft_help_z_bonus(tab[i][j].z, z.max_z, z.min_z);
			j++;
		}
		i++;
	}
	return (tab);
}

void	update_z(t_data **data)
{
	int	i;
	int	j;

	i = 0;
	(*data)->img_data = mlx_get_data_addr((*data)->img, &(*data)->bpp,
			&(*data)->size_line, &(*data)->endian);
	free_tab((*data)->tab, (*data)->map);
	(*data)->tab = ft_index_window(ft_to_array((*data)->map), (*data)->stp,
			(*data)->map);
	center_point(data);
	(*data)->z_choice += 2;
	while (i < (*data)->map.line)
	{
		j = 0;
		while (j < (*data)->map.colone)
		{
			(*data)->tab[i][j].z *= (*data)->z_choice;
			j++;
		}
		i++;
	}
	(*data)->tab = rotation_z_bonus((*data)->tab, (*data)->map,
			(*data)->angle.angle_z);
	(*data)->tab = rotation_x((*data)->tab, (*data)->map,
			(*data)->angle.angle_x);
}

void	bonus_choice(t_data *data)
{
	int	i;
	int	j;

	draw_image(data);
	update_z(&data);
	i = 0;
	j = 0;
	while (i < data->map.line)
	{
		j = 0;
		while (j < data->map.colone)
		{
			data->tab[i][j].x_ind += 500;
			data->tab[i][j].y_ind += 700;
			j++;
		}
		i++;
	}
	draw_line(data->tab, data->map, data);
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
}

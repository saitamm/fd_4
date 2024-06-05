/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sait-amm <sait-amm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 12:01:28 by sait-amm          #+#    #+#             */
/*   Updated: 2024/06/05 12:10:41 by sait-amm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include_file/fdf.h"

void	trans_left(t_data *data)
{
	draw_image(data);
	update_data_left(&data);
	draw_line(data->tab, data->map, data);
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
}

t_point	**rotation_x(t_point **tab, t_map map, double angle)
{
	int		i;
	int		j;
	int		tmp;
	double	alpha;

	i = 0;
	j = 0;
	alpha = angle * (PI / 180.0);
	while (i < map.line)
	{
		j = 0;
		while (j < map.colone)
		{
			tab[i][j].x_ind = tab[i][j].x_ind;
			tmp = tab[i][j].y_ind;
			tab[i][j].y_ind = tab[i][j].y_ind * sin(alpha) - sin(alpha)
				* tab[i][j].z;
			tab[i][j].z = tmp * cos(alpha) + cos(alpha) * tab[i][j].z;
			j++;
		}
		i++;
	}
	return (tab);
}

int	ft_help_z(int z, int max, int min)
{
	if (max < 10)
		z *= 65;
	else if (max > 10 && max <= 20 && min > 0)
		z *= 50;
	else
		z *= 3;
	return (z);
}

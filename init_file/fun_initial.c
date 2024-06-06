/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fun_initial.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sait-amm <sait-amm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 12:00:42 by sait-amm          #+#    #+#             */
/*   Updated: 2024/06/06 10:36:33 by sait-amm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include_file/fdf.h"

int	max(int a, int b)
{
	if (a < b)
		return (b);
	return (a);
}

void	ft_init_mlx(t_map map, t_mlx *mlx)
{
	int	pixels_x;

	mlx->x_index = INT_START_X;
	mlx->y_index = INT_START_Y;
	mlx->x_max = L_WIN - 100;
	mlx->y_max = LE_WIN - 100;
	pixels_x = mlx->x_max - mlx->x_index;
	mlx->step = pixels_x / max(map.line, map.colone) * 0.6;
	if (mlx->step <= 1)
	{
		mlx->step = 1;
	}
	else if (mlx->step > 50)
		mlx->step = 50;
}

t_point	**ft_index_window(t_point **tab, t_mlx mlx, t_map map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < map.line)
	{
		j = 0;
		while (j < map.colone)
		{
			tab[i][j].x_ind = j * mlx.step + mlx.x_index;
			tab[i][j].y_ind = i * mlx.step + mlx.y_index;
			j++;
		}
		i++;
	}
	return (tab);
}

void	center_point(t_data **data)
{
	t_point	midle;
	int		i;
	int		j;

	i = 0;
	j = 0;
	midle = middle((*data)->tab, (*data)->map);
	while (i < (*data)->map.line)
	{
		j = 0;
		while (j < (*data)->map.colone)
		{
			(*data)->tab[i][j].x_ind -= midle.x_ind;
			(*data)->tab[i][j].y_ind -= midle.y_ind;
			j++;
		}
		i++;
	}
}

t_data	*initial_data(int fd)
{
	t_data	*data;

	data = (t_data *)malloc(sizeof(t_data));
	if (!data)
		return (NULL);
	ft_init_map(fd, &data->map);
	ft_init_mlx(data->map, &data->stp);
	data->tab = ft_index_window(ft_to_array(data->map), data->stp, data->map);
	center_point(&data);
	data->mlx = mlx_init();
	data->img = mlx_new_image(data->mlx, L_WIN, LE_WIN);
	data->img_data = mlx_get_data_addr(data->img, &data->bpp, &data->size_line,
			&data->endian);
	data->win = mlx_new_window(data->mlx, L_WIN, LE_WIN, "fdf");
	data->angle.angle_z = 45;
	data->angle.angle_x = 45;
	data->angle.angle_y = 0;
	data->z_choice = 2;
	return (data);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sait-amm <sait-amm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 11:13:29 by sait-amm          #+#    #+#             */
/*   Updated: 2024/06/27 20:07:19 by sait-amm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include_file/fdf.h"

void	error_file(int ac, int fd, char **av)
{
	if (ac != 2)
	{
		write(2, "no more or less than two arguments", 35);
		exit(1);
	}
	if (fd < 0 || check_file(av[1]) == 1)
	{
		write(2, "error file", 11);
		exit(1);
	}
}

void	key_manda(t_data *data, int fd)
{
	draw_line(data->tab, data->map, data);
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
	mlx_key_hook(data->win, handle_key_close_mand, data);
	mlx_hook(data->win, DESTROY_NOTIFY, 0, handle_close, data);
	mlx_loop(data->mlx);
	close(fd);
	ft_free_data(data);
}

t_point	**tab_iso(t_data *data)
{
	int	x_p;
	int	y_p;
	int	i;
	int	j;
	t_z	z;

	i = 0;
	z.max_z = max_z(data->tab, data->map);
	z.min_z = min_z(data->tab, data->map);
	while (i < data->map.line)
	{
		j = 0;
		while (j < data->map.colone)
		{
			x_p = data->tab[i][j].x_ind;
			y_p = data->tab[i][j].y_ind;
			data->tab[i][j].z = ft_help_z(data->tab[i][j].z, z.max_z, z.min_z);
			data->tab[i][j].x_ind = (x_p - y_p) * cos(0.523599);
			data->tab[i][j].y_ind = -data->tab[i][j].z + (x_p + y_p)
				* sin(0.523599);
			j++;
		}
		i++;
	}
	return (data->tab);
}

int	main(int ac, char **av)
{
	int		fd;
	t_data	*data;
	int		i;
	int		j;

	fd = open(av[1], O_RDONLY, 0644);
	error_file(ac, fd, av);
	data = initial_data(fd);
	data->tab = tab_iso(data);
	draw_image(data);
	i = -1;
	while (++i < data->map.line)
	{
		j = 0;
		while (j < data->map.colone)
		{
			data->tab[i][j].x_ind += 500;
			data->tab[i][j++].y_ind += 500;
		}
	}
	key_manda(data, fd);
}

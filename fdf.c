/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sait-amm <sait-amm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 11:13:29 by sait-amm          #+#    #+#             */
/*   Updated: 2024/06/26 21:12:40 by sait-amm         ###   ########.fr       */
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
	mlx_key_hook(data->win, handle_key_close, data);
	mlx_hook(data->win, DESTROY_NOTIFY, 0, handle_close, data);
	mlx_loop(data->mlx);
	close(fd);
	ft_free_data(data);
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
	data->tab = rotation_z(data->tab, data->map, 45);
	data->tab = rotation_x(data->tab, data->map, 45);
	draw_image(data);
	i = -1;
	while (++i < data->map.line)
	{
		j = 0;
		while (j < data->map.colone)
		{
			data->tab[i][j].x_ind += 500;
			data->tab[i][j++].y_ind += 700;
		}
	}
	key_manda(data, fd);
}

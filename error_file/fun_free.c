/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fun_free.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sait-amm <sait-amm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 08:54:38 by sait-amm          #+#    #+#             */
/*   Updated: 2024/06/05 08:34:56 by sait-amm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include_file/fdf.h"

// void free_map(t_map *map)
// {
//     free(map->buff);
//     free(map);
// }
void	free_tab(t_point **tab, t_map map)
{
	int	i;

	i = 0;
	while (i < map.line)
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}
void	ft_free_data(t_data *data)
{
	free_tab(data->tab, data->map);
	free(data->map.buff);
	if (data->img)
		mlx_destroy_image(data->mlx, data->img);
	if (data->win)
		mlx_destroy_window(data->mlx, data->win);
	mlx_destroy_display(data->mlx);
	if (data->mlx)
		free(data->mlx);
	free(data);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sait-amm <sait-amm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 09:34:34 by sait-amm          #+#    #+#             */
/*   Updated: 2024/06/06 10:40:57 by sait-amm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../include_file/fdf.h"

t_point	**rotation_z_bonus(t_point **tab, t_map map, double angle)
{
	int		i;
	int		j;
	int		tmp;

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
			tab[i][j].z = tab[i][j].z;
			j++;
		}
		i++;
	}
	return (tab);
}

void update_z(t_data **data)
{
    int i;
    int j;

    i = 0;
    (*data)->img_data = mlx_get_data_addr((*data)->img, &(*data)->bpp,
			&(*data)->size_line, &(*data)->endian);
    free_tab((*data)->tab, (*data)->map);
	(*data)->tab = ft_index_window(ft_to_array((*data)->map), (*data)->stp,
			(*data)->map);
	center_point(data);
    (*data)->z_choice +=2;
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

void    bonus_choice(t_data *data)
{
    draw_image(data);
    update_z(&data);
    int i = 0;
    int j = 0;
     while (i < data->map.line)
    {
        j = 0;
        while (j < data->map.colone)
        {
            data->tab[i][j].x_ind += 500;
			data->tab[i][j].y_ind += 500;
            data->tab[i][j].y_ind -= data->tab[i][j].z;
            j++;
        }
        i++;
    }
    draw_line(data->tab, data->map, data);
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
}

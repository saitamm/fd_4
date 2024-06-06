/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sait-amm <sait-amm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 11:37:00 by sait-amm          #+#    #+#             */
/*   Updated: 2024/06/06 09:21:09 by sait-amm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include_file/fdf.h" 

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

int	min_z(t_point **tab, t_map map)
{
	int	i;
	int	j;
	int	min_z;

	min_z = tab[0][0].z;
	i = 0;
	while (i < map.line)
	{
		j = 0;
		while (j < map.colone)
		{
			if (tab[i][j].z < min_z)
				min_z = tab[i][j].z;
			j++;
		}
		i++;
	}
	return (min_z);
}

int	max_z(t_point **tab, t_map map)
{
	int	i;
	int	j;
	int	max_z;

	i = 0;
	max_z = tab[0][0].z;
	while (i < map.line)
	{
		j = 0;
		while (j < map.colone)
		{
			if (tab[i][j].z > max_z)
				max_z = tab[i][j].z;
			j++;
		}
		i++;
	}
	return (max_z);
}

t_point	middle(t_point **tab, t_map map)
{
	int	i;
	int	j;

	i = 0;
	while (i < map.line)
	{
		j = 0;
		while (j < map.colone)
		{
			if (i == map.line / 2 && j == map.colone / 2)
				return (tab[i][j]);
			j++;
		}
		i++;
	}
	return (tab[i][j]);
}

t_point	**rotation_z(t_point **tab, t_map map, double angle)
{
	int		i;
	int		j;
	int		tmp;
	t_z		z;

	i = 0;
	z.max_z = max_z(tab, map);
	z.min_z = min_z(tab, map);
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
			tab[i][j].z = ft_help_z(tab[i][j].z, z.max_z, z.min_z);
			j++;
		}
		i++;
	}
	return (tab);
}

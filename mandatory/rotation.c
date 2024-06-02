/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sait-amm <sait-amm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 11:37:00 by sait-amm          #+#    #+#             */
/*   Updated: 2024/06/02 10:32:09 by sait-amm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include_file/header.h"

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

t_point	**rotation_y(t_point **tab, t_map map, double angle)
{
	int		i;
	int		j;
	int		tmp;
	double	alpha;

	i = 0;
	j = 0;
	alpha = angle * PI / 180;
	while (i < map.line)
	{
		j = 0;
		while (j < map.colone)
		{
			tab[i][j].y_ind = tab[i][j].y_ind;
			tmp = tab[i][j].x_ind;
			tab[i][j].x_ind = tab[i][j].x_ind * cos(alpha) + sin(alpha)
				* tab[i][j].z;
			tab[i][j].z = tmp * sin(alpha) + cos(alpha) * tab[i][j].z;
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
	double	alpha;
	int		tmp;
	t_point	midle;
	int		max;
	int		min;

	max = max_z(tab, map);
	min = min_z(tab, map);
	i = 0;
	alpha = angle * PI / 180;
	midle = middle(tab, map);
	while (i < map.line)
	{
		j = 0;
		while (j < map.colone)
		{
			tab[i][j].x_ind -= midle.x_ind;
			tab[i][j].y_ind -= midle.y_ind;
			tmp = tab[i][j].x_ind;
			tab[i][j].x_ind = (double)tab[i][j].x_ind - sin(alpha)
				* (double)tab[i][j].y_ind;
			tab[i][j].y_ind = (double)tmp * sin(alpha) + cos(alpha)
				* (double)tab[i][j].y_ind;
			if (max <= 10)
				tab[i][j].z *= 65;
			else if (max > 10 && max <= 20 && min > 0)
				tab[i][j].z *= 50;
			else
				tab[i][j].z *= 3;
			j++;
		}
		i++;
	}
	return (tab);
}

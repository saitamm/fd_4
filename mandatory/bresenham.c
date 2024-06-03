/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sait-amm <sait-amm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 10:18:14 by sait-amm          #+#    #+#             */
/*   Updated: 2024/06/03 11:53:09 by sait-amm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include_file/header.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	int	offset;

	if (x < 0 || x >= L_WIN || y < 0 || y >= LE_WIN)
	{
		return ;
	}
	offset = (y * data->size_line) + (x * (data->bpp / 8));
	*((unsigned int *)(data->img_data + offset)) = color;
}

void	init_flag(t_bres_flag *s, t_point p0, t_point p1)
{
	s->dx = abs(p1.x_ind - p0.x_ind);
	s->dy = 
	abs(p1.y_ind - p0.y_ind);
	if (p0.x_ind < p1.x_ind)
		s->sx = 1;
	else
		s->sx = -1;
	if (p0.y_ind < p1.y_ind)
		s->sy = 1;
	else
		s->sy = -1;
	s->err = s->dx - s->dy;
}

void	bresenham(t_point p0, t_point p1, t_data *data)
{
	t_bres_flag	s;
	int			e2;
	int			color;

	init_flag(&s, p0, p1);
	color = p0.red * 256 * 256 + p0.green * 256 + p0.blue;
	while (1)
	{
		color = crem_color(&p0, p1, 72);
		my_mlx_pixel_put(data, p0.x_ind, p0.y_ind, color);
		// printf("x_end: %lf y_end: %lf\nx_start: %lf y_start: %lf\n",p1.x_ind,  p1.y_ind,p0.x_ind, p0.y_ind);
		if (p0.x_ind == p1.x_ind || p0.y_ind == p1.y_ind)
			break ;
		e2 = s.err * 2;
		if (e2 > -s.dy)
		{
			s.err -= s.dy;
			p0.x_ind += s.sx;
		}
		else if (e2 < s.dx)
		{
			s.err += s.dx;
			p0.y_ind += s.sy;
		}
	}
}

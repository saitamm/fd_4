/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sait-amm <sait-amm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 10:18:14 by sait-amm          #+#    #+#             */
/*   Updated: 2024/05/28 13:30:22 by sait-amm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include_file/header.h"

t_bres  *ft_initial(t_point x, t_point y)
{
    t_bres  *data;

    data = malloc(sizeof(t_bres));
    if(!data)
        return (NULL);
    data->dx = y.x_ind - x.x_ind;
    data->dy = y.y_ind - x.y_ind;
    if (data->dx && data->dy)
        data->slope = data->dy / data->dx;
    return (data);
}

int initial_p_k(t_point x, t_point y)
{
    int p_k;
    t_bres *data;

    data = ft_initial(x, y);
    if (data->slope < 1)
        p_k = 2 * data->dy - data->dx;
    else
        p_k = 2 * data->dx - data->dy;
    return (p_k);
}

void my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
    int offset;
    offset = (y * data->size_line) + (x * (data->bpp / 8));
    *((unsigned int *)(data->img_data + offset)) = color;
}
void bresenham(t_point p0, t_point p1,t_data *data) 
{
    int dx;
    int dy; 
    int sx;
    int  sy;
    int err;
    int e2;
    int color;
    
    dx = abs(p1.x_ind - p0.x_ind);
    dy = abs(p1.y_ind - p0.y_ind);
    if (p0.x_ind < p1.x_ind)
        sx = 1;
    else
        sx = -1;
    if (p0.y_ind < p1.y_ind)
        sy = 1;
    else
        sy = -1;
    err = dx - dy;
    color = p0.red *256 *256 + p0.green * 256 + p0.blue;
    while (1) 
    {
        color = crem_color(&p0, p1, 72);
        my_mlx_pixel_put(data, p0.x_ind, p0.y_ind, color); 
        if (p0.x_ind == p1.x_ind && p0.y_ind == p1.y_ind) 
            break;
        e2 = err * 2;
        if (e2 > -dy) 
        { 
            err -= dy; 
            p0.x_ind += sx; 
        }
        if (e2 < dx) 
        {
            err += dx; 
            p0.y_ind += sy; 
        }
    }
}

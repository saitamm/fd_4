/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_image.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sait-amm <sait-amm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 08:38:28 by sait-amm          #+#    #+#             */
/*   Updated: 2024/06/01 08:59:03 by sait-amm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include_file/header.h"

void    draw_image(t_data *data)
{
    int x;
    int y;

    x = 0;
    y = 0;
    while (x < L_WIN)
    {
        y = 0;
        while (y < LE_WIN)
        {
            my_mlx_pixel_put(data, x, y, 202020);
            y++;
        }
        x++;
    }
}
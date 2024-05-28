/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_rgb.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sait-amm <sait-amm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 10:24:09 by sait-amm          #+#    #+#             */
/*   Updated: 2024/05/28 10:21:21 by sait-amm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include_file/header.h"

float step_r(int x_red, int y_red, int nbr_pixel)
{
    float step_r;
    
    step_r = abs(y_red - x_red)/nbr_pixel;
    return (step_r);
}

float step_g(int x_green, int y_green, int nbr_pixel)
{
    float step_r;
    
    step_r = abs(y_green - x_green)/nbr_pixel;
    return (step_r);
}

float step_b(int x_blue, int y_blue, int nbr_pixel)
{
    float step_r;
    
    step_r = abs(y_blue - x_blue)/nbr_pixel;
    return (step_r);
}

void crem_red(int *x_red, int y_red, int nbr_pixel)
{
    if (*x_red < y_red)
        *x_red = *x_red + step_r(*x_red, y_red, nbr_pixel);
    else if (*x_red > y_red)
        *x_red = *x_red - step_r(*x_red, y_red, nbr_pixel);
}
void crem_green(int *x_green, int y_green, int nbr_pixel)
{
    if (*x_green < y_green)
        *x_green = *x_green + step_g(*x_green, y_green, nbr_pixel);
    else if (*x_green > y_green)
        *x_green = *x_green - step_g(*x_green, y_green, nbr_pixel);
}
void crem_blue(int *x_blue, int y_blue, int nbr_pixel)
{
    if (*x_blue < y_blue)
        *x_blue = *x_blue + step_b(*x_blue, y_blue, nbr_pixel);
    else if (*x_blue > y_blue)
        *x_blue = *x_blue - step_b(*x_blue, y_blue, nbr_pixel);
}


int crem_color(t_point *x, t_point y, int nbr_pixel)
{
    int color_1;
    int color_2;


    color_1 =x->red * 256 * 256 + x->green * 256 +x->blue ;
    color_2 =y.red * 256 * 256 + y.green * 256 +y.blue ;

    if (color_1 != color_2)
    {
        crem_red(&x->red, y.red, nbr_pixel);
        crem_green(&x->green, y.green, nbr_pixel);
        crem_blue(&x->blue, y.blue, nbr_pixel);
    }
    color_1 =x->red * 256 *256 +x->green * 256 +x->blue;
    return (color_1);
}



/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   crem_color.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sait-amm <sait-amm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 08:42:33 by sait-amm          #+#    #+#             */
/*   Updated: 2024/06/05 08:43:10 by sait-amm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include_file/fdf.h"

float	step_r(int x_red, int y_red, int nbr_pixel)
{
	float	step_r;

	step_r = abs(y_red - x_red) / nbr_pixel;
	return (step_r);
}

float	step_g(int x_green, int y_green, int nbr_pixel)
{
	float	step_r;

	step_r = abs(y_green - x_green) / nbr_pixel;
	return (step_r);
}

float	step_b(int x_blue, int y_blue, int nbr_pixel)
{
	float	step_r;

	step_r = abs(y_blue - x_blue) / nbr_pixel;
	return (step_r);
}

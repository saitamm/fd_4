/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_close.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sait-amm <sait-amm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 08:59:07 by sait-amm          #+#    #+#             */
/*   Updated: 2024/06/05 09:02:26 by sait-amm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include_file/fdf.h"

int	handle_key_close(int keycode, t_data *data)
{
	if (keycode == ESC_KEY)
	{
		ft_free_data(data);
		exit(0);
	}
	return (0);
}
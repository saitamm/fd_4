/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sait-amm <sait-amm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 12:26:57 by sait-amm          #+#    #+#             */
/*   Updated: 2024/06/05 11:57:37 by sait-amm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include_file/fdf.h"

char	*ft_read_map(int fd)
{
	char	*buff;
	char	*str;
	char	*tmp;

	str = NULL;
	while (1)
	{
		buff = get_next_line(fd);
		tmp = str;
		str = ft_strjoin(tmp, buff);
		if (!buff)
		{
			free(tmp);
			break ;
		}
		free(buff);
	}
	return (str);
}

int	handle_close(t_data *data)
{
	mlx_destroy_window(data->mlx, data->win);
	exit(0);
	return (0);
}

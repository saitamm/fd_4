/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fun_initial_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sait-amm <sait-amm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 08:44:13 by sait-amm          #+#    #+#             */
/*   Updated: 2024/06/05 11:55:28 by sait-amm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include_file/fdf.h"

void	whithout_color(int i, int j, t_point *tab, char *str)
{
	tab->y = i;
	tab->x = j;
	tab->blue = 255;
	tab->green = 255;
	tab->red = 255;
	tab->z = ft_atoi(str);
}

char	*add_char(char *str)
{
	char	*src;
	int		i;

	i = 0;
	src = malloc((ft_strlen(str) + 2) * sizeof(char));
	if (!src)
		return (NULL);
	src[i] = '0';
	while (str[i])
	{
		src[i + 1] = str[i];
		i++;
	}
	src[i + 1] = '\0';
	return (src);
}

void	whith_color(int i, int j, t_point *tab, char *str)
{
	tab->y = i;
	tab->x = j;
	tab->z = ft_atoi(str);
	while (str && str[0] != 'x')
		str++;
	str++;
	while (ft_strlen(str) < 6)
		str = add_char(str);
	tab->red = ft_atoi_base(str, 16, 0);
	str = str + 2;
	tab->green = ft_atoi_base(str, 16, 0);
	str = str + 2;
	tab->blue = ft_atoi_base(str, 16, 0);
}

void	ft_init_map(int fd, t_map *map)
{
	map->buff = ft_read_map(fd);
	map->line = num_line(map->buff);
	map->colone = num_colone(map->buff);
	map->point_num = map->line * map->colone;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fun_initial_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sait-amm <sait-amm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 08:44:13 by sait-amm          #+#    #+#             */
/*   Updated: 2024/06/12 13:07:36 by sait-amm         ###   ########.fr       */
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
	size_t		i;
	int j;

	i = 0;
	j = 0;
	size_t k = ft_strlen(str);
	// printf("%zu\n", k);

	src = malloc(7 * sizeof(char));
	if (!src)
		return (NULL);
	while (i < 6 - k)
	{
		src[i] = '0';
		i++;
	}
	while (str[j])
	{
		src[i + j] = str[j];
		j++;
	}
	src[i + j] = '\0';
	return (src);
}

void	whith_color(int i, int j, t_point *tab, char *str)
{
	size_t k;
	char *tmp;

	tab->y = i;
	tmp = NULL;
	tab->x = j;
	tab->z = ft_atoi(str);
	while (str && str[0] != 'x')
		str++;
	str++;
	k = ft_strlen(str);
	if (k < 6)
	{
		tmp = add_char(str);
		tab->red = ft_atoi_base(tmp, 16, 0);
		tab->green = ft_atoi_base(tmp + 2, 16, 0);
		tab->blue = ft_atoi_base(tmp + 4, 16, 0);
		free(tmp);
	}
	else
	{
		tab->red = ft_atoi_base(str, 16, 0);
		str = str + 2;
		tab->green = ft_atoi_base(str, 16, 0);
		str = str + 2;
		tab->blue = ft_atoi_base(str, 16, 0);
	}
}

void	ft_init_map(int fd, t_map *map)
{
	map->buff = ft_read_map(fd);
	if (map->buff == NULL)
	{
		write(1, "no data found\n", 15);
		exit(1);
	}
	map->line = num_line(map->buff);
	map->colone = num_colone(map->buff);
	map->point_num = map->line * map->colone;
}

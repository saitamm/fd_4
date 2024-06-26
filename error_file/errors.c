/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sait-amm <sait-amm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 09:43:19 by sait-amm          #+#    #+#             */
/*   Updated: 2024/06/25 19:13:16 by sait-amm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include_file/fdf.h"

int	check_file(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '.' && str[i + 1] == 'f' && str[i + 2] == 'd'
		&& str[i + 3] == 'f')
		return (1);
	while (str[i])
		i++;
	i--;
	if (str[i] == 'f')
	{
		i--;
		if (str[i] == 'd')
		{
			i--;
			if (str[i] == 'f')
			{
				i--;
				if (str[i] == '.')
					return (0);
			}
		}
	}
	return (1);
}

size_t	ft_strlen_line(char *str)
{
	int		i;
	size_t	len;

	i = 0;
	len = 0;
	while (str[i])
	{
		if (str[i] == ' ')
			len++;
		i++;
	}
	return (len);
}

int	not_same_colone(t_map map)
{
	int		i;
	char	**str;
	char	**str_2;
	int		l;

	i = 0;
	str = ft_split(map.buff, '\n');
	str_2 = ft_split(str[0], ' ');
	l = ft_str_len(str_2);
	ft_free_double(str_2, ft_str_len(str_2));
	while (str[i])
	{
		str_2 = ft_split(str[i], ' ');
		if (ft_str_len(str_2) != l)
		{
			ft_free_double(str, ft_str_len(str));
			ft_free_double(str_2, ft_str_len(str_2));
			return (0);
		}
		ft_free_double(str_2, ft_str_len(str_2));
		i++;
	}
	ft_free_double(str, ft_str_len(str));
	return (1);
}

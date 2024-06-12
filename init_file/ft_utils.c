/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sait-amm <sait-amm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 09:45:33 by sait-amm          #+#    #+#             */
/*   Updated: 2024/06/12 13:05:49 by sait-amm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include_file/fdf.h"

int	num_line(char *buff)
{
	int	i;
	int	len;
	int	in_number;

	i = 0;
	len = 0;
	in_number = 0;
	if (!buff)
		return (0);
	while (buff[i] != '\0')
	{
		if (buff[i] != '\n')
		{
			if (!in_number)
			{
				len++;
				in_number = 1;
			}
		}
		else
		{
			in_number = 0;
		}
		i++;
	}
	return (len);
}

int	num_colone(char *buff)
{
	int	i;
	int	len;
	int	in_number;

	i = 0;
	len = 0;
	in_number = 0;
	if (!buff)
		return (0);
	while (buff[i] != '\n' && buff[i] != '\0')
	{
		if (buff[i] != ' ')
		{
			if (!in_number)
			{
				len++;
				in_number = 1;
			}
		}
		else
		{
			in_number = 0;
		}
		i++;
	}
	return (len);
}

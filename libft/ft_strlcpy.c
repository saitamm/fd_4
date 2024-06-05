/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sait-amm <sait-amm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 18:27:51 by sait-amm          #+#    #+#             */
/*   Updated: 2024/06/05 08:32:00 by sait-amm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include_file/libft.h"

size_t	ft_strlcpy(char *str, const char *src, size_t size)
{
	size_t	j;
	size_t	i;

	j = 0;
	i = 0;
	while (src[j] != '\0')
		j++;
	if (size == 0)
		return (j);
	while (src[i] != '\0' && i < (size - 1))
	{
		str[i] = src[i];
		i++;
	}
	str[i] = '\0';
	return (j);
}

char	*ft_strcpy(char *str)
{
	size_t	j;
	char	*src;

	j = 0;
	while (str[j] && str[j] != '\n')
		j++;
	src = (char *)malloc(sizeof(char) * (j + 1));
	if (!src)
		return (NULL);
	j = 0;
	while (str[j] != '\0' && str[j] != '\n')
	{
		src[j] = str[j];
		j++;
	}
	src[j] = '\0';
	return (src);
}

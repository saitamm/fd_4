/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sait-amm <sait-amm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 14:04:39 by sait-amm          #+#    #+#             */
/*   Updated: 2024/06/05 08:32:00 by sait-amm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include_file/libft.h"

size_t	ft_strlcat(char *str, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	len1;
	size_t	len2;

	i = 0;
	j = 0;
	if (!str && !size)
		return (ft_strlen(src));
	len1 = ft_strlen(str);
	len2 = ft_strlen(src);
	if (size == 0 || size <= len1)
		return (len2 + size);
	while (src[i] && i < size - len1 - 1)
	{
		str[len1 + i] = src[i];
		i++;
	}
	str[i + len1] = '\0';
	return (len1 + len2);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sait-amm <sait-amm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 11:01:06 by sait-amm          #+#    #+#             */
/*   Updated: 2024/06/05 08:32:00 by sait-amm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include_file/libft.h"

char	*ft_strdup(const char *s1)
{
	char	*d;
	int		len;
	int		i;

	len = 0;
	i = 0;
	while (s1[len])
		len++;
	d = (char *)s1;
	d = malloc((len + 1) * sizeof(char));
	if (!d)
		return (NULL);
	while (s1[i])
	{
		d[i] = s1[i];
		i++;
	}
	d[i] = '\0';
	return (d);
}

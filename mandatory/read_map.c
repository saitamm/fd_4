/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sait-amm <sait-amm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 12:26:57 by sait-amm          #+#    #+#             */
/*   Updated: 2024/05/20 10:03:06 by sait-amm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include_file/header.h"

char *ft_read_map(int fd)
{
    char    *buff;
    char    *str;

    str = NULL;
    while (1)
    {
        buff = get_next_line(fd);
        str = ft_strjoin(str, buff);
        if(!buff)
            break;
        free(buff);
    }
    return (str);
}
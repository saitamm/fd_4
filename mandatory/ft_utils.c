/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sait-amm <sait-amm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 09:45:33 by sait-amm          #+#    #+#             */
/*   Updated: 2024/05/21 09:50:44 by sait-amm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include_file/header.h"

int num_line(char *buff)
{
    int len;
    int i;

    len = 0;
    i = 0;
    while(buff[i])
    {
        if (buff[i] == '\n')
            len++;
        i++;
    }
    return (len);
}

int num_colone(char *buff)
{
    int i = 0;
    int len = 0;
    int in_number = 0; 

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
    return len;
}

int ft_len_line(char *buff)
{
    int i;

    i = 0;
    while (buff[i] && buff[i] != '\n')
        i++;
    return (i);
}
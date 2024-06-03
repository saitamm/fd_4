/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sait-amm <sait-amm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 11:13:29 by sait-amm          #+#    #+#             */
/*   Updated: 2024/06/03 20:28:36 by sait-amm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include_file/header.h"

int main(int ac, char **av)
{
    int fd;
    t_data *data;

    if (ac != 2)
    {
        printf("soumaya\n");
        exit(1);
    }
    fd = open(av[1], O_RDONLY , 0644);
    if (fd < 0)
        exit(1);
    data = initial_data(fd);
    data->tab = rotation_z(data->tab, data->map, 45);
    data->tab = rotation_x(data->tab, data->map, 45);
    draw_image(data);
    int i;
    int j;
    i = 0;
    while (i < data->map.line)
    {
        j = 0;
        while (j <data->map.colone)
        {
            data->tab[i][j].x_ind += 500;
            data->tab[i][j].y_ind += 500;
            j++;
        }
        i++;
    }
    draw_line(data->tab, data->map, data);
    mlx_put_image_to_window(data->mlx, data->win, data->img,0, 0);
    // mlx_key_hook(data->win,(int (*)(int, void *))handle_key, data);
    mlx_hook(data->win,2, (1L<<0), (int (*)(int, void *))handle_key, data);
    mlx_hook(data->win, DESTROY_NOTIFY, 0, handle_close, data);
    mlx_loop(data->mlx);
    close(fd);
    ft_free_data(data);
}

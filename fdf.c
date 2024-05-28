/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sait-amm <sait-amm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 11:13:29 by sait-amm          #+#    #+#             */
/*   Updated: 2024/05/28 13:36:05 by sait-amm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include_file/header.h"

int main(int ac, char **av)
{
    t_point **tab;
    int fd;
    t_map map;
    t_mlx   mlx;
    t_data data;

    if (ac != 2)
    {
        printf("soumaya\n");
        exit(1);
    }
    fd = open(av[1], O_RDONLY , 0644);
    if (fd < 0)
        exit(1);
    ft_init_map(fd, &map);
    ft_init_mlx(map, &mlx);
    tab = ft_index_window(ft_to_array(map), mlx, map);       
    data.mlx = mlx_init();
    data.img = mlx_new_image(data.mlx, 800, 900);
    data.img_data = mlx_get_data_addr(data.img, &data.bpp, &data.size_line, &data.endian);
    data.win = mlx_new_window(data.mlx, L_WIN  , LE_WIN, "fdf");
    tab = rotation_z(tab, map, -45);
    tab = rotation_x(tab, map, 30);
    // tab = zoom_int(&data, tab, map);
    draw_line(tab, map, &data);
    mlx_put_image_to_window(data.mlx, data.win, data.img,800, 100);
    mlx_loop(data.mlx);
}

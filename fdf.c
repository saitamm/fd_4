/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sait-amm <sait-amm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 11:13:29 by sait-amm          #+#    #+#             */
/*   Updated: 2024/05/21 20:55:49 by sait-amm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include_file/header.h"

int main(int ac, char **av)
{
    int fd;
    t_map *map;
    t_point **tab;
    t_mlx   *mlx;
    void *mlx_ptr;
    void *win_ptr;

    if (ac != 2)
    {
        printf("soumaya\n");
        exit(1);
    }
    fd = open(av[1], O_RDONLY , 0644);
    if (fd < 0)
        exit(1);
    map = malloc(sizeof(t_map));
    if (!map)
        return(0);
    ft_init_map(fd, map);
    mlx = malloc(sizeof(t_mlx));
    if (!mlx)
        return (0);
    ft_init_mlx(map, mlx);
    // tab = ft_index_window(ft_to_array(map), mlx, map);
    tab = initial_z(ft_index_window(ft_to_array(map), mlx, map), map);
    // double   angle = 30;
    mlx_ptr = mlx_init();
    win_ptr = mlx_new_window(mlx_ptr, L_WIN  , LE_WIN, "Point Example");
    // while (angle < 90)
    // {
    tab = rotation_z(tab, map, 45);
        tab = rotation_x(tab, map, 45);
        draw_line(tab, map, mlx_ptr, win_ptr);
    //     printf("************\n");
    //     angle = angle + 10;

    // }
    // printf("%d\n", map->colone);
    // printf(">>>>>%d\n", tab[0][0].x_ind);
    mlx_loop(mlx_ptr);
}

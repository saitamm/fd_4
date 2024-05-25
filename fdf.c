/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sait-amm <sait-amm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 11:13:29 by sait-amm          #+#    #+#             */
/*   Updated: 2024/05/25 20:12:44 by sait-amm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include_file/header.h"

int main(int ac, char **av)
{
    int fd;
    t_map *map;
    t_point **tab;
    t_mlx   *mlx;
    t_data data;

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
    tab = ft_index_window(ft_to_array(map), mlx, map);
    int i = 0;
    while (i < map->line)
    {
        int j = 0;
        while (j < map->colone)
        {
            printf("^^%d\n", tab[i][j].red);
            printf("^^%d\n", tab[i][j].green);
            printf("^^%d\n", tab[i][j].blue);
            j++;
        }
        i++;
    }
    data.mlx = mlx_init();
    data.win = mlx_new_window(data.mlx, L_WIN  , LE_WIN, "fdf");
    tab = rotation_z(tab, map, 60);
    tab = rotation_x(tab, map, 45);
    draw_line(tab, map, data.mlx, data.win, mlx);
    mlx_loop(data.mlx);
}

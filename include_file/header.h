/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sait-amm <sait-amm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 11:14:00 by sait-amm          #+#    #+#             */
/*   Updated: 2024/05/27 11:45:15 by sait-amm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H
#define INT_START_X 0
#define INT_START_Y 0
#define LE_WIN 1080
#define L_WIN 1920
#define STEP_WIN 50 
#define PI 3.14159265359
# include "../libft/libft.h"
# include <errno.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <unistd.h>
#include "../minilibx-linux/mlx.h"
#include "../get_next_line/get_next_line.h"
#include <math.h>

typedef struct s_point
{
    int x;
    int y;
    int z;
    int x_ind;
    int y_ind;
    int red;
    int green;
    int blue;
}t_point;

typedef struct s_mlx
{
    int x_index;
    int y_index;
    int x_max;
    int y_max;
    int step;
}t_mlx;

typedef struct s_map
{
    char *buff;
    int line;
    int colone;
    int point_num;
}t_map;

typedef struct s_bres
{
    int dx;
    int dy;
    float slope;
}t_bres;

typedef struct {
    void *mlx;
    void *win;
    void *img;
} t_data;

typedef struct s_col
{
    float step_r;
    float step_g;
    float step_b;
}t_col;
// inittial function

void    ft_init_map(int fd, t_map *map);
void   ft_init_mlx(t_map map, t_mlx *mlx);
int num_line( char *buff);
int num_colone( char *buff);
t_point **ft_index_window(t_point **tab, t_mlx mlx, t_map map);
t_bres  *ft_initial(t_point x, t_point y);
int initial_p_k(t_point x, t_point y);
void bresenham( t_point x, t_point y, void *mlx_ptr, void *mlx_win);
void draw_line(t_point **tab, t_map map,t_data data);

// map function
// void draw_point(t_point **tab, t_map map,void *win_ptr, void *window);
t_point **ft_to_array(t_map map);
t_point  *sub_array(int i, int colone, char *buff);
char *ft_read_map(int fd);
int ft_len_line(char *buff);
void    whithout_color(int i, int j, t_point *tab, char *str);
void    whith_color(int i, int j, t_point *tab, char *str);

//rotation function

t_point **rotation_x(t_point **tab, t_map map, double angle);
t_point **rotation_y(t_point **tab, t_map map, double angle);
t_point **rotation_z(t_point **tab, t_map map, double angle);


//color function
int crem_color(t_point *x, t_point y, int nbr_pixel);
// void crem_blue(t_point *, t_point y, int step_col);
// void crem_green(t_point *x, t_point y, int step_col);
// void crem_red(t_point *x, t_point y, int step_col);
// int step_color(t_point x, t_point y, int nbr_pixel);

#endif
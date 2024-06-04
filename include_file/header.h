/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sait-amm <sait-amm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 11:14:00 by sait-amm          #+#    #+#             */
/*   Updated: 2024/06/04 19:15:38 by sait-amm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H
# define INT_START_X 0
# define INT_START_Y 0
# define LE_WIN 1920
# define L_WIN 1180
# define STEP_WIN 50
# define PI 3.14159265359
# define ZOOM_FAC 20
# define ESC_KEY 65307
# define DESTROY_NOTIFY 17
# define KEY_ESC 53
# define ROT_X 120
# define ROT_Y 121
# define KEY_W 65362
# define KEY_D 65364
# define KEY_R 65361
# define KEY_L 65363
# define ZOOM_IN 65451
# define ZOOM_OUT 65453
# define KEY_P 112
# define KEY_I 105
# include "../get_next_line/get_next_line.h"
# include "../libft/libft.h"
# include "../minilibx-linux/mlx.h"
# include <errno.h>
# include <fcntl.h>
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <unistd.h>

typedef struct s_point
{
	int		x;
	int		y;
	int		z;
	int		x_ind;
	int		y_ind;
	int		red;
	int		green;
	int		blue;
}			t_point;

typedef struct s_mlx
{
	int		x_index;
	int		y_index;
	int		x_max;
	int		y_max;
	int		step;
}			t_mlx;

typedef struct s_map
{
	char	*buff;
	int		line;
	int		colone;
	int		point_num;
}			t_map;

typedef struct s_rot
{
	double	angle_x;
	double	angle_y;
	double	angle_z;
}			t_rot;

typedef struct s_data
{
	void	*mlx;
	void	*win;
	void	*img;
	char	*img_data;
	t_point	**tab;
	t_map	map;
	t_mlx	stp;
	int		bpp;
	int		size_line;
	int		endian;
	t_rot	angle;
}			t_data;

typedef struct s_bres_flag
{
	int		dx;
	int		dy;
	int		sx;
	int		sy;
	int		err;
}			t_bres_flag;

// initial function

void		ft_init_map(int fd, t_map *map);
void		ft_init_mlx(t_map map, t_mlx *mlx);
int			num_line(char *buff);
int			num_colone(char *buff);
t_point		**ft_index_window(t_point **tab, t_mlx mlx, t_map map);
t_data		*initial_data(int fd);

// map function

t_point		**ft_to_array(t_map map);
t_point		*sub_array(int i, int colone, char *buff);
char		*ft_read_map(int fd);

// rotation function

t_point		**rotation_x(t_point **tab, t_map map, double angle);
t_point		**rotation_y(t_point **tab, t_map map, double angle);
t_point		**rotation_z(t_point **tab, t_map map, double angle);

// color function

int			crem_color(t_point *x, t_point y, int nbr_pixel);
float		step_r(int x_red, int y_red, int nbr_pixel);
float		step_g(int x_green, int y_green, int nbr_pixel);
float		step_b(int x_blue, int y_blue, int nbr_pixel);
void		crem_red(int *x_red, int y_red, int nbr_pixel);
void		crem_green(int *x_green, int y_green, int nbr_pixel);
void		crem_blue(int *x_blue, int y_blue, int nbr_pixel);
void		whithout_color(int i, int j, t_point *tab, char *str);
void		whith_color(int i, int j, t_point *tab, char *str);

// draw function

void		draw_image(t_data *data);
void		my_mlx_pixel_put(t_data *data, int x, int y, int color);
void		bresenham(t_point x, t_point y, t_data *data);
void		draw_line(t_point **tab, t_map map, t_data *data);

// help function
int			max(int a, int b);
t_point		middle(t_point **tab, t_map map);

// function to free

int			ft_str_len(char **str);
void		ft_free_double(char **str, int i);
void		free_map(t_map map);

// key function

int			handle_key(int keycode, t_data *data);
int			handle_close(t_data *data);

// image function
void		draw_image_in(t_data *data);
void		draw_image_out(t_data *data);

// rotation

void		update_data(t_data **data);
void		rot_x(t_data *data);
void		update_data_rot(t_data **data);
void		rot_y(t_data *data);
void		rot_z(t_data *data);

// translation
void		trans_left(t_data *data);
void		update_data_right(t_data **data);
void		update_data_left(t_data **data);
void		trans_right(t_data *data);
void		trans_up(t_data *data);
void		trans_down(t_data *data);
void		update_data_down(t_data **data);
void		update_data_up(t_data **data);
void		press_p(t_data *data);
void		update_data_p(t_data **data);
void		press_i(t_data *data);
void		update_data_i(t_data **data);

// free and error function
void		ft_free_data(t_data *data);
void		free_tab(t_point **tab, t_map map);
// int not_same_colone(char *str);
// void free_map(t_map *map);
int	min_z(t_point **tab, t_map map);
int	max_z(t_point **tab, t_map map);
void center_point(t_data **data);
#endif

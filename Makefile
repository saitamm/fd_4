# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sait-amm <sait-amm@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/01 11:15:01 by sait-amm          #+#    #+#              #
#    Updated: 2024/06/10 10:20:47 by sait-amm         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC =	fdf.c \
		libft/ft_split.c \
		libft/ft_strlen.c \
		libft/ft_strdup.c \
		libft/ft_strjoin.c \
		libft/ft_strlcpy.c \
		libft/ft_strchr.c \
		libft/ft_atoi.c \
		libft/ft_atoi_base.c \
		get_next_line/get_next_line_utils.c \
		get_next_line/get_next_line.c \
		color_file/crem_color.c \
		color_file/step_color.c \
		draw_file/bresenham.c \
		draw_file/draw_image.c \
		draw_file/draw_pixel.c \
		init_file/ft_utils.c \
		init_file/fun_initial_2.c \
		init_file/fun_initial.c \
		map_file/ft_to_array.c \
		map_file/read_map.c \
		move_file/rotation.c \
		error_file/errors.c \
		error_file/free_fun.c \
		error_file/fun_free.c \
		map_file/handle_close.c \
		move_file/help_fun.c

SRCB =	fdf_bonus.c \
		libft/ft_split.c \
		libft/ft_strlen.c \
		libft/ft_strdup.c \
		libft/ft_strjoin.c \
		libft/ft_strlcpy.c \
		libft/ft_strchr.c \
		libft/ft_atoi.c \
		libft/ft_atoi_base.c \
		get_next_line/get_next_line_utils.c \
		get_next_line/get_next_line.c \
		color_file/crem_color.c \
		color_file/step_color.c \
		draw_file/bresenham.c \
		draw_file/draw_image.c \
		draw_file/draw_pixel.c \
		init_file/ft_utils.c \
		init_file/fun_initial_2.c \
		init_file/fun_initial.c \
		map_file/ft_to_array.c \
		map_file/read_map.c \
		move_file/rot_xyz.c \
		move_file/rotation.c \
		move_file/translation.c \
		move_file/updat_data.c \
		move_file/update_data_2.c \
		move_file/zoom.c \
		error_file/errors.c \
		error_file/free_fun.c \
		error_file/fun_free.c \
		move_file/ft_utils.c \
		move_file/help_fun.c \
		map_file/handle_close.c \
		move_file/rotation_bonus.c


OBJF = $(SRC:.c=.o)
OBJFB = $(SRCB:.c=.o)

NAME = fdf


BONUS = fdf_bonus


C = cc

CFLAGS = -Wall -Werror -Wextra  -fsanitize=address -g3

all: $(NAME)


$(NAME): $(OBJF)
		$(C) $(CFLAGS) $(OBJF) -o $(NAME) -L/minilibx-linux -lmlx -lX11 -lXext -lm

$(BONUS): $(OBJFB)
		$(C) $(CFLAGS) $(OBJFB) -o $(BONUS) -L/minilibx-linux -lmlx -lX11 -lXext -lm

bonus : $(BONUS)

clean:
	rm -rf $(OBJF) $(OBJFB)

fclean: clean
	rm -rf $(NAME) $(BONUS)

re: fclean all

.PHONY: all clean fclean re bonus
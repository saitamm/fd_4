# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sait-amm <sait-amm@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/01 11:15:01 by sait-amm          #+#    #+#              #
#    Updated: 2024/05/21 16:44:36 by sait-amm         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC =	fdf.c \
		mandatory/ft_utils.c \
		mandatory/ft_to_array.c \
		mandatory/fun_initial.c \
		mandatory/draw_pixel.c \
		mandatory/add_height.c \
		get_next_line/get_next_line_utils.c \
		get_next_line/get_next_line.c \
		libft/ft_split.c \
		libft/ft_strlen.c \
		libft/ft_strdup.c \
		libft/ft_strjoin.c \
		libft/ft_strlcpy.c \
		mandatory/read_map.c \
		libft/ft_strchr.c \
		libft/ft_atoi.c \
		libft/ft_atoi_base.c \
		mandatory/bresenham.c \
		mandatory/rotation.c
	

OBJF = $(SRC:.c=.o)

NAME = fdf


C = cc

CFLAGS = -Wall -Werror -Wextra  #-fsanitize=address -g3

all: $(NAME)


$(NAME): $(OBJF)
		$(C) $(CFLAGS) $(OBJF) -o $(NAME) -L/minilibx-linux -lmlx -lX11 -lXext -lm

clean:
	rm -rf $(OBJF)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
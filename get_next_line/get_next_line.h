/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sait-amm <sait-amm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/25 10:17:23 by sait-amm          #+#    #+#             */
/*   Updated: 2024/05/09 10:04:04 by sait-amm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
#include "../libft/libft.h"
# ifndef BUFFER_SIZE

#  define BUFFER_SIZE 42

# endif

char	*get_next_line(int fd);
char	*ft_afterline(char *str);
char	*ft_getline(char *str);
char	*ft_read(int fd, char *line);
// size_t	ft_strlen(char *str);
char	*ft_free(char *str, char *line);
// char	*ft_strdup(char *s);
char	*ft_cpy(char *s1, char *s2);
// char	*ft_strjoin(char *s1, char *s2);
int		ft_strchar(char *str);

#endif

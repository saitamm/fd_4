/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sait-amm <sait-amm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 20:11:04 by sait-amm          #+#    #+#             */
/*   Updated: 2024/05/29 15:06:49 by sait-amm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <limits.h>
# include <stdlib.h>
#include <stdio.h>

int			ft_atoi(const char	*c);
char		**ft_split(const char *s, char c);
int         ft_strchr(const char *s, int c);
char		*ft_strdup(const char *s1);
char		*ft_strjoin(char const *s1, char const *s2);
size_t		ft_strlen(const char	*str);
size_t		ft_strlcpy(char	*str, const char	*src, size_t size);
char	*ft_strcpy(char *str);
int ft_atoi_base(const char *str, int str_base, int flag);

#endif

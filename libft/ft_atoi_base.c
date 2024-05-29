/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sait-amm <sait-amm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 09:11:17 by sait-amm          #+#    #+#             */
/*   Updated: 2024/05/29 15:12:22 by sait-amm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	to_lower(char c)
{
	if (c >= 'A' && c <= 'Z')
		return (c + ('a' - 'A'));
	return (c);
}

int get_digit(char c, int digits_in_base)
{
	int max_digit;
	if (digits_in_base <= 10)
		max_digit = digits_in_base + '0';
	else
		max_digit = digits_in_base - 10 + 'a';
	if (c >= '0' && c <= '9' && c <= max_digit)
		return (c - '0');
	else if (c >= 'a' && c <= 'f' && c <= max_digit)
		return (10 + c - 'a');
	else
		return (-1);
}

int ft_atoi_base(const char *str, int str_base, int flag)
{
	int result = 0;
	int sign = 1;
	int digit;
    int i;

	if (*str == '-')
	{
		sign = -1;
		++str;
	}
    i = 0;
	if (flag == 0)
	{
		while ((digit = get_digit(to_lower(*str), str_base)) >= 0  && i < 2)
		{
			result = result * str_base;
			result = result + (digit * sign);
			++str;
			i++;
		}
	}
	else
	{
		while ((digit = get_digit(to_lower(*str), str_base)) >= 0)
		{
			result = result * str_base;
			result = result + (digit * sign);
			++str;
			i++;
		}
	}
	return (result);
}
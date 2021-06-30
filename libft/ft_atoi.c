/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felisabe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 13:00:43 by felisabe          #+#    #+#             */
/*   Updated: 2021/04/29 01:50:42 by felisabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int			dig;
	int			sign;
	long int	num;

	num = 0;
	sign = 1;
	dig = 0;
	while (*str && (*str == '\f' || *str == '\t' || *str == ' ' || \
				*str == '\n' || *str == '\r' || *str == '\v'))
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (*str && ft_isdigit(*str))
	{
		num = num * 10 + (*str - '0');
		dig++;
		if (dig > 10 || (num * sign) > MAXINT || (num * sign) < MININT)
			ft_error();
		str++;
	}
	return ((int)(num * sign));
}

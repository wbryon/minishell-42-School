/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felisabe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/06 07:03:23 by felisabe          #+#    #+#             */
/*   Updated: 2021/04/16 14:13:48 by felisabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_len(int nbr)
{
	size_t	len;

	len = 0;
	if (nbr == 0)
		len++;
	if (nbr < 0)
	{
		nbr *= -1;
		len++;
	}
	while (nbr > 0)
	{
		nbr /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char	*buff;
	size_t	i;

	if (n == -2147483648)
		return (buff = ft_strdup("-2147483648"));
	i = ft_len(n);
	buff = ft_calloc(sizeof(char), i + 1);
	if (!buff)
		return (NULL);
	if (n == 0)
		buff[0] = '0';
	if (n < 0)
	{
		buff[0] = '-';
		n *= -1;
	}
	while (n > 0)
	{
		buff[--i] = (n % 10) + '0';
		n /= 10;
	}
	return (buff);
}

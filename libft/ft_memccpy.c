/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felisabe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 07:33:11 by felisabe          #+#    #+#             */
/*   Updated: 2021/04/16 14:19:59 by felisabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t			i;
	unsigned char	*p_dst;
	unsigned char	*p_src;

	i = 0;
	p_dst = (unsigned char *)dst;
	p_src = (unsigned char *)src;
	while (n--)
	{
		p_dst[i] = p_src[i];
		if (p_dst[i] == (unsigned char)c)
			return (dst + i + 1);
		i++;
	}
	return (0);
}

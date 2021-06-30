/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felisabe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 07:34:53 by felisabe          #+#    #+#             */
/*   Updated: 2021/04/16 14:22:39 by felisabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*p_dst;
	unsigned char	*p_src;

	p_dst = (unsigned char *)dst;
	p_src = (unsigned char *)src;
	if (!dst && !src)
		return (NULL);
	if (p_src > p_dst)
		dst = ft_memcpy(dst, src, len);
	else
	{
		while (len--)
			p_dst[len] = p_src[len];
	}
	return (dst);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felisabe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 19:12:04 by felisabe          #+#    #+#             */
/*   Updated: 2021/04/16 14:29:20 by felisabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	size_t	i;

	i = 0;
	while (*s)
	{
		if (*s == (char)c)
			return ((void *)s);
		s++;
	}
	if (*s == (char)c)
		return ((void *)s);
	return (NULL);
}

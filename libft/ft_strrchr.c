/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felisabe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 19:37:32 by felisabe          #+#    #+#             */
/*   Updated: 2021/04/16 14:35:04 by felisabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*str;

	str = (0);
	while (*s)
	{
		if (*s == (char)c)
			str = (char *)s;
		s++;
	}
	if (str)
		return (str);
	if ((char)c == '\0')
		return ((char *)s);
	return (0);
}

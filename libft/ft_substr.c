/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felisabe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 16:12:39 by felisabe          #+#    #+#             */
/*   Updated: 2021/04/16 14:36:09 by felisabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;

	if (!s)
		return (NULL);
	substr = ft_calloc(sizeof(char), len + 1);
	if (substr)
	{
		if (start >= ft_strlen(s))
			return (substr);
		ft_memcpy(substr, ((char *)s + start), len);
		return (substr);
	}
	return (NULL);
}

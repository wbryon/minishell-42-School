/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felisabe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/06 08:51:13 by felisabe          #+#    #+#             */
/*   Updated: 2021/04/16 14:35:40 by felisabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*buff;
	size_t	i;
	size_t	len;

	i = 0;
	if (!s1)
		return (NULL);
	if (*s1 == '\0')
		return ("");
	while (*s1 && ft_strchr(set, *s1))
		s1++;
	len = ft_strlen(s1);
	while (len && ft_strchr(set, s1[len]))
		len--;
	buff = ft_substr((char *)s1, 0, len + 1);
	return (buff);
}

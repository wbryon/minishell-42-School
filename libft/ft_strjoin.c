/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felisabe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 19:24:58 by felisabe          #+#    #+#             */
/*   Updated: 2020/11/12 08:28:32 by felisabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*buff;
	size_t	s1_len;
	size_t	s2_len;

	if (!s1 || !s2)
		return (NULL);
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	buff = ft_calloc(sizeof(char), s1_len + s2_len + 1);
	if (buff != NULL)
	{
		ft_strlcpy(buff, s1, s1_len + 1);
		ft_strlcat(buff, s2, s1_len + s2_len + 1);
		return (buff);
	}
	return (NULL);
}

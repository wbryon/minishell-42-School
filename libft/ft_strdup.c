/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felisabe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 07:58:00 by felisabe          #+#    #+#             */
/*   Updated: 2020/11/12 08:19:21 by felisabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	size_t	i;
	char	*str;

	i = 0;
	str = ft_calloc(sizeof(char), ft_strlen(s1) + 1);
	if (str != NULL)
	{
		while (s1[i])
		{
			str[i] = s1[i];
			i++;
		}
	}
	return (str);
}

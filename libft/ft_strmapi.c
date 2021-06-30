/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felisabe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/06 07:04:18 by felisabe          #+#    #+#             */
/*   Updated: 2020/11/12 08:39:54 by felisabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*buff;
	size_t	i;

	i = 0;
	if (!s || !f)
		return (NULL);
	buff = ft_calloc(sizeof(char), ft_strlen(s) + 1);
	if (buff != NULL)
	{
		while (s[i])
		{
			buff[i] = f(i, s[i]);
			i++;
		}
		return (buff);
	}
	return (0);
}

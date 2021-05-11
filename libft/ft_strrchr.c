#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	int i;

	i = ft_strlen(str);
	str = str + i;
	while (i >= 0)
	{
		if (*str == c)
			return ((char *)str);
		i--;
		str--;
	}
	return (0);
}

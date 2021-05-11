#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char *strjoin;

	if (!s1 || !s2)
		return (0);
	if (!(strjoin = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1))))
		return (0);
	ft_strlcpy(strjoin, s1, ft_strlen(s1) + 1);
	ft_strlcat(strjoin, s2, (ft_strlen(s1) + ft_strlen(s2) + 1));
	return (strjoin);
}

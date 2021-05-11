#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*strtrim;
	size_t	begin;

	begin = 0;
	if (s1 == 0 || set == 0)
		return (0);
	while (*s1 != '\0' && ft_strchr(set, *s1))
		s1++;
	begin = ft_strlen(s1);
	while (begin != 0 && ft_strrchr(set, s1[begin]))
		begin--;
	strtrim = ft_substr((char*)s1, 0, begin + 1);
	return (strtrim);
}

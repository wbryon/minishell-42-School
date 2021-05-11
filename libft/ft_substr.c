#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char *dest;

	if (!s)
		return (0);
	if (!(dest = malloc(sizeof(char) * (len + 1))))
		return (NULL);
	ft_memset(dest, 0, len + 1);
	if (start > ft_strlen(s))
		return (dest);
	else
		ft_memmove(dest, (char *)s + start, len);
	return (dest);
}

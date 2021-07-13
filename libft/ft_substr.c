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

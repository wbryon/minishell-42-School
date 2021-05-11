#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	if (*needle == 0)
		return ((char *)haystack);
	while (*haystack != '\0' && len > 0)
	{
		if (*haystack == *needle)
		{
			if (ft_strlen(needle) <= len)
			{
				if (ft_strncmp(haystack, needle, ft_strlen(needle)) == 0)
					return ((char *)haystack);
			}
		}
		haystack++;
		len--;
	}
	return (0);
}

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t i;
	size_t dst_length;
	size_t dst_count;

	i = 0;
	dst_length = ft_strlen(dst);
	dst_count = dst_length;
	if (dstsize <= dst_length)
		return (ft_strlen(src) + dstsize);
	while (src[i] && i < (dstsize - (dst_length + 1)))
	{
		dst[dst_count] = src[i];
		dst_count++;
		i++;
	}
	dst[dst_count] = '\0';
	return (dst_length + ft_strlen(src));
}

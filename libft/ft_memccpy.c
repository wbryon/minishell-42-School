#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char *ptr_dst;
	unsigned char *ptr_src;

	ptr_dst = (unsigned char *)dst;
	ptr_src = (unsigned char *)src;
	if (ptr_dst == 0 && ptr_src == 0)
		return (0);
	while (n > 0)
	{
		if (*ptr_src != (unsigned char)c)
			*ptr_dst++ = *ptr_src++;
		else
		{
			*ptr_dst++ = *ptr_src++;
			return (ptr_dst);
		}
		n--;
	}
	return (0);
}

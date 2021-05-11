#include "libft.h"

void	*ft_memset(void *dest, int c, size_t len)
{
	char *ptr;

	ptr = (char *)dest;
	while (len > 0)
	{
		ptr[len - 1] = c;
		len--;
	}
	return (dest);
}

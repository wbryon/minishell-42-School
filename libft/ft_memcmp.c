#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	char	*ptr1;
	char	*ptr2;
	size_t	i;

	ptr1 = (char *)s1;
	ptr2 = (char *)s2;
	i = 0;
	if (n == 0)
		return (0);
	while (ptr1[i] == ptr2[i] && i < n - 1)
	{
		++i;
	}
	return ((unsigned char)ptr1[i] - (unsigned char)ptr2[i]);
}

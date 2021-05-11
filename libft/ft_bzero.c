#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	while (n > 0)
	{
		ft_memset(s, 0, n);
		n--;
	}
}

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void *s;

	if (!(s = malloc(size * count)))
		return (0);
	else
		return (ft_memset(s, 0, size * count));
}

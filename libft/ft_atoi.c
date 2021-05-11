#include "libft.h"

int	sign_checker(const char *str)
{
	int sign;

	sign = 1;
	if (*str == '-')
		sign = -sign;
	return (sign);
}

int	ft_atoi(const char *str)
{
	unsigned long long	res;
	int					sign;

	res = 0;
	sign = 1;
	while ((*str >= 9 && *str <= 13) || *str == 32)
		str++;
	if (*str == '-' || *str == '+')
	{
		sign = sign_checker(str);
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		res = (res * 10) + *str - '0';
		str++;
		if (*str < '0' && *str > '9')
			break ;
	}
	if (res >= 9223372036854775807)
		res = (sign == -1) ? 0 : -1;
	return ((int)res * sign);
}

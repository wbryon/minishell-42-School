#include "libft.h"

static int		char_count(int number)
{
	int i;

	i = 0;
	if (number == 0)
	{
		i++;
		return (i);
	}
	else if (number < 0)
	{
		i++;
		number = -number;
	}
	while (number > 0)
	{
		number = number / 10;
		i++;
	}
	return (i);
}

static	void	reverse_str(char *s, int sign, int x)
{
	int		i;
	int		j;
	char	c;

	i = 0;
	if (sign < 0)
	{
		s[x++] = '-';
		s[x] = '\0';
	}
	j = ft_strlen(s) - 1;
	while (i < j)
	{
		c = s[i];
		s[i] = s[j];
		s[j] = c;
		i++;
		j--;
	}
}

char			*ft_itoa(int n)
{
	int		i;
	int		sign;
	char	*str;

	i = 0;
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (!(str = malloc(sizeof(char) * (char_count(n) + 1))))
		return (NULL);
	if (n == 0)
		str[i++] = '0';
	if ((sign = n) < 0)
		n = -n;
	while (n > 0)
	{
		str[i++] = (n % 10) + '0';
		n /= 10;
	}
	str[i] = '\0';
	reverse_str(str, sign, i);
	return (str);
}

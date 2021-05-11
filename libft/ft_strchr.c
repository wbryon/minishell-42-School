char	*ft_strchr(const char *str, int c)
{
	while (*str != '\0')
	{
		if (*str == c)
			return ((char *)str);
		else
			str++;
	}
	if (*str == c)
		return ((char *)str);
	return (0);
}

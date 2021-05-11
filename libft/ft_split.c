#include "libft.h"

static	int		count_words(const char *str, char delimiter)
{
	int count;

	count = 0;
	while (*str)
	{
		if (*str == delimiter)
			str++;
		else if (*str != delimiter && *str)
		{
			while (*str != delimiter && *str)
				str++;
			count++;
		}
	}
	return (count);
}

static	int		ft_len(char const *str, char delimiter, int i)
{
	int length;

	length = 0;
	while (str[i] != delimiter && str[i] != '\0')
	{
		length++;
		i++;
	}
	return (length);
}

static	char	**free_tab(char **tab, int i)
{
	while (i >= 0)
		free(tab[i--]);
	return (NULL);
}

static	char	**mem_alloc(char const *s, char **tab, char delimiter, int len)
{
	int i;
	int j;
	int k;

	i = 0;
	j = 0;
	while (s[i] && j < len)
	{
		k = 0;
		while (s[i] == delimiter)
			i++;
		tab[j] = (char *)malloc(sizeof(char) * (ft_len(s, delimiter, i) + 1));
		if (tab[j] == NULL)
			return (free_tab((char **)tab, j));
		while (s[i] && s[i] != delimiter)
			tab[j][k++] = s[i++];
		tab[j][k] = '\0';
		j++;
	}
	tab[j] = NULL;
	return (tab);
}

char			**ft_split(char const *s, char c)
{
	char	**tab;
	int		i;

	if (s == NULL)
		return (NULL);
	i = count_words(s, c);
	if (!(tab = (char **)malloc(sizeof(char *) * (i + 1))))
		return (NULL);
	return (mem_alloc(s, tab, c, i));
}

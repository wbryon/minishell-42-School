#include "libft.h"

static void		init_l(t_split *l)
{
	l->flag = 0;
	l->j = 0;
}

static char		**free_array(char **array)
{
	int i;

	i = -1;
	while (array[++i])
		free(array[i]);
	free(array);
	return (NULL);
}

static int		isset(char *s, char c)
{
	int i;

	i = -1;
	while (s[++i])
		if (s[i] == c)
			return (1);
	return (0);
}

static char	*malloc_word(char *str, char *set)
{
	char	*word;
	int		i;

	i = 0;
	while (isset(set, str[i]) == 0)
		i++;
	word = (char *)malloc(sizeof(char) * (i + 1));
	if (word == NULL)
		return (NULL);
	i = 0;
	while (str[i] && isset(set, str[i]) == 0)
	{
		word[i] = str[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

static int		count_words(char *str, char *set, t_split *l)
{
	int			i;
	int			counter;

	i = -1;
	counter = 0;
	while (str[++i])
	{
		if (l->flag == 0 && isset(set, str[i]) == 0)
		{
			counter++;
			l->flag = 1;
		}
		if (l->flag == 1 && isset(set, str[i]) == 1)
			l->flag = 0;
	}
	return (counter);
}

static char		**spls(char *str, char *set, t_split *l)
{
	while (*str)
	{
		if (!isset(set, *str))
		{
			l->array[l->j] = malloc_word(str, set);
			if (!l->array[l->j])
				return (free_array(l->array));
			while (*str && isset(set, *str) == 0)
				str++;
			l->j++;
		}
		if (*str == '\0')
			break;
		str++;
	}
	l->array[l->j] = NULL;
	return (l->array);
}

char	**ft_splitset(const char *str, const char *set)
{
	t_split l;

	init_l(&l);
	if (!(l.array = (char **)malloc(sizeof(char *) *
		(count_words((char *)str, (char *)set, &l) + 1))))
		return (NULL);
	return (spls((char *)str, (char *)set, &l));
}

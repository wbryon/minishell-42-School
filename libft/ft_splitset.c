#include "libft.h"

static void		init_l(t_split *l)
{
	l->f = 0;
	l->j = 0;
}

static char		**free_tab(char **tab)
{
	int i;

	i = -1;
	while (tab[++i])
		free(tab[i]);
	free(tab);
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

static char		*malloc_word(char *mem, char *set)
{
	char		*word;
	int			i;

	i = 0;
	while (!isset(set, mem[i]))
		i++;
	word = (char *)malloc(sizeof(char) * (i + 1));
	if (word == NULL)
		return (NULL);
	i = 0;
	while (mem[i] && !isset(set, mem[i]))
	{
		word[i] = mem[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

static int		count_words(char *s, char *set, t_split *l)
{
	int			i;
	int			counter;

	i = -1;
	counter = 0;
	while (s[++i])
	{
		if (l->f == 0 && !isset(set, s[i]))
		{
			counter++;
			l->f = 1;
		}
		if (l->f == 1 && isset(set, s[i]))
			l->f = 0;
	}
	return (counter);
}

static char		**spls(char *s, char *set, t_split *l)
{
	while (*s)
	{
		if (!isset(set, *s))
		{
			if (!(l->mem[l->j] = malloc_word(s, set)))
				return (free_tab(l->mem));
			while (*s && !isset(set, *s))
				s++;
			l->j++;
		}
		if (*s == '\0')
			break;
		s++;
	}
	l->mem[l->j] = NULL;
	return (l->mem);
}

char	**ft_splitset(const char *s, const char *set)
{
	t_split l;

	init_l(&l);
	if (!(l.mem = (char **)malloc(sizeof(char *) *
		(count_words((char *)s, (char *)set, &l) + 1))))
		return (NULL);
	return (spls((char *)s, (char *)set, &l));
}

#include "minishell.h"

char	*coder(char *str, int *i)
{
	if (str[*i] == ' ')
		str[*i] = SPACE;
	if (str[*i] == '|')
		str[*i] = PIPE;
	if (str[*i] == '>')
		str[*i] = REDIR_OUT;
	if (str[*i] == '<')
		str[*i] = REDIR_IN;
	if (str[*i] == '$')
		str[*i] = DOLLAR;
	return (&str[*i]);
}

void	decoder(char **str, int *i)
{
	while (str[0][*i])
	{
		if (str[0][*i] == SPACE)
			str[0][*i] = ' ';
		if (str[0][*i] == PIPE)
			str[0][*i] = '|';
		if (str[0][*i] == REDIR_OUT)
			str[0][*i] = '>';
		if (str[0][*i] == REDIR_IN)
			str[0][*i] = '<';
		if (str[0][*i] == DOLLAR)
			str[0][*i] = '$';
		++(*i);
	}
	// return (&str[*i]);
}
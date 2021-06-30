#include "minishell.h"
char	*parser(t_all *all)
{
	int		i;
	char	*tmp;

	i = -1;
	tmp = ft_strdup(all->history->current);
	while (tmp[++i])
	{
		if (tmp[i] == '\'')
		{
			if (tmp[i - 1] && tmp[i - 1] == '\\')
				continue ;
			else
				tmp = parse_quotes(tmp, &i);				
		}
	}
	return (tmp);
}

void	parse_pipes(t_all *all)
{
	t_token		*src_lst;
	t_token		*pipe_lst_tok;
	t_pipelist	*pipelist;

	init_pipe_list(all, &src_lst, &pipe_lst_tok, &pipelist);
	while (src_lst)
	{
		if (src_lst->type == '|')
			if_pipe_do(&pipelist, &pipe_lst_tok);
		else if (src_lst->type == ';')
		{
			if_semi_do(all, src_lst);
			break ;
		}
		else
		{
			set_data_and_type(src_lst, pipe_lst_tok);
			if (src_lst->next != NULL && src_lst->next->type != '|'
				&& src_lst->next->type != ';')
				pipe_lst_tok = get_next_tok_list_elem(pipe_lst_tok);
		}
		src_lst = src_lst->next;
		if (!src_lst)
			all->parse_utils->current_token = src_lst;
	}
}

char	*parse_quotes(char *str, int *i)
{
	int		j;
	char	*tmp;
	char	*tmp2;
	char	*tmp3;

	j = *i;
	tmp = NULL;
	while (str[++(*i)] != '\0')
	{
		if (str[*i] == '\'' && str[*i - 1] == '\'')
		{
			tmp = ft_strdup(str + *i);
			*i = -1;
			free(str);
			return (tmp);
		}
		else if (str[*i] == '\'' && str[*i - 1] == '\\')
			*i += 1;
		if (str[*i] == '\'')
			break ;
	}
	tmp = ft_substr(str, 0, j);
	tmp2 = ft_substr(str, j + 1, *i - (j + 1));
	tmp3 = ft_strdup(str + *i + 1);
	tmp = ft_strjoin(tmp, tmp2);
	tmp = ft_strjoin(tmp, tmp3);
	free(tmp2);
	free(tmp3);
	return (tmp);
}

int	build_tokens(t_all *all, char *line, int size, t_lexer *lexer_list)
{
	tokenize(line, size, lexer_list);
	if (check_syntax(all, lexer_list->token_list))
	{
		lexer_destroy(all->lexer_buff);
		all->parse_utils = malloc(sizeof(t_parse_utils));
		return (-1);
	}
	all->parse_utils = malloc(sizeof(t_parse_utils));
	all->parse_utils->current_token = all->lexer_buff->token_list;
	return (0);
}

void	line_parse_and_execute(t_all *all)
{
	tcsetattr(0, TCSANOW, &all->params);
	if (!build_tokens(all, all->history->current, ft_strlen(all->history->current), all->lexer_buff))
	{
		while (all->parse_utils->current_token)
		{
			parse_pipes(all);
			dereference_the_value(all);
			build_to_execute_lst(all);
			execution(all);
			destroy_to_execute_lst(all);
			destroy_parse_pipes(all);
		}
		lexer_destroy(all->lexer_buff);
		free(all->parse_utils);
	}
}
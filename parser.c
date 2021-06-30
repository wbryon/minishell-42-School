#include "minishell.h"

// void	init_tokenizer(t_lexer *lexer, int size)
// {
// 	lexer->token_list = malloc(sizeof(t_token));
// 	lexer->token = lexer->token_list;
// 	token_init(lexer->token, size);
// 	lexer->char_type = 0;
// 	lexer->j = 0;
// 	lexer->condition = 2;
// 	lexer->size = size;
// }

// int	tokenize(char *line, int size, t_lexer *lexer)
// {
// 	init_tokenizer(lexer, size);
// 	while (*line)
// 	{
// 		get_char_type(&line, &lexer->char_type);
// 		if (lexer->condition == 2)
// 			if_status_general(lexer, &line);
// 		else if (lexer->condition == 1)
// 			if_status_quote(lexer, line);
// 		else if (lexer->condition == 0)
// 			if_status_dquote(lexer, &line);
// 		if (lexer->char_type == '\0' || lexer->char_type == '\n')
// 		{
// 			if (lexer->j > 0)
// 			{
// 				lexer->token->data[lexer->j] = '\0';
// 				lexer->j = 0;
// 			}
// 		}
// 		if_last_char_is_not_zero_do_line_pp(&line);
// 	}
// 	return (set_and_return_num_of_tokens(lexer));
// }

// int	build_tokens(t_all *all, char *line, int size, t_lexer *lexer_list)
// {
// 	tokenize(line, size, lexer_list);
// 	if (check_syntax(all, lexer_list->token_list))
// 	{
// 		lexer_destroy(all->lexer_buff);
// 		all->parse_utils = malloc(sizeof(t_parse_utils));
// 		return (-1);
// 	}
// 	all->parse_utils = malloc(sizeof(t_parse_utils));
// 	all->parse_utils->current_token = all->lexer_buff->token_list;
// 	return (0);
// }

// char	*parser(t_all *all)
// {
// 	tcsetattr(0, TCSANOW, &all->params);

// 	return (NULL);
// }
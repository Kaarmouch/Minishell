/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aglampor <aglampor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 15:38:59 by aglampor          #+#    #+#             */
/*   Updated: 2024/08/08 15:41:56 by aglampor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minishell.h"
#include <stdio.h>
void	bt_u(char *l, t_token **t)
{
	t_token	*frst;

	first = (t_token *)malloc(sizeof(t_token));
	if (!first)
		return ;
	while (!(is_white(l[i])))
			i++;
	first->value = word_dup(l, 0, i);
	first->type = test_tok(first->value);

void	build_tokens(char *line, t_token **t, int turn)
{
	int	i;

	i = 0;
	while (is_white(line[i]))
		i++;
	bt_u(line[i], t)


static void	minishell(t_env *env)
{
	char	*line;
	t_token	*toks;
	int		run;
	int		i;

	(void)env;
	run = 1;
	i = 0;
	while (run)
	{
		toks = NULL;
		line = readline("MY_nishell : ");
		build_tokens(line ,&toks, 0);
		}
		i = 0;
	}
}

int	main(int ac, char **av, char **ev)
{
	t_env		*env;

	(void)ac;
	(void)av;
	env = NULL;
	init_env(&env, ev);
	minishell(env);
	free_env(env);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aglampor <aglampor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 15:38:59 by aglampor          #+#    #+#             */
/*   Updated: 2024/08/07 20:35:38 by aglampor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minishell.h"
#include <stdio.h>

static void	minishell(t_env *env)
{
	char	*line;
	char	**imput;
	int		run;
	int		i;

	(void)env;
	run = 1;
	i = 0;
	while (run)
	{
		line = readline("MY_nishell : ");
		imput = splt_white(line);
		while (imput && imput[i])
		{
			printf("%s\n", imput[i]);
			if (ft_cmp("exit", imput[i]))
			{
				ft_free_split(imput);
				return ;
			}
			i++;
		}
		ft_free_split(imput);
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

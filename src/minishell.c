/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aglampor <aglampor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 15:38:59 by aglampor          #+#    #+#             */
/*   Updated: 2024/08/04 16:34:16 by aglampor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minishell.h"
#include <stdio.h>

static int	is_white(char c)
{
	if ((c >= 9 && c <= 13) || c == 32)
		return (1);
	return (0);
}

static int	white_words(char *str)
{
	int	i;
	int	flag;

	i = 0;
	flag = 0;
	while (*str)
	{
		if (!(is_white(*str)) && flag == 0)
		{
			flag = 1;
			i++;
		}
		else
			flag = 0;
		str++;
	}
	return (i);
}

static char	**splt_white(char *s)
{
	int		i;
	int		j;
	int		index;
	char	**split;

	split = malloc((white_words(s) + 1) * sizeof(char *));
	if (!s || !(split))
		return (0);
	i = 0;
	j = 0;
	index = -1;
	while (i <= ft_strlen(s))
	{
		if (!(is_white(s[i])) && index < 0)
			index = i;
		else if ((is_white(s[i]) || i == ft_strlen(s)) && index >= 0)
		{
			split[j++] = word_dup(s, index, i);
			index = -1;
		}
		i++;
	}
	split[j] = 0;
	return (split);
}

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
			printf("%s", imput[i]);
			if (ft_cmp("exit", imput[i]))
			{
				ft_free_split(imput);
				run = 0;
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

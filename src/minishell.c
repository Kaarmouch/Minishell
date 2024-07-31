/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aglampor <aglampor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 15:38:59 by aglampor          #+#    #+#             */
/*   Updated: 2019/10/11 18:07:44 by aglampor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minishell.h"
#include <stdio.h>

static void print_env(t_env *env_list)
{
    t_env *current = env_list;

    while (current != NULL)
    {
        printf("Key: %s, Value: %s\n", current->key, current->value);
        current = current->next;
    }
}


int		main(int ac, char **av, char **ev)
{
	t_env		*env;

	(void)ac;
	(void)av;
	env = NULL;
	init_env(&env, ev);
	print_env(env);	
	free_env(env);
	return (0);
}

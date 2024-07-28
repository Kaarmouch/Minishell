/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncolomer <ncolomer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 20:05:17 by ncolomer          #+#    #+#             */
/*   Updated: 2019/11/12 19:56:48 by ncolomer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_env	*ft_lstnew(char *key, char *value)
{
	t_env	*u_env;

	if (!(u_env = (t_env*)malloc(sizeof(*u_env))))
		return (NULL);
	ft_dupstr(key, u_env->key);
	ft_dupstr(value, u_env->value);
	elt->next = NULL;
	return (elt);
}

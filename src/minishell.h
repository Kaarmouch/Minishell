#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <unistd.h>

typedef struct	s_environement
{
	char	*key;
	char	*value;
	struct	*s_environement;
}		t_env;


void	init_env(t_env **env, char **ev);
void	ft_free_split(char **split);
char	**ft_split(char *s, char c);
int	ft_strlen(char *s);
#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_chunks2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmoujan <rmoujan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 10:58:03 by rmoujan           #+#    #+#             */
/*   Updated: 2022/08/30 15:38:39 by rmoujan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"
#include "../libft/libft.h"

char	*get_value(char *ptr, char **envp)
{
	char	**tab;
	char	*new;
	char	*tmp;
	int		i;

	i = 0;
	new = ft_strdup("");
	while (envp[i])
	{
		if (strncmp (envp[i], ptr, ft_strlen(ptr)) == 0)
		{
			tab = ft_split(envp[i], '=');
			free(tab[0]);
			free(ptr);
			free(new);
			tmp = ft_strdup(tab[1]);
			free(tab[1]);
			free(tab);
			return (tmp);
		}
		i++;
	}
	free(ptr);
	return (new);
}

void	flag_expand(char *str, int i, int *flag)
{
	if (!*flag && (str[i] == '\'' || str[i] == '"'))
		*flag = str[i];
	else if (*flag && *flag == str[i])
		*flag = 0;
}

void	initial_expand(t_expand *d, char *s, char **en, char **av)
{
	d->start = 0;
	d->i = 0;
	d->new = ft_strdup("");
	d->str = s;
	d->env = en;
	d->av = av[0];
}

char	*chunk5_expand(t_expand *all)
{
	char	*new;

	new = all->new;
	free(all);
	return (new);
}

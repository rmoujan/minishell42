/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_chunks2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmoujan <rmoujan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 10:58:03 by rmoujan           #+#    #+#             */
/*   Updated: 2022/08/31 04:07:51 by rmoujan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"
#include "../libft/libft.h"


char	*strchr_value(char *s, int c)
{
	char	cara;
	int		i;
	int		j;
	char	*p1;

	i = 0;
	j = 0;
	p1 = (char *)s;
	cara = (char)c;
	while (p1[i] != '\0')
	{
		if (p1[i] == cara)
		{
			if (p1[i + 1] != '\0')
				return (&p1[i + 1]);
		}
		i++;
	}
	return (NULL);
}

char	*get_value(char *ptr, char **envp)
{
	char	**tab;
	char	*new;
	char	*value;
	int		i;

	i = 0;
	printf("hallo from expand \n");
	new = ft_strdup("");
	while (envp[i])
	{
		tab = ft_split(envp[i], '=');
		if (strcmp(tab[0], ptr) == 0)
		{
			value = strchr_value(envp[i], 61);
			free_lines(tab);
			free(ptr);
			free(new);
			if (value == NULL)
				return (ft_strdup(""));
			return (ft_strdup(value));
		}
		free_lines(tab);
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

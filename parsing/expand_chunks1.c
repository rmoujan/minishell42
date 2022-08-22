/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_chunks1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmoujan <rmoujan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 10:55:45 by rmoujan           #+#    #+#             */
/*   Updated: 2022/08/22 11:56:02 by rmoujan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"
#include "../libft/libft.h"

void	chunk0_expand(t_expand *all)
{
	char	*ptr;

	ptr = ft_substr(all->str, all->start, all->i - all->start);
	all->new = ft_strjoin(all->new, ptr);
	all->start = all->i;
}

void	chunk1_expand(t_expand *all)
{
	if (all->str[all->i + 1] != '\0' && all->str[all->i + 1] == 48)
		all->new = ft_strjoin(all->new, ft_strdup(all->av));
	else
		all->new = ft_strjoin(all->new, ft_strdup(""));
	all->start += 2;
	all->i++;
}

void	chunk2_expand(t_expand *all)
{
	char	*ptr;

	all->start = ++all->i;
	while (all->str[all->i] != '\0'
		&& (ft_isalnum(all->str[all->i]) || all->str[all->i] == '_'))
	{
		all->i++;
	}
	ptr = ft_substr(all->str, all->start, ((all->i) - all->start));
	ptr = get_value(ptr, all->env);
	all->new = ft_strjoin(all->new, ptr);
	all->start = all->i;
}

void	chunk3_expand(t_expand *all)
{
	char	*ptr;

	ptr = ft_itoa(g_state);
	all->new = ft_strjoin(all->new, ptr);
	all->start += 2;
	all->i += 2;
}

void	chunk4_expand(t_expand *all)
{
	char	*ptr;

	all->i++;
	ptr = ft_substr(all->str, all->start, all->i - all->start);
	all->new = ft_strjoin(all->new, ptr);
}

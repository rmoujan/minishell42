/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_heredoc.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmoujan <rmoujan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 15:49:29 by rmoujan           #+#    #+#             */
/*   Updated: 2022/09/03 16:05:58 by rmoujan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"
#include "../libft/libft.h"

char	*expand_dollar_heredoc(char *s, char **en, char *av[])
{
	t_expand	*d;

	d = (t_expand *) malloc(sizeof(t_expand));
	if (d == NULL)
		return (NULL);
	initial_expand(d, s, en, av);
	while (s[d->i] != '\0')
	{
		if (s[d->i] == '$')
			chunk0_expand(d);
		if (s[d->i] == '$' && ft_isdigit(s[d->i + 1]))
			chunk1_expand(d);
		else if (s[d->i] == '$' && ft_isalnum(s[d->i + 1]))
			chunk2_expand(d);
		else if (s[d->i] == '$' && s[d->i + 1] == '?')
			chunk3_expand(d);
		else if (s[d->i + 1] == '\0')
			chunk4_expand(d);
		else
			d->i++;
	}
	return (chunk5_expand(d));
}

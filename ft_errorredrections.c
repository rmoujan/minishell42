/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_errorredrections.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmoujan <rmoujan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 13:11:00 by rmoujan           #+#    #+#             */
/*   Updated: 2022/08/09 15:03:18 by rmoujan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "libft/libft.h"

void	redrections_flag(int *flag, char c)
{
	if (!*flag && (c == '\'' || c == '"'))
		*flag = c;
	else if (*flag && c == *flag)
		*flag = 0;
}

//23 lines !!!
int	cheak_redrections(char *s)
{
	int	i;
	int	flag;

	i = 0;
	flag = 0;
	if (s[0] == '<' && (s[i + 1] == '\0' || s[i + 1] == '>'))
		return (3);
	while (s[i])
	{
		redrections_flag(&flag, s[i]);
		if ((s[i] == '<' || s[i] == '>') && !flag)
		{
			if (s[i + 1] != '\0' && (s[i + 1] == '<' || s[i + 1] == '>'))
			{
				if (s[i + 2] != '\0' && (s[i + 2] == '<' || s[i + 2] == '>'))
					return (3);
			}
		}
		i++;
	}
	if (s[i - 1] == '<' || s[i - 1] == '>')
		return (3);
	return (0);
}

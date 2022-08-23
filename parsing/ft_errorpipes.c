/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_errorpipes.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmoujan <rmoujan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 13:06:09 by rmoujan           #+#    #+#             */
/*   Updated: 2022/08/23 16:43:24 by rmoujan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"
#include "../libft/libft.h"


int	check_spacepipe(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0' && str[i] == ' ')
		i++;
	if (str[i] == '|')
		return (0);
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i++] == '|')
		{
			while (str[i] != '\0' && str[i] == ' ')
				i++;
			if (str[i] == '\0')
				return (0);
		}
	}
	return (1);
}
//must recode this 7it hiya li katl3 liya error when i wrote echo "|||"
int	check_spaceafterpipe(char *str)
{
	int	i;
	int	flag;
	int pi;

	i = 0;
	flag = 0;
	pi = 0;
	while (str[i] != '\0')
	{
		if (!flag && (str[i] == '\'' || str[i] == '"'))
			flag = str[i];
		else if (flag && str[i] == flag)
			flag = 0;
		if (str[i++] == '|' && flag == 0)
		{
			pi = 0;
			while (str[i] != '\0' && str[i] != '|')
			{
				if (str[i] != ' ')
					pi = 1;
				i++;
			}
			if (pi == 0 && str[i] != '0' && str[i] == '|')
				return (0);
		}
	}
	return (1);
}

int	cheak_pipes(char *str)
{
	int	i;
	int	flag;

	i = 0;
	flag = 0;
	if (!check_spacepipe(str) || str[0] == '|')
		return (2);
	if (!check_spaceafterpipe(str))
		return (2);
	while (str[i] != '\0')
	{
		if (!flag && (str[i] == '\'' || str[i] == '"'))
			flag = str[i];
		else if (flag && str[i] == flag)
			flag = 0;
		if (str[i] == '|' && !flag)
		{
			if (str[i + 1] != '\0' && str[i + 1] == '|')
				return (2);
		}
		i++;
	}
	if (str[i - 1] == '|')
		return (2);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_specialchar.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmoujan <rmoujan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 09:34:04 by rmoujan           #+#    #+#             */
/*   Updated: 2022/08/30 15:37:31 by rmoujan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"
#include "../libft/libft.h"
//new norm !!
int	special_char(char c)
{
	if (c == ';' || c == '/')
		return (1);
	return (0);
}

void	flag_semicolon(int *flag, char c)
{
	if (!*flag && (c == '\'' || c == '"'))
		*flag = c;
	else if (*flag && c == *flag)
		*flag = 0;
}

int	check_spaceaftersemicolon(char *str)
{
	int	i;
	int	flag;
	int	pi;

	i = 0;
	flag = 0;
	pi = 0;
	while (str[i] != '\0')
	{
		flag_semicolon(&flag, str[i]);
		if (str[i++] == ';' && flag == 0)
		{
			pi = 0;
			while (str[i] != '\0' && str[i] != ';')
			{
				if (str[i] != ' ')
					pi = 1;
				i++;
			}
			if (pi == 0 && str[i] != '0' && str[i] == ';')
				return (0);
		}
	}
	return (1);
}

int	check_specialchar(char *str)
{
	int	i;
	int	flag;

	i = 0;
	flag = 0;
	if (str[0] == ';')
		return (6);
	if (!check_spaceaftersemicolon(str))
		return (6);
	while (str[i])
	{
		if (!flag && (str[i] == '\'' || str[i] == '"'))
			flag = str[i];
		else if (flag && str[i] == flag)
			flag = 0;
		if (str[i] == ';' && str[i + 1] != '\0' && str[i + 1] == ';' && !flag)
			return (6);
		i++;
	}
	return (1);
}

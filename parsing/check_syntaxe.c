/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_syntaxe.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmoujan <rmoujan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 16:01:57 by rmoujan           #+#    #+#             */
/*   Updated: 2022/08/27 19:08:53 by rmoujan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"
#include "../libft/libft.h"
//new norm
void	output_error(char *str)
{
	printf("\033[0;31m");
	printf("minishell: %s \n", str);
	printf("\033[0m");
}

int	ft_errno(int code)
{
	if (code == 1)
	{
		output_error("syntax error near unexpected token '");
		t_global.state = 258;
		return (0);
	}
	if (code == 2)
	{
		output_error("syntax error near unexpected token '|'");
		t_global.state = 258;
		return (0);
	}
	if (code == 3)
	{
		output_error("syntax error near unexpected token 'newline'");
		t_global.state = 258;
		return (0);
	}
	if (code == 6)
	{
		output_error("syntax error near unexpected token ;");
		t_global.state = 258;
		return (0);
	}
	if (code == 4)
	{
		t_global.state = 258;
		return (0);///check ret
	}
	
	return (1);
}

int	cheak_space(char *str)
{
	int	i;
	int	counter;

	i = 0;
	counter = 0;
	while (str[i] != '\0')
	{
		if (str[i] != ' ')
			counter++;
		i++;
	}
	return (counter);
}

int	cheak_quotes(char *str)
{
	int	i;
	int	flag;
	int	count;

	i = 0;
	count = 0;
	flag = 0;
	while (str[i] != '\0')
	{
		if (!flag && (str[i] == '\'' || str[i] == '"'))
		{
			flag = str[i];
			count++;
		}
		else if (flag && str[i] == flag)
		{
			flag = 0;
			count++;
		}
		i++;
	}
	if (count % 2 != 0)
		return (1);
	return (0);
}

int	ft_check(char *str)
{
	if (cheak_pipes(str) == 2)
		return (ft_errno(2));
	if (cheak_redrections(str) == 3)
		return (ft_errno(3));
	if (cheak_quotes(str) == 1)
		return (ft_errno(1));
	if (cheak_space(str) == 0)
		return (ft_errno(4));
	if (check_specialchar(str) == 6)
		return (ft_errno(6));
	return (1);
}

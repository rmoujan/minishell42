/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmoujan <rmoujan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 08:56:04 by lelbakna          #+#    #+#             */
/*   Updated: 2022/08/27 18:48:48 by rmoujan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../minishell.h"
#include "../libft/libft.h"

int	ft_check_char(char *str)
{
	int	i;

	i = 1;
	if (str[1] != 'n')
		return(1);
	while (str[i + 1] != '\0')
	{
		if (str[i] != str[i + 1])
			return (1);
		i++;
	}
	return (0);
}

int	my_echo(t_cmdfinal **cmd_final)
{
	int	i;
	int	j;
	int k;

	i = 1;
	j = 0;
	k = 0;
	if ((*cmd_final)->tab[j + 1] != NULL)
	{
		while ((*cmd_final)->tab[i] && ft_check_char((*cmd_final)->tab[i]) == 0)
		{
			k++;
			i++;
		}
		while ((*cmd_final)->tab[i])
		{
			ft_putstr_fd((*cmd_final)->tab[i], 1);
			if((*cmd_final)->tab[i + 1] && (*cmd_final)->tab[i][0] != '\0')
				ft_putchar_fd(' ', 1);
			i++;
		}
		j++;
	}
	if (k == 0)
	 	ft_putchar_fd('\n', 1);
		// system("leaks minishell");
		// while (1);
	// int i;
	i = 0;
	while ((*cmd_final)->tab[i] != '\0')
	{
		free((*cmd_final)->tab[i]);
		i++;
	}
	free((*cmd_final)->tab);
	return (0);
}
// can you handle case of echo --- --- :)?
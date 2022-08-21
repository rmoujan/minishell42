/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lelbakna <lelbakna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 18:43:06 by lelbakna          #+#    #+#             */
/*   Updated: 2022/08/21 10:58:32 by lelbakna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../minishell.h"
#include "../libft/libft.h"

int	ft_isnum(char *n)
{
	int	i;

	i = 0;
	while (n[i])
	{
		if (n[i] == '-')
			i++;
		if (ft_isdigit(n[i]) == 0)
			return (1);
		i++;
	}
	return (0);
}

int	my_exit(t_cmdfinal **cmd_final)
{
	if (ft_strncmp ((*cmd_final)->tab[0], "exit", 4) == 0 && !(*cmd_final)->tab[1])
	{
		g_state = 0;
		exit(g_state);
	}
		
	if ((*cmd_final)->tab[1] && ft_strcmp ((*cmd_final)->tab[1], "--") == 0)
		g_state = 0;
	if (ft_isnum((*cmd_final)->tab[1]) == 0 && (*cmd_final)->tab[1] && (*cmd_final)->tab[2])
	{
		g_state = 1;
		ft_putstr_fd("exit\n", 2);
		ft_putstr_fd("minishell: exit: ", 2);
		ft_putendl_fd("too many arguments", 2);
		return (1);
	}
	else if (ft_isnum((*cmd_final)->tab[1]) == 1)
	{
		g_state = 255;
		ft_putstr_fd("exit\n", 2);
		ft_putstr_fd("minishell: exit: ", 2);
		ft_putstr_fd((*cmd_final)->tab[1], 2);
		ft_putendl_fd(": numeric argument required", 2);
		exit(g_state);
	}
	else if (ft_isnum((*cmd_final)->tab[1]) == 0)
	{
		g_state = ft_atoi((*cmd_final)->tab[1]);
		if ( g_state > 255)
		g_state = g_state % 256;
		exit(g_state);
	}
	return(0);
}
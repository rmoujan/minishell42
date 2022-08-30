/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmoujan <rmoujan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/07 12:46:03 by lelbakna          #+#    #+#             */
/*   Updated: 2022/08/29 19:16:20 by rmoujan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"
#include "../libft/libft.h"

int	is_builtin(char *value)
{
	if (!value)
		return (1);
	if (!(ft_strcmp(value, "pwd")) || !(ft_strcmp(value, "export")))
		return (0);
	if (!(ft_strcmp(value, "unset")) || !(ft_strcmp(value, "env")))
		return (0);
	if (!(ft_strcmp(value, "echo\0")) || !(ft_strcmp(value, "cd\0")))
		return (0);
	if (!(ft_strcmp(value, "exit")))
		return (0);
	return (1);
}

void	execute_builtin(t_cmdfinal **cmd_final)
{
	if (!(ft_strcmp((*cmd_final)->tab[0], "echo")))
		my_echo(cmd_final);
	else if (!(ft_strcmp((*cmd_final)->tab[0], "cd")))
		my_cd(cmd_final);
	else if (!(ft_strcmp((*cmd_final)->tab[0], "pwd")))
		my_pwd(cmd_final);
	else if (!(ft_strcmp((*cmd_final)->tab[0], "export")))
		my_export(cmd_final);
	else if (!(ft_strcmp((*cmd_final)->tab[0], "unset")))
		my_unset(cmd_final);
	else if (!(ft_strcmp((*cmd_final)->tab[0], "env")))
		my_env(cmd_final);
	else if (!(ft_strcmp((*cmd_final)->tab[0], "exit")))
		my_exit(cmd_final);
}

int	exec_builtin(t_cmdfinal **cmd_final, char **av)
{
	if (!ft_check_heredoc(*cmd_final, av))
		return (0);
	if ((*cmd_final)->next == NULL && is_builtin((*cmd_final)->tab[0]) == 0)
	{
		if (ft_dup_file((*cmd_final)) == 1)
			return (1);
		execute_builtin(cmd_final);
	}
	else
	{
		exec_cmd(cmd_final);
	}
	return (1);
}
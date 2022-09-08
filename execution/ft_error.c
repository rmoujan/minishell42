/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lelbakna <lelbakna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 23:47:59 by lelbakna          #+#    #+#             */
/*   Updated: 2022/09/03 17:46:31 by lelbakna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../minishell.h"
#include "../libft/libft.h"

// void	error(void)
// {
// 	write(1, "Error\n", 6);
// 	exit(1);
// }

void	print(t_cmdfinal **cmd_final)
{
	ft_putstr_fd("$ minishell: ", 2);
	write(2, (*cmd_final)->tab[1], ft_strlen((*cmd_final)->tab[1]));
	ft_putstr_fd(" : No such file or directory\n", 2);
}

void	ft_str_error(char *str, char *s)
{
	t_global.state = 1;
	if (str != NULL)
	{
		ft_putstr_fd("$ minishell: ", 2);
		write(2, s, ft_strlen(s));
		ft_putstr_fd(" : ", 2);
	}
	write(2, str, ft_strlen(str));
	exit(t_global.state);
}

void	ft_errors_red(char *str, char *s)
{
	t_global.state = 1;
	if (str != NULL)
	{
		ft_putstr_fd("$ minishell: ", 2);
		write(2, s, ft_strlen(s));
		ft_putstr_fd(" :", 2);
	}
	write(2, str, ft_strlen(str));
	return ;
}

void	error_exe(char *str)
{
	t_global.state = 127;
	ft_putstr_fd("$ minishell: ", 2);
	write(2, str, ft_strlen(str));
	ft_putstr_fd(": command not found\n", 2);
	exit(t_global.state);
}

void	error_file(void)
{
	perror("Error file");
	exit(1);
}

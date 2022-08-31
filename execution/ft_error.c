/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmoujan <rmoujan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 23:47:59 by lelbakna          #+#    #+#             */
/*   Updated: 2022/08/31 00:31:35 by rmoujan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../minishell.h"
#include "../libft/libft.h"

void	error(void)
{
	write(1, "Error\n", 6);
	exit(1);
}

void	ft_str_error(char *str, char *s)
{
	t_global.state = 1;
	if (str != NULL)
		fprintf(stderr, "$ minishell: %s :", s);
	write(2, str, ft_strlen(str));
	exit(t_global.state);
}

void	ft_errors_red(char *str, char *s)
{
	t_global.state = 1;
	if (str != NULL)
		fprintf(stderr, "$ minishell: %s :", s);
	write(2, str, ft_strlen(str));
	return ;
}

void	error_exe(char *str)
{
	t_global.state = 127;
	ft_putstr_fd("$ minishell: ", 2);
	write(2, str, ft_strlen(str));
	ft_putstr_fd(": command not found\n", 2);
	// perror("execve");
	exit(t_global.state);
}

void	error_file(void)
{
	perror("Error file");
	exit(1);
}

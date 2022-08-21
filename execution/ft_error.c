/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lelbakna <lelbakna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 23:47:59 by lelbakna          #+#    #+#             */
/*   Updated: 2022/08/21 16:08:39 by lelbakna         ###   ########.fr       */
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
	g_state = 1;
	if (str != NULL)
		fprintf(stderr, "$ minishell: %s :", s);
	write(2, str, ft_strlen(str));
	exit(g_state);
}

void	error_exe(void)
{
	g_state = 127;
	perror("execve");
	exit(g_state);
}

void	error_file(void)
{
	perror("Error file");
	exit(1);
}

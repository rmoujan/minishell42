/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lelbakna <lelbakna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 15:36:22 by lelbakna          #+#    #+#             */
/*   Updated: 2022/08/21 16:02:14 by lelbakna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"
#include "../libft/libft.h"

void	int_handler()
{
	g_state = 130;
	ft_putchar_fd('\n',1);// check stdout or std_error
	ft_putstr_fd("\033[32;1m", 1);
	ft_putstr_fd("$ minishell \033[0;37m", 1);
	ft_putstr_fd("\033[0;37m", 1);
}

void	quit_handler()
{
	g_state = 131;
	ft_putstr_fd("Quit\n", 1);
	// write(1, "minishell>\n", ft_strlen("minishell>\n"));
}
void	interrupt_process(int signal)
{
	(void)signal;
	g_state = 130;
	write(1, "\n", 1);
}

void	end_of_file(char *str)
{
	if (str == NULL)
	{
		printf("exit");
		exit(0);//
	}
}
void	ft_e_signals(void)
{
	signal(SIGINT, interrupt_process);
	signal(SIGQUIT, quit_handler);
}

void	ft_i_signals(void)
{
	signal(SIGINT, int_handler);
	signal(SIGQUIT, SIG_IGN);
}
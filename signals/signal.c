/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmoujan <rmoujan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 15:36:22 by lelbakna          #+#    #+#             */
/*   Updated: 2022/08/23 16:29:39 by rmoujan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"
#include "../libft/libft.h"

//ctrl + c
void	int_handler()
{
	g_state = 130;
	if (t_global.here == 0)
	{
		//when you are not in heredoc
		ft_putchar_fd('\n',1);// check stdout or std_error
		//rl_on_new_line();
		//rl_replace_line("", 0);
		//rl_redisplay();
		//ft_putstr_fd("\033[32;1m", 1);
		ft_putstr_fd("$ minishell \033[0;37m", 1);
		//ft_putstr_fd("$ minishell ", 1);
		//ft_putstr_fd("\033[0;37m", 1);		
	}
	else
	{
		//when u are in heredoc and wanted to exit from herdoc
		//handling heredoc, should change the value of flag (t_global.here) and close all pipes of heredoc
	}
}

//quit 
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

//ctrl + D
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
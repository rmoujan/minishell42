/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmoujan <rmoujan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 15:36:22 by lelbakna          #+#    #+#             */
/*   Updated: 2022/08/27 16:00:50 by rmoujan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"
#include "../libft/libft.h"
//new changed by reshe !!
//ctrl + c
void	int_handler()
{
	if (t_global.herdoc == 0)
	{
		//when you are not in heredoc
		t_global.state = 130;
		ft_putchar_fd('\n',1);// check stdout or std_error
		rl_on_new_line();
		rl_replace_line("", 0);
		rl_redisplay();
		//ft_putstr_fd("\033[32;1m", 1);
		//ft_putstr_fd("$ minishell \033[0;37m", 1);
		//ft_putstr_fd("$ minishell ", 1);
		//ft_putstr_fd("\033[0;37m", 1);		
	}
	else if (t_global.herdoc == 1)
	{
		t_global.signal_s = 2;
		t_global.state = 1;	
		close(t_global.fd[0]);
		close(t_global.fd[1]);
		close(0);
	}
}

//quit 
void	quit_handler()
{
	t_global.state = 131;
	ft_putstr_fd("Quit\n", 1);
	// write(1, "minishell>\n", ft_strlen("minishell>\n"));
}

void	interrupt_process(int signal)
{
	(void)signal;
	t_global.state = 130;
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
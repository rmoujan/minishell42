/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmoujan <rmoujan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 15:36:22 by lelbakna          #+#    #+#             */
/*   Updated: 2022/08/29 23:05:23 by rmoujan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"
#include "../libft/libft.h"

void	int_handler()
{
	if (t_global.herdoc == 0)
	{
		t_global.state = 130;
		ft_putchar_fd('\n', 1);
		rl_on_new_line();
		rl_replace_line("", 0);
		rl_redisplay();
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

void	quit_handler()
{
	ft_putstr_fd("Quit\n", 1);
}

void	interrupt_process(int signal)
{
	(void)signal;
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
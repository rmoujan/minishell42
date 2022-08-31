/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmoujan <rmoujan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 23:47:12 by rmoujan           #+#    #+#             */
/*   Updated: 2022/08/31 00:40:14 by rmoujan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../minishell.h"

void	quit_handler(int sig)
{
	(void)sig;
	ft_putstr_fd("Quit\n", 1);
}

void	end_of_file(char *str)
{
	if (str == NULL)
	{
		printf("exit\n");
		exit(0);
	}
}

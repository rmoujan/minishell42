/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_herdoc_input.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lelbakna <lelbakna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 15:00:02 by rmoujan           #+#    #+#             */
/*   Updated: 2022/09/03 20:39:23 by lelbakna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"
#include "../libft/libft.h"

int	check_herdoc(char *str)
{
	if (!str)
	{
		t_global.herdoc = 0;
		if (t_global.signal_s == 2)
		{
			dup(t_global.dup_input);
			t_global.signal_s = 0;
			return (0);
		}
		else
		{
			return (1);
		}
	}
	return (2);
}

void	ft_close(t_vars *x, t_cmdfinal *tmp)
{
	t_global.herdoc = 1;
	if (x->flag1 == 1)
		close(tmp->fdhere[0]);
}

void	ret_fork(t_var	*exec)
{
	if (exec->flag == 1)
		t_global.state = 1;
	free(exec->child_pids);
}

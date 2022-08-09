/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   number_nodefinal.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmoujan <rmoujan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 17:13:31 by rmoujan           #+#    #+#             */
/*   Updated: 2022/08/09 15:55:42 by rmoujan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "libft/libft.h"

void	ft_numberofnode(t_cmdfinal *head)
{
	t_cmdfinal	*cmd;
	int			j;

	cmd = head;
	j = 0;
	while (cmd)
	{
		j++;
		cmd = cmd->next;
	}
	head->number_node = j;
}

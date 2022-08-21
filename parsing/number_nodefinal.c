/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   number_nodefinal.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmoujan <rmoujan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 17:13:31 by rmoujan           #+#    #+#             */
/*   Updated: 2022/08/21 17:26:49 by rmoujan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"
#include "../libft/libft.h"


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
	cmd = head;
	while (cmd)
	{
		cmd->number_node = j;
		cmd = cmd->next;
	}
}

void put_flagquotes(int *flag, int *i,int *start, char c)
{
    if(!*flag && (c == '\'' || c == '"'))
    {
        *flag = c;
        *start = ++(*i);
    }
    else if(*flag && *flag == c)
    {
        *flag = 0;
        *start = ++(*i);
    }
    
}
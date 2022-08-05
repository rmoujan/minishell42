/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   number_nodefinal.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmoujan <rmoujan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 17:13:31 by rmoujan           #+#    #+#             */
/*   Updated: 2022/08/05 11:28:18 by rmoujan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "libft/libft.h"

void ft_numberofnode(t_cmdfinal *head)
{
    int j;
    
    t_cmdfinal *cmd;
    cmd = head;
    j = 0;
    while (cmd)
    {
        j++;
        cmd = cmd->next;
    }
    printf("number of node are ||%d|| \n", j);
    head->number_node = j;
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmoujan <rmoujan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 19:22:06 by rmoujan           #+#    #+#             */
/*   Updated: 2022/08/05 19:26:02 by rmoujan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include  "minishell.h"

t_cmdfinal	*ft_parser(t_command *node)
{
    t_command	*tmp; 
    t_cmdfinal	*head;
    t_cmdfinal	*pointer;
    t_cmdfinal	*final;
    t_token		*save;
    
    tmp = node;
    head = 0;
    while (tmp)
    {
        save = tmp->data;
        pointer = create_node_final(tmp);
        if (head == 0)
		{
            head  = pointer;
			final = pointer;	
		}
        else
        {
            final->next = pointer;
            final = pointer;
        }
        iterate_tokens(tmp->data, pointer);
        tmp->data = save;
        tmp = tmp->next;
    }
    pointer->next = NULL;
    return (head);
}
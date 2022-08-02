/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lexer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmoujan <rmoujan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 20:43:34 by rmoujan           #+#    #+#             */
/*   Updated: 2022/07/21 12:31:59 by rmoujan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "libft/libft.h"


t_command *ft_lexer(t_command *data, char *const envp[], char *argv[])
{
    t_command *tmp;

    tmp = data;
    //if there are some << or > < >>  should remove all of them
    // from nodes or create new linked list from zero and put nodes without < > << >>
    while(tmp)
    {
        while (tmp->data)
        {
            if (ft_strcmp(tmp->data->token, "<")  == 0)
            {
                printf("<\n");
            }
            else if (ft_strcmp(tmp->data->token, "<<") == 0)
            {
                printf("<<\n");
            }
            else if (ft_strcmp(tmp->data->token, ">") == 0)
            {
                printf(">\n");
            }
            else if (ft_strcmp(tmp->data->token, ">>") == 0)
            {
                printf(">\n");
            }
            tmp->data = tmp->data->next;
        }
        tmp = tmp->next;
    }
    return tmp;
}

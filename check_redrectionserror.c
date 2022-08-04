/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_redrectionserror.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmoujan <rmoujan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 11:25:35 by rmoujan           #+#    #+#             */
/*   Updated: 2022/08/04 12:42:46 by rmoujan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "libft/libft.h"


int compare_redrections(char *str)
{
    if (strcmp(str, "<") == 0 || strcmp(str, ">") == 0 
    || strcmp(str, "<<") == 0 || strcmp(str, ">>") == 0 )
    {
        return 1;
    }
    return 0;
}

int ft_red(char *str1, char *str2)
{
    // if (strcmp(str1, str2) == 0)
    //     return 1;
    if(compare_redrections(str1) == 1)
    {
        if(compare_redrections(str2) == 1)
            return 1;   
    }
    return 0;
}

int ft_checkredrections(t_command *head)
{
    t_command *tmp;
    t_token *save;
    
    tmp = head;
    printf("===>  STARTING CHEAK \n");
    while (tmp)
    {
        printf("===> WHILLLLLE 1\n");
        save = tmp->data;
        while (tmp->data)
        { printf("===> WHILLLLLE 2\n");
            if (tmp->data->next != NULL)
            {
                 printf("===> IIIIIIFFF 1\n");
                if(ft_red(tmp->data->token, tmp->data->next->token) == 1)
                {
                    printf("===> IIIIIIFFF 2\n");
                    tmp->data = save;
                    ft_errno(3);
                    free_node(head);
                    return (-1);
                }
            }
            tmp->data = tmp->data->next;
        }
        tmp->data = save;
        tmp = tmp->next;
    }
    return (0);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_errorstr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmoujan <rmoujan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 15:39:10 by rmoujan           #+#    #+#             */
/*   Updated: 2022/08/01 16:51:30 by rmoujan          ###   ########.fr       */
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

void ft_errno2(int code)
{
    if (code == 5)
    {
        printf("minishell: command not found'\n");
        exit(0);
    }
}

int count_quotes(char *str)
{
    int i;
    i = 0;
    while (str[i] != '\0')
    {
        if (str[i] != '\'' && str[i] != '"')
        {
            printf("count quotes |%c|\n", str[i + 1]);
            return 1;
            
        }
        i++;
    } 
    printf("****** else count double quotes \n");   
    return 0;
}

void check_emptystr(t_command *data)
{
    t_command *tmp;
    t_token *token;
    
    tmp = data;
    while (tmp !=  NULL)
    {
        token = tmp->data;
        while (tmp->data != NULL)
        {
            printf("==> %s\n", tmp->data->token);
            if (compare_redrections(tmp->data->token) == 1)
            {
                tmp->data = tmp->data->next;
            }
            else
            {
                if (count_quotes(tmp->data->token)== 0)
                {
                    printf("INSIDE ERRNO \n");
                    ft_errno2(5);
                }
            }
            tmp->data = tmp->data->next; 
        }
        tmp->data = token;
        tmp= tmp->next;
    } 
}
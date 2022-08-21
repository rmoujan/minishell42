/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_output.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmoujan <rmoujan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 19:01:23 by rmoujan           #+#    #+#             */
/*   Updated: 2022/08/21 17:26:24 by rmoujan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"
#include "../libft/libft.h"


void ft_output(t_command *data)
{
    int i;
    i = 1;
    printf("***output from ft_output***\n");
    t_command *tmp;

    
    tmp = data;
    t_token *middle = NULL;
    while(tmp)
    {
        printf("node number %d are \n", i);
        middle = tmp->data;
        while (tmp->data)
        {
            //printf("** (%s) and id is (%d)\n",tmp->data->token, tmp->data->id);
            printf("** (%s) \n",tmp->data->token);
            tmp->data = tmp->data->next;
        }
        tmp->data = middle;
        tmp = tmp->next;
        i++;
    }
}

void output(char **cmds)
{
    int  i = 0;
    while (cmds[i] != '\0')
    {
        printf("*** %s\n", cmds[i]);
        i++;
    }
}

void ft_outputcmdfinal(t_cmdfinal *cmd)
{
    int i = 0;
    int j = 1;
    

    printf("|||| OUTPUT CMDFINAL |||| \n");
    while (cmd)
    {
        i = 0;
        printf("cmd number %d is : \n\n", j);
        // printf("===> cmd and its args \n");
        while (cmd->tab[i])
        {
            printf("|%s|\n", cmd->tab[i]);
            i++;
        }
        printf("===> IN OU files of cmd \n");
        while (cmd->file)
        {
            printf("file is : |%s| AND ID is is |%d| \n", cmd->file->name, cmd->file->id);
            cmd->file = cmd->file->next;
        }
        // printf("koko\n");
        cmd = cmd->next;
        j++;
    }
}
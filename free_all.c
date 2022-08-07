/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmoujan <rmoujan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 19:13:34 by rmoujan           #+#    #+#             */
/*   Updated: 2022/08/07 18:10:05 by rmoujan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "libft/libft.h"

//all fcts have less or equal to 25 lines !!!!
void free_node(t_command *head)
{
    t_command *tmp;
    t_token *token;
    
    while (head)
    {
        tmp = head;
		while (head->data)
		{
            token = head->data->next;
			free(head->data->token);
			free(head->data);
			head->data = token;
		}
		head  = tmp->next;
		free(tmp);
    } 
}

void free_lines(char **cmds)
{
    int i;

    i = 0;
    while (cmds[i] != '\0')
    {
        free(cmds[i]);
        i++;
    }
    free(cmds);
}

//16 lines !!!
void free_cmdfinal(t_cmdfinal *cmd)
{
    t_files *tmp;
    t_cmdfinal *pointer;

    //printf("|||| FREE CMD FINAL|||| \n");
    while (cmd !=  NULL) 
    {
        pointer = cmd;
        free_lines(cmd->tab);
        // while (cmd->tab[i])
        // {
        //     free(cmd->tab[i]);
        //     i++;
        // }
        // free(cmd->tab);
        while (cmd->file)
        {
            tmp = cmd->file->next;
            free(cmd->file->name);
            free(cmd->file);
            cmd->file = tmp;
        }
        free(cmd);
        cmd = pointer->next;
    }
}
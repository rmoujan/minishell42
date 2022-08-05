/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmoujan <rmoujan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 19:13:34 by rmoujan           #+#    #+#             */
/*   Updated: 2022/08/05 11:57:19 by rmoujan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "libft/libft.h"

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

//28 lines !!!
void free_cmdfinal(t_cmdfinal *cmd)
{
    t_files *tmp;
    t_cmdfinal *pointer;
    int i;
    int j;

    i = 0;
    j = 1;
    printf("|||| FREE CMD FINAL|||| \n");
    //ERROR que wakha t salat data mn cmd ba9i kaydor f while !!!!
    while (cmd !=  NULL) 
    {
        pointer = cmd;
        i = 0;
        while (cmd->tab[i])
        {
            free(cmd->tab[i]);
            i++;
        }
       free(cmd->tab);
        while (cmd->file)
        {
            tmp = cmd->file->next;
            free(cmd->file->name);
            free(cmd->file);
            cmd->file = tmp;
        }
        free(cmd);
        cmd = pointer->next;
        j++;
    }
}
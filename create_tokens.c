/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_tokens.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmoujan <rmoujan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 20:19:21 by rmoujan           #+#    #+#             */
/*   Updated: 2022/08/05 11:27:18 by rmoujan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "libft/libft.h"

t_token *create_token(char *str)
{
    t_token *node_token;

    //create token:
    node_token = (t_token*) malloc(sizeof(t_token));
    return_space_double(&str);
    //return_space_single(&str);
    node_token->token = ft_strdup(str);
    return node_token;
}

t_command *create_cmd(char **data)
{
    t_command *node_cmd;
    t_token *node_token;
    t_token *tmp_token;
    // t_token *head_token;
    
    //create cmd global:
    node_cmd = (t_command*) malloc(sizeof(t_command));
    int i = 0;
    while (data[i])
    {
       node_token = create_token(data[i]);
       //linked each token with the next and put the first one on node global !!!
       if (i == 0)
       {
        node_cmd->data = tmp_token = node_token;
       }
       else
       {
        tmp_token->next = node_token;
        tmp_token = node_token;
       }
    //    free(data[i]);
        //printf("data number |%d| is |%s| \n", i, node_token->token);
       i++;
    }
    // free_lines(data);
   tmp_token->next = NULL;
   return node_cmd;
}
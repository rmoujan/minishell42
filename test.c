/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmoujan <rmoujan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 19:22:06 by rmoujan           #+#    #+#             */
/*   Updated: 2022/08/07 14:34:29 by rmoujan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include  "minishell.h"

void iterate_tokens(t_token *tmp, t_cmdfinal *head)
{
    t_files *file;
    t_files *pointer;
    int i;
    int j;
    int id;
    
    i = 0;
    j = 0;
    while (tmp)
    {
        //check if there is rederict
        if (is_redirect(tmp->token) != 0)
        {
            id = is_redirect(tmp->token);
            if (tmp->next != NULL)
            {
                tmp = tmp->next;
                file = create_file(tmp->token, id);
                link_nodetokens(&file, &pointer, &head, j);
                j++;
            }
        }
        else
            head->tab[i++] = ft_strdup(tmp->token);
        tmp = tmp->next;
    }
    //should put this on a fct !!
    // if (file != NULL)
    //     file->next = NULL;
    // if (j == 0)
    //     head->file = NULL;
    // head->tab[i] = NULL;
    put_null(&file, &head, i, j);
}
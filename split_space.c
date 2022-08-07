/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_space.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmoujan <rmoujan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 17:08:09 by rmoujan           #+#    #+#             */
/*   Updated: 2022/08/07 11:14:30 by rmoujan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "libft/libft.h"


//I'm working with it
//new version
//I replace each space that inside " " with -2 !!!!!
void replace_space_double(char **ptr)
{
    int i;
    int flag;
    char *str;
    
    i = 0;
    flag = 0;
    str = *ptr;
    while (str[i] != '\0')
    {
        if(!flag && (str[i] == '\'' || str[i] == '"'))
            flag = str[i];
        else if(flag && flag == str[i])
            flag = 0; 
        if (str[i] == ' ' && flag)
            str[i] = -2;
        i++;
    }
}


void return_space_double(char **str1)
{
    int i;
    int flag;
    char *str;
    
    str = *str1;
    flag = 0;
    i = 0;
    //I replace each -2 that inside " " with space !!!!!
    while (str[i] != '\0')
    {
        if(!flag && (str[i] == '\'' || str[i] == '"'))
            flag = str[i];
        else if(flag && flag == str[i])
            flag = 0; 
   
        if (str[i] == -2 && flag)
            str[i] = ' ';
        i++;
    }
}

//27 lines !!!
// start creation of the  big node t_command !!!!
t_command *split_space(char **cmds)
{
    t_command	*head;
    t_command	*tmp;
    t_command	*node;
    char		**data;
    int			i;
  
    i = 0;
    while (cmds[i])
    {
        replace_space_double(&cmds[i]);
        data = ft_split(cmds[i], ' ');
		node = create_cmd(data);
        if (i == 0)
        {
            head = node;
			tmp  = node;
        }
        else
        {
            tmp->next = node;
		    tmp = node;
        }
        free_lines(data);
        i++;
    }
    tmp->next = NULL;
    return head;
}
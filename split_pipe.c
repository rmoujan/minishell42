/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_pipe.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmoujan <rmoujan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 19:53:15 by rmoujan           #+#    #+#             */
/*   Updated: 2022/08/07 19:25:27 by rmoujan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "libft/libft.h"

//I'm working with it
//17 lines 
void replace_pipe_double(char **ptr)
{
    int i;
    int flag;
    char *str;
    
    i = 0;
    str = *ptr;
    flag = 0;   
    //I replace each | that inside " " or ' ' with -2 !!!!!
    while (str[i] != '\0')
    {
        if(!flag && (str[i] == '\'' || str[i] == '"'))
            flag = str[i];
        else if(flag && flag == str[i])
            flag = 0; 
        if (str[i] == '|' && flag)
            str[i] = -2;
        i++;
    }
}

// 17 lines !!!
//new version
//replace -2 inside " " with |
void return_pipe_double(char **str1)
{
    int i;
    int flag;
    char *str;
    
    i = 0;
    flag  = 0;
    str = *str1;
    //I replace each | that inside " " with -2 !!!!!
    while (str[i] != '\0')
    {
        if(!flag && (str[i] == '\'' || str[i] == '"'))
            flag = str[i];
        else if(flag && flag == str[i])
            flag = 0; 
        if (str[i] == -2 && flag)
            str[i] = '|';
        i++;
    }
}

void return_pipes(char ***ptr)
{
    int i;
    char **cmds;
    
    i = 0;
    cmds  = *ptr;
    while (cmds[i])
    {
        return_pipe_double(&cmds[i]);
        i++;
    }
}
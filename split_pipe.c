/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_pipe.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmoujan <rmoujan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 19:53:15 by rmoujan           #+#    #+#             */
/*   Updated: 2022/07/20 19:56:17 by rmoujan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "libft/libft.h"

//check if there are any pipes inside " " to replace them with -2
void replace_pipe_double(char **ptr)
{
    int i;
    char *str;
    
    i = 0;
    str = *ptr;
    //I replace each | that inside " " with -2 !!!!!
    while (str[i] != '\0')
    {
        if (str[i] == '"')
        {
            i++;
            while (str[i] != '\0' && str[i] != '"')
            {
                if (str[i] == '|')
                {
                    printf("IF\n");
                    str[i] = -2;
                }
                i++;
            }
        }
        i++;
    }
}


//check if there are any pipes inside ' ' to replace them with -2
void replace_pipe_single(char **ptr)
{
    int i;
    char *str;
    
    i = 0;
    str = *ptr;
    //I replace each | that inside " " with -2 !!!!!
    while (str[i] != '\0')
    {
        if (str[i] == '\'')
        {
            i++;
            while (str[i] != '\0' && str[i] != '\'')
            {
                if (str[i] == '|')
                {
                    printf("IF\n");
                    str[i] = -2;
                }
                i++;
            }
        }
        i++;
    }
}

//replace -2 inside " " with |
void return_pipe_double(char **str1)
{
    int i;
    i = 0;
    char *str;
    str = *str1;
    //I replace each | that inside " " with -2 !!!!!
    while (str[i] != '\0')
    {
        if (str[i] == '"')
        {
            i++;
            while (str[i] != '\0' && str[i] != '"')
            {
                if (str[i] == -2)
                {
                    printf("return pipe IF\n");
                    str[i] = '|';
                }
                i++;
            }
        }
        i++;
    }
}

//replace -2 inside ' ' with |
void return_pipe_single(char **str1)
{
    int i;
    i = 0;
    char *str;
    str = *str1;
    //I replace each | that inside " " with -2 !!!!!
    while (str[i] != '\0')
    {
        if (str[i] == '\'')
        {
            i++;
            while (str[i] != '\0' && str[i] != '\'')
            {
                if (str[i] == -2)
                {
                    printf("IF\n");
                    str[i] = '|';
                }
                i++;
            }
        }
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
        return_pipe_single(&cmds[i]);
        i++;
    }
}
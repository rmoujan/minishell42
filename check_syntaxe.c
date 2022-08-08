/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_syntaxe.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmoujan <rmoujan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 16:01:57 by rmoujan           #+#    #+#             */
/*   Updated: 2022/08/08 15:42:05 by rmoujan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "libft/libft.h"
//still need norm ==> there are some fcts more than 25 lines !!!!
//test case : "espace | cmdname" ::  should must handle this stest case !!!!! == >normalement bash skip spaces ==> is done !!!!!
//// had case khedama :: !!!!! """'''"''""''"'"'"""' ls
//// NOTE :: most of this functions are  working well 
//// WHEN :: I add many dq and sq !!!!!
void output_error(char *str)
{
    printf("\033[0;31m");
    printf("minishell: %s \n", str);
    printf("\033[0m");
}

//20lines !!
int ft_errno(int code)
{
    if (code == 1)
    {
        output_error("syntax error near unexpected token '");
        return(0);
    }
    if (code == 2)
    {
        output_error("syntax error near unexpected token '|'");
        return(0);
    }
    if (code == 3)
    {
        output_error("syntax error near unexpected token '<'");
        return(0);
    }
    if (code == 4)
    {
        return(0);
    }
    return (1);
}

//32
//I think still not complet !!!
int cheak_redrections(char *str)
{
    int i;
    int flag;
    
    i = 0;
    flag = 0;
    if (str[0] == '<' && (str[i + 1] == '\0' || str[i + 1] == '>'))
        return 3;
    while (str[i])
    {
        if (!flag && (str[i] == '\'' || str[i] == '"'))
        {
            flag = str[i];
        }
        else if (flag && str[i] == flag)
        {
            flag = 0;
        }
        if ((str[i] == '<' || str[i] == '>') && !flag)
        {
            if (str[i + 1] != '\0' && (str[i + 1] == '<' || str[i + 1] == '>'))
            {
                if (str[i + 2] != '\0' && (str[i + 2] == '<' || str[i + 2] == '>'))
                {
                    return 3;
                }
            }
        }
        i++;
    }
    if (str[i - 1] == '<' || str[i - 1] == '>')
        return 3;
    return 0;
}
//19 lines
int check_spacepipe(char *str)
{
    int i;
    
    i = 0;
    while (str[i] != '\0' && str[i] == ' ')
        i++;
    if (str[i] == '|')
        return 0;
    i = 0;
    while (str[i] != '\0')
    {
        if (str[i++] == '|')
        {
            while (str[i] != '\0' && str[i] == ' ')
                i++;
            if (str[i] == '\0')
                return 0;
        }
    }
    return 1;
}

//21 lines
int check_spaceafterpipe(char *str)
{
    int i;
    int flag;
    
    i = 0;
    flag = 0;
    while (str[i] != '\0')
    {
        if (str[i++] == '|')
        {
            flag = 0;
            while (str[i] != '\0' && str[i] != '|')
            {
                if (str[i] != ' ')
                    flag = 1;
                i++;   
            }
            if (flag == 0 && str[i] != '0' && str[i] == '|')
                return 0;
        }
    }
    return 1;
}

//25 lines
int cheak_pipes(char *str)
{
    int i;
    int flag;

    i = 0;
    flag = 0;
    if (!check_spacepipe(str) || str[0] == '|')
        return 2;
    if (!check_spaceafterpipe(str))
        return 2;
    while (str[i] != '\0')
    {
        if (!flag && (str[i] == '\'' || str[i] == '"'))
            flag = str[i];
        else if (flag && str[i] == flag)
            flag = 0;
        if (str[i] == '|' && !flag)
        {
            if (str[i + 1] != '\0' && str[i + 1] == '|')
                return 2;
        }
        i++;
    }
    if (str[i - 1] == '|')
        return 2;
    return 0;
}

//14 lines
int cheak_space(char *str)
{
    int i;
    int counter;
    
    i = 0;
    counter = 0;
    while (str[i] != '\0')
    {
        if (str[i] != ' ')
        {
            counter++;
        }
        i++;
    }
    return counter;
}

//23 lines
//it seems it's working !!!!!!
int cheak_quotes(char *str)
{
    int i;
    int flag;
    int count;

    i = 0;
    count = 0;
    flag = 0;
    while (str[i] != '\0')
    {
        if (!flag && (str[i] == '\'' || str[i] == '"'))
        {
            flag = str[i];
            count++;
        }
        else if (flag && str[i] == flag)
        {
            flag = 0;
            count++;
        }
        i++;
    }
    if (count % 2 != 0)
        return 1;
    return 0;
}

// 17 lines 
int ft_check(char *str)
{
    if (cheak_pipes(str) == 2)
    {
        // printf("pipes\n");
        return (ft_errno(2));
    }
    if (cheak_redrections(str) == 3)
    {
        // printf("red\n");
        return (ft_errno(3));
    }
    if (cheak_quotes(str) == 1)
    {
        // printf("quotes \n");
        return (ft_errno(1));
    }
    if (cheak_space(str) == 0)
    {
        // printf("space\n");
        return (ft_errno(4));
    }
    return 1;
}
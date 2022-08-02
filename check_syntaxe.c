/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_syntaxe.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmoujan <rmoujan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 16:01:57 by rmoujan           #+#    #+#             */
/*   Updated: 2022/08/02 14:42:06 by rmoujan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "libft/libft.h"



//// NOTE :: most of this functions are not working well 
//// WHEN :: I add many dq and sq !!!!!
int ft_errno(int code)
{
    if (code == 1)
    {
        printf("minishell: syntax error near unexpected token '\n");
        return(0);
    }
    if (code == 2)
    {
        printf("minishell: syntax error near unexpected token '|'\n");
        return(0);
    }
     if (code == 3)
    {
        printf("minishell: syntax error near unexpected token '<'\n");
        return(0);
    }
     if (code == 4)
    {
        printf("minishell: syntax error near unexpected token '\n");
        return(0);
    }
     if (code == 5)
    {
        return(0);
    }
    return (1);
}



int cheak_redrections(char *str)
{
    int i;
    i = 0;
    
    if (str[0] == '<' && (str[i + 1] == '\0' || str[i + 1] == '>'))
        return 3;
    while (str[i])
    {
        if (str[i] == '<' || str[i] == '>')
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

int cheak_pipes(char *str)
{
    int i;

    i = 0;
    if (str[0] == '|')
        return 2;
    while (str[i] != '\0')
    {
        if (str[i] == '|')
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
//old vers not working completly !!
// int cheak_sq(char *input_user)
// {
//     int i;
//     int count;

//     i = 0;
//     count = 0;
//     while (input_user[i] != '\0')
//     {
//         if (input_user[i] == '"')
//         {
//             i++;
//             while (input_user[i] != '\0' && input_user[i] != '"')
//             {
//                 i++;
//             }
//         }
//         else{
            
//             if (input_user[i] == '\'')
//                 count++; 
//         }
//         i++;
//     }
//     if (count % 2 != 0)
//         return 1;
//     return 0;
// }

//I think this vers is working !!
int cheak_sq(char *input_user)
{
    int i;
    int count;

    i = 0;
    count = 0;
    while (input_user[i] != '\0')
    {
        if (input_user[i] == '"' && count == 0)
        {
            i++;
            while (input_user[i] != '\0' && (input_user[i] != '"'))
            {
                i++;
            }
            // if (input_user[i] == '"')
            //      i++;
        }
        else{
            
            if (input_user[i] == '\'')
                count++; 
        }
        i++;
    }
    // printf("count is %d\n", count);
    if (count % 2 != 0)
        return 1;
    return 0;
}


//I think this vers is working !!
int cheak_dq(char *input_user)
{
    int i;
    int count;

    i = 0;
    count = 0;
    while (input_user[i] != '\0')
    {
        if (input_user[i] == '\'' && count == 0)
        {
            i++;
            while (input_user[i] != '\0' && (input_user[i] != '\''))
            {
                i++;
            }
        }
        else{
            
            if (input_user[i] == '"')
                count++; 
        }
        i++;
    }
    // printf("count is %d\n", count);
    if (count % 2 != 0)
        return 4;
    return 0;
}

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




int ft_check(char *str)
{
    int i;
    int count;
    
    if (cheak_pipes(str) == 2)
    {
        printf("pipes\n");
        return (ft_errno(2));
    }
    if (cheak_redrections(str) == 3)
    {
        printf("red\n");
        return (ft_errno(3));
    }
    if (cheak_sq(str) == 1)
    {
        printf("single Q\n");
        return (ft_errno(1));
    }
    if (cheak_dq(str) == 4)
    {
        printf("DOUBLE Q\n");
        return (ft_errno(4));
    }
    if (cheak_space(str) == 0)
    {
        printf("space\n");
        return (ft_errno(5));
    }
    return 1;
}
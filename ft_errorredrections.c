/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_errorredrections.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmoujan <rmoujan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 13:11:00 by rmoujan           #+#    #+#             */
/*   Updated: 2022/08/09 13:15:41 by rmoujan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "libft/libft.h"

void redrections_flag(int *flag, char c)
{
    if (!*flag && (c == '\'' || c == '"'))
        *flag = c;
    else if (*flag && c == *flag)
        *flag = 0;
}

//23 lines !!!
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
        redrections_flag(&flag, str[i]);
        if ((str[i] == '<' || str[i] == '>') && !flag)
        {
            if (str[i + 1] != '\0' && (str[i + 1] == '<' || str[i + 1] == '>'))
            {
                if (str[i + 2] != '\0' && (str[i + 2] == '<' || str[i + 2] == '>'))
                    return 3;
            }
        }
        i++;
    }
    if (str[i - 1] == '<' || str[i - 1] == '>')
        return 3;
    return 0;
}
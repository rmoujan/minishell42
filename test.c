/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmoujan <rmoujan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 19:22:06 by rmoujan           #+#    #+#             */
/*   Updated: 2022/08/07 17:55:11 by rmoujan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include  "minishell.h"

char *handle_quotes(char *str)
{
    char *new;
    int start;
    int flag;
    int i;
    
    flag = 0;
    i = 0;
    new = ft_strdup("");
    while (str[i] != '\0')
    {
        start = i;
        put_flag(&flag, &i, &start, str[i]);
        if (flag)
        {
            while (str[i] != '\0' && str[i] != flag)
                i++;
        }
        else
        {
            while (str[i] != '\0' && (str[i] != '\'' && str[i] != '"'))
                i++;
        }
        new = ft_strjoin(new, ft_substr(str, start, (i - start)));
    }
    return new;
}
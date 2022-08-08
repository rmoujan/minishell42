/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmoujan <rmoujan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 19:22:06 by rmoujan           #+#    #+#             */
/*   Updated: 2022/08/08 14:08:48 by rmoujan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include  "minishell.h"

//customize before norm :: 
//> 69 lines
//all cases of dollar !! leaks kaynin heennnnnnnnnnna !!!!!
//I am now custmizing this !!!!
char *expand_dollar(char *str, char *const envp[], char *argv[])
{
    char *ptr;
    char *new;
    int start;
    int flag;
    int i;
    
    start = 0;
    flag = 0;
    i = 0;
    new = ft_strdup("");
    while (str[i] != '\0')
    {
        if(!flag && (str[i] == '\'' || str[i] == '"'))
            flag = str[i];
        else if(flag && flag == str[i])
            flag = 0;
        if (str[i] == '$')
        {
            ptr = ft_substr(str, start, i - start);
            new = ft_strjoin(new, ptr);
            start = i;
        }
        if (str[i] == '$' && ft_isdigit(str[i + 1]) && flag != '\'')
        {
            if (str[i + 1] != '\0' && str[i + 1] == 48)
            {
                //ptr = ft_strdup(argv[0]);
                ptr = argv[0];
                new = ft_strjoin(new, ptr);
            }
            else
            {
                ptr = ft_strdup("");
                new = ft_strjoin(new, ptr);  
            }
            start += 2;
            i++;
        }
        else if (str[i] ==  '$' && ft_isalnum(str[i + 1]) && flag != '\'')
        {
            start = ++i;
            while (str[i] != '\0' && (ft_isalnum(str[i]) || str[i] == '_'))
                i++;
            ptr = ft_substr(str, start, ((i) - start));
            ptr = get_value(ptr, envp);
            new = ft_strjoin(new, ptr);
            start = i;
        }
        else if (str[i] == '$' && str[i + 1] == '?' && flag != '\'')
        {
            //exit status of the last prg :   
            ptr = ft_itoa(g_state);
            new = ft_strjoin(new, ptr);
            start += 2;
            i += 2;
        }
        else if (str[i] == '$' && (str[i + 1] == '\'' || str[i + 1] =='"'))
        {
            //when we meet $ and next char is " or ' , we must skip this $ !!!!
            start = ++i;
        }
        else if(str[i + 1] == '\0')
        {
            i++;
            ptr = ft_substr(str, start, i - start);
            new = ft_strjoin(new, ptr);
        }
        else
            i++;
    }
    return new;
}
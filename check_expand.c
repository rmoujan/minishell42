/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_expand.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmoujan <rmoujan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 21:24:59 by rmoujan           #+#    #+#             */
/*   Updated: 2022/06/30 20:09:10 by rmoujan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "libft/libft.h"

//sttill needs work
char * get_value(char *str, char *const envp[])
{
    int i = 0;
    char *ptr;
    char **tab;

    ptr = &str[1];
    // printf("ENVP\n");
    while (envp[i])
    {
        if (strncmp(envp[i], ptr, ft_strlen(ptr))== 0)
        {
            // printf("|%zu| and |%s| \n", ft_strlen(ptr), ptr);
            // printf("YESs\n");
            tab = ft_split(envp[i], '=');
            return (tab[1]);
            // printf("value of %s is %s\n", ptr, tab[1]);
        }
        i++;
    }
    return "";
}

void check_dollar(t_token *data, char *const envp[])
{
    int i;
    int start = 0;
    char *str1;
    char *str2;
    char *str3;
    i = 0;
    str1 =  ft_strdup("");
    str2 =  ft_strdup("");
    while (data->token[i] != '\0')
    {
        if (data->token[i] == '$')
        {
            start = i;
            while (data->token[i] != '\0' && data->token[i] != '"' && data->token[i] != ' ' 
            && data->token[i] != '\'')
            {
                i++;
            }
            // printf("INSiDE DOLLAR\n");
            str2 = ft_substr(data->token, start, (i - start));
            printf("inside dollar |%s|\n", str2);
            str2 = get_value(str2, envp);
            str1 = ft_strjoin(str1, str2);
        }
        else
        {
            // str2 = ft_strdup(data->token[i]);
            start = i;
            while (data->token[i] != '\0' && data->token[i] != '$')
            {
                i++;
            }
            str2 = ft_substr(data->token, start, (i - start));
            printf("|%s| \n", str2);
            str1 = ft_strjoin(str1,str2);
            // i++;
        }
    }
    printf("++from check_dollar  str1 is |%s|\n", str1);
}

void check_expand(t_command *node, char *const envp[])
{
    t_command *tmp;

    tmp = node;
    while (tmp)
    {
        while (tmp->data)
        {
            if (tmp->data->id == 4)
            {
                // printf("**%s\n", tmp->data->token);
                check_dollar(tmp->data, envp);
            }
            tmp->data = tmp->data->next;
        }
        tmp = tmp->next;
    }
}
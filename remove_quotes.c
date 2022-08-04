/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_quotes.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmoujan <rmoujan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 20:24:57 by rmoujan           #+#    #+#             */
/*   Updated: 2022/08/04 20:31:09 by rmoujan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "libft/libft.h"
//I'm working with it
char *handle_quotes(char *str)
{
    int i;
    int flag;
    int start;
    char *ptr;
    char *new;
    flag = 0;
    i = 0;
    start = 0;
    new = ft_strdup("");
    // printf("before str is |%s|\n", str);
    while (str[i] != '\0')
    {
        start = i;
        if(!flag && (str[i] == '\'' || str[i] == '"'))
        {
            flag = str[i];
            start = ++i;
        }
        else if(flag && flag == str[i])
        {
            flag = 0;
            start = ++i;
        }
        if (flag)
        {
            while (str[i] != '\0' && str[i] != flag)
            {
                i++;
            }
        }
        else
        {
            while (str[i] != '\0' && (str[i] != '\'' && str[i] != '"'))
            {
                i++;
            }
        }
        ptr = ft_substr(str, start, (i - start));
        new = ft_strjoin(new, ptr);
    }
    // printf("NEW IS :: %s\n", new);
    return new;
}

int check_quotes(char *str)
{
    int counter;
    int i;
    counter = 0 ;
    i = 0;
    
    while (str[i] != '\0')
    {
        if (str[i] == '"' || str[i] == '\'')
        {
            counter++;
        }
        i++;
    }
    return counter;
}

int check_spacecmd(char *str)
{
    int counter;
    counter = 0 ;
    int i ;
    i = 0;
    while (str[i])
    {
        if (str[i] == ' ')
            counter++;
        i++;
    }
    return counter;
}

 void handle_cmd(char ***tab)
 {
    char **cmd;
    char *ptr;
    cmd = *tab;
    int i;
    i = 0;
    //I don't rembeber this fct what it did !!!!
    //==> khas doubleq and sq yt7ydo ghi fash makykonsh 3andi space 
    //f name cmd ya3ni first elm f tab d cmd and +++ ila kant haka "ls" khashom yt7yedo ila kan haka 
    //"ls -la" makhshomsh yt7ydo !!! .. kanden khashom yt7eydooo !!!
    // if (check_quotes(cmd[0]) != '\0')
    // {
    //     if (check_spacecmd(cmd[0]) == 0)
    //        {
    //             cmd[0] = handle_quotes(cmd[0]);
    //        }
    // }
    while (cmd[i])
    {
        if (check_quotes(cmd[i]) != '\0')
        {
            ptr = cmd[i];
            cmd[i] = handle_quotes(cmd[i]);
            free(ptr);
        }
        i++;
    }
 }
 
 void ft_remove(t_cmdfinal *cmd)
{
    t_cmdfinal *tmp;
    char *ptr;
    t_files *save;
    tmp = cmd;
    while (tmp)
    {
        save = tmp->file;
        while (tmp->file)
        {
            if (check_quotes(tmp->file->name) != 0)
            {
                ptr = tmp->file->name;
                tmp->file->name = handle_quotes(tmp->file->name);
                free(ptr);
            }
            tmp->file = tmp->file->next;
        }
        handle_cmd(&tmp->tab);
        tmp->file = save;
        tmp = tmp->next;
    }
}
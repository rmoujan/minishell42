/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_quotes.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmoujan <rmoujan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 20:24:57 by rmoujan           #+#    #+#             */
/*   Updated: 2022/08/07 18:00:19 by rmoujan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "libft/libft.h"
//all fcts have less or equal to 25 lines !!!!
void put_flag(int *flag, int *i,int *start, char c)
{
    if(!*flag && (c == '\'' || c == '"'))
    {
        *flag = c;
        *start = ++(*i);
    }
    else if(*flag && *flag == c)
    {
        *flag = 0;
        *start = ++(*i);
    }
    
}
//25 lines
//I'm working with it
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
        // if(!flag && (str[i] == '\'' || str[i] == '"'))
        // {
        //     flag = str[i];
        //     start = ++i;
        // }
        // else if(flag && flag == str[i])
        // {
        //     flag = 0;
        //     start = ++i;
        // }
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
        // ptr = ft_substr(str, start, (i - start));
        new = ft_strjoin(new, ft_substr(str, start, (i - start)));
    }
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

//16 lines
 void handle_cmd(char ***tab)
 {
    char **cmd;
    char *ptr;
    int i;
    
    cmd = *tab;
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
 
 //22 lines
 void ft_remove(t_cmdfinal *cmd)
{
    t_cmdfinal *tmp;
    t_files *save;
    char *ptr;
    
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
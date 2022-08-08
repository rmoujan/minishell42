/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_expand.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmoujan <rmoujan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 23:01:07 by rmoujan           #+#    #+#             */
/*   Updated: 2022/08/08 14:14:19 by rmoujan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "libft/libft.h"

//21 lines
//now I am working on this version 28-07-2022 !!
char *get_value(char *ptr, char *const envp[])
{
    int i;
    char *new;
    char **tab;
    
    i = 0;
    new = ft_strdup("");
    while (envp[i])
    {
        if (strncmp(envp[i], ptr, ft_strlen(ptr))== 0)
        {
            tab = ft_split(envp[i], '=');
            free(tab[0]);
            free(ptr);
            free(new);
            free(tab);
            return (tab[1]);
        }
        i++;
    }
    free(ptr);
    return new;
}

// void chunk0_expand(char *str, int *i, int *start, char **new)
// {
//     char *ptr;

//     ptr = ft_substr(str, *start, (*i) - (*start));
//     *new = ft_strjoin(*new, ptr);
//     *start = *i;
// }

// void chunk1_expand(char *str, int *i, int *start, char **new)
// {
//     char *ptr;
    
//     if (str[*i + 1] != '\0' && str[*i + 1] == 48)
//     {
//         ptr = argv[0];
//         *new = ft_strjoin(*new, ptr);
//     }
//     else
//     {
//         ptr = ft_strdup("");
//         *new = ft_strjoin(*new, ptr);  
//     }
//     *start = *start + 2;
//     (*i)++; 
// }

// void chunk2_expand(char *str, int *i, int *start, char **new)
// {
//     char *ptr;
    
//     *start = ++(*i);
//     while (str[*i] != '\0' && (ft_isalnum(str[*i]) || str[*i] == '_'))
//         (*i)++;
//     ptr = ft_substr(str, *start, ((*i) - (*start)));
//     ptr = get_value(ptr, envp);
//     *new = ft_strjoin(*new, ptr);
//     *start = *i;
// }

// void chunk3_expand(char *str, int *i, int *start, char **new)
// {
//     char *ptr;
    
//     ptr = ft_itoa(g_state);
//     *new = ft_strjoin(*new, ptr);
//     *start = *start + 2;
//     *i = *i + 2;
// }

void flag_expand(char *str, int *i, int *flag)
{
    if(!*flag && (str[*i] == '\'' || str[*i] == '"'))
        *flag = str[*i];
    else if(*flag && *flag == str[*i])
        *flag = 0;
}
// void chunk4_expand(char *str, int *i, int *start, char **new)
// {
//     char *ptr;
    
//     (*i)++;
//     ptr = ft_substr(str, *start, *i - *start);
//     *new = ft_strjoin(*new, ptr);
// }
void ft_initializeexpand(int *i, int *flag, int *start, char **new)
{
    *start = 0;
    *flag = 0;
    *i = 0;
    *new = ft_strdup("");
}
//> 25 lines
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
        flag_expand(str, &i, &flag);
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
            ptr = ft_itoa(g_state);
            new = ft_strjoin(new, ptr);
            start += 2;
            i += 2;
        }
        else if (str[i] == '$' && (str[i + 1] == '\'' || str[i + 1] =='"'))
            start = ++i;
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

int check_dollar(char *str)
{
    int i ;
    int counter;
    i = 0;
    counter = 0;
    while (str[i] != '\0')
    {
        if (str[i] == '$')
            counter++;
        i++;
    }
    return counter;
}

char *change_emptystr(char **str)
{
    char *ptr;

    free(*str);
    ptr = ft_itoa(-1);
    return ptr;
}


//22 lines
void expand_cmd(char ***tab, char *const envp[], char *argv[])
{
    char **cmd;
    char *ptr;
    int i;
    
    i = 0;
    cmd = *tab;
    while (cmd[i] != '\0')
    {
        if (check_dollar(cmd[i]) != 0)
        {
            ptr = cmd[i];
            cmd[i] =  expand_dollar(cmd[i], envp, argv);
            if (cmd[i][0] == '\0')
                {
                    // free(cmd[i]);
                    // cmd[i] = ft_itoa(-1);
                   cmd[i] = change_emptystr(&cmd[i]);
                }
            else  if (cmd[i][0] == '"' && cmd[i][1] == '"' && cmd[i][2] == '\0')
                {
                    // free(cmd[i]);
                    // cmd[i] = ft_itoa(-1);
                    cmd[i] = change_emptystr(&cmd[i]);
                }
            else  if (cmd[i][0] == '\'' && cmd[i][1] == '\'' && cmd[i][2] == '\0')
                {
                    // free(cmd[i]);
                    // cmd[i] = ft_itoa(-1);
                    cmd[i] = change_emptystr(&cmd[i]);
                }
            free(ptr);   
        }
        i++;
    }
}

//starting new version of expand!!
//u have 3 cases that any token must be start : soit $ or " or ' 
//23 lines
void  ft_expand(t_cmdfinal *cmd, char *const envp[], char *argv[])
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
                if (tmp->file->id != 3)
                {
                    //check be3da if there is a dollar 3ad expandi if not no need to expand !!
                    ptr = tmp->file->name;
                    tmp->file->name = expand_dollar(tmp->file->name, envp, argv);
                    free(ptr);
                }
                tmp->file = tmp->file->next;
            }
            expand_cmd(&tmp->tab, envp, argv);
            tmp->file = save;
            tmp = tmp->next;
       }
}

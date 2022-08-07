/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_expand.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmoujan <rmoujan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 23:01:07 by rmoujan           #+#    #+#             */
/*   Updated: 2022/08/07 12:44:09 by rmoujan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "libft/libft.h"

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

//all cases of dollar !! leaks kaynin heennnnnnnnnnna !!!!!
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
    // printf("EXPAND DOLLLAR |%s|\n", str);
    while (str[i] != '\0')
    {
        // printf("inside expand \n");
        if(!flag && (str[i] == '\'' || str[i] == '"'))
            flag = str[i];
        else if(flag && flag == str[i])
            flag = 0;
        if (str[i] == '$')
        {
            // printf("if 1 \n");
            ptr = ft_substr(str, start, i - start);
            new = ft_strjoin(new, ptr);
            start = i;
        }
        if (str[i] == '$' && ft_isdigit(str[i + 1]) && flag != '\'')
        {
            // printf("if 2 \n");
            if (str[i + 1] != '\0' && str[i + 1] == 48)
            {
                //ptr = ft_strdup(argv[0]);
                ptr = argv[0];
                //printf("0 %s\n", ptr);
                new = ft_strjoin(new, ptr);
            }
            else
            {
                ptr = ft_strdup("");
                //printf("1--9 %s\n", ptr);
                new = ft_strjoin(new, ptr);
                
            }
            start += 2;
            i++;
        }
        else if (str[i] ==  '$' && ft_isalnum(str[i + 1]) && flag != '\'')
        {
            // printf("if 3 \n");
            start = ++i;
            while (str[i] != '\0' && (ft_isalnum(str[i]) || str[i] == '_'))
            {
                i++;
            }
            ptr = ft_substr(str, start, ((i) - start));
            //printf("PTR IS %s\n", ptr);
             ptr = get_value(ptr, envp);//
            //printf("value |%s|\n", ptr);
            new = ft_strjoin(new, ptr);
            start = i;
        }
        else if (str[i] == '$' && str[i + 1] == '?' && flag != '\'')
        {
            // printf("if 4 \n");
            //exit status of the last prg :   
            ptr = ft_itoa(g_state);
            // // printf("1--9 %s\n", ptr);
            new = ft_strjoin(new, ptr);
            start += 2;
            i += 2;
        }
         else if (str[i] == '$' && (str[i + 1] == '\'' || str[i + 1] =='"'))
        {
            // printf("if 5 \n");
            //when we meet $ and next char is " or ' , we must skip this $ !!!!
            start = ++i;
        }
        else if(str[i + 1] == '\0')
        {
            // printf("if 6 \n");
            i++;
            ptr = ft_substr(str, start, i - start);
            new = ft_strjoin(new, ptr);
        }
        else
        {
            // printf("if 7 \n");
            i++;
        }
        // printf("koko\n");
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

//31 lines
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
                    free(cmd[i]);
                    cmd[i] = ft_itoa(-1);
                }
            else  if (cmd[i][0] == '"' && cmd[i][1] == '"' && cmd[i][2] == '\0')
                {
                    free(cmd[i]);
                    cmd[i] = ft_itoa(-1);
                }
            else  if (cmd[i][0] == '\'' && cmd[i][1] == '\'' && cmd[i][2] == '\0')
                {
                    free(cmd[i]);
                    cmd[i] = ft_itoa(-1);
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

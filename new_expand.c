/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_expand.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmoujan <rmoujan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 23:01:07 by rmoujan           #+#    #+#             */
/*   Updated: 2022/08/04 18:53:29 by rmoujan          ###   ########.fr       */
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
            printf("===>> if 000000000000\n");
            tab = ft_split(envp[i], '=');
            free(tab[0]);
            free(ptr);
            free(new);
            free(tab);
            return (tab[1]);
        }
        printf("===>> else 000000000000\n");
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
    
    printf("EXPAND DOLLLAR |%s|\n", str);
    while (str[i] != '\0')
    {
        printf("inside expand \n");
        if(!flag && (str[i] == '\'' || str[i] == '"'))
            flag = str[i];
        else if(flag && flag == str[i])
            flag = 0;
        if (str[i] == '$')
        {
            printf("if 1 \n");
            ptr = ft_substr(str, start, i - start);
            new = ft_strjoin(new, ptr);
            start = i;
        }
        if (str[i] == '$' && ft_isdigit(str[i + 1]) && flag != '\'')
        {
            printf("if 2 \n");
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
            printf("if 3 \n");
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
            printf("if 4 \n");
            //exit status of the last prg :   
            ptr = ft_itoa(g_state);
            // // printf("1--9 %s\n", ptr);
            new = ft_strjoin(new, ptr);
            start += 2;
            i += 2;
        }
         else if (str[i] == '$' && (str[i + 1] == '\'' || str[i + 1] =='"'))
        {
            printf("if 5 \n");
            //when we meet $ and next char is " or ' , we must skip this $ !!!!
            start = ++i;
        }
        else if(str[i + 1] == '\0')
        {
            printf("if 6 \n");
            i++;
            ptr = ft_substr(str, start, i - start);
            new = ft_strjoin(new, ptr);
        }
        else
        {
            printf("if 7 \n");
            i++;
        }
        printf("koko\n");
    }
    //while (1);
    return new;
}

// //I'm now on this step !!!
// char *expand_dsq(char *str, int *i, char *const envp[], char *argv[])
// {
//     char flag;
//     int start;
//     start = 0;
//     // flag = str[*i];
//     while (str[*i] != '\0')
//     {
//         if (str[*i] == '"' || str[*i] == '\'')
//         {
//             flag = str[*i];
//             (*i)++;
//         }
//         start = *i;
//         while (str[*i] != '\0' && flag)
//         {
//             if (str[*i] == flag)
//             {
//                 flag = 0;
//                 break;
//             }
//             (*i)++;
//         }

//     }
//    return ""; 
// }

// // expand all files except heredoc :
// char *expand_files(char *str, char *const envp[], char *argv[])
// {
//     int i;
//     char *new;
//     char *ptr;
//     i = 0;
    
//     new = ft_strdup("");
//     while (str[i] != '\0')
//     {
//         // printf("before dollar\n");
//         //cheak_flag(str[i], &flag);
//         // if (str[i] == '$')
//         // {
//             // cases_expand_dollar(str, i, envp, argv);
//             ptr = expand_dollar(str, &i, envp, argv);
//             // printf("between dollar \n");
//             new = ft_strjoin(new, ptr);
//             // printf("after IS %s\n", new);
//         // }
//         // printf("after dollar\n");
//         // else if (str[i] == '"' || str[i] == '\'')
//         // {
//         //     ptr = expand_dsq(str, &i, envp, argv);
//         //     new = ft_strjoin(new, ptr);
//         // }!!!
//         // else if(str[i] == '\'')
//         // {
//         //     ptr = expand_sq(str, &i, envp, argv);
//         //     new = ft_strjoin(new, ptr);
//         // }
//         // i++;
//     }
//     return new;
// }
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
            printf("inside check dollar \n");
            ptr = cmd[i];
            cmd[i] =  expand_dollar(cmd[i], envp, argv);
            if (cmd[i][0] == '\0')
                {
                    printf(" 2 0 2 2 \n");
                    free(cmd[i]);
                    cmd[i] = ft_itoa(-1);
                }
            else  if (cmd[i][0] == '"' && cmd[i][1] == '"' && cmd[i][2] == '\0')
                {
                    printf(" 2 0 2 2 \n");
                    free(cmd[i]);
                    cmd[i] = ft_itoa(-1);
                }
            else  if (cmd[i][0] == '\'' && cmd[i][1] == '\'' && cmd[i][2] == '\0')
                {
                    printf(" 2 0 2 2 \n");
                    free(cmd[i]);
                    cmd[i] = ft_itoa(-1);
                }
            // printf("====>> %s\n", cmd[i]);
            free(ptr);   
        }
        i++;
    }
}

//starting new version of expand!!
void  ft_expand(t_cmdfinal *cmd, char *const envp[], char *argv[])
{
       //u have 3 cases that any token must be start : soit $ or " or ' 
       t_cmdfinal *tmp;
       t_files *save;
       char *ptr;

       tmp = cmd;
       while (tmp)
       {
            //printf("FIRST WHILE \n");
            save = tmp->file;
            while (tmp->file)
            {
                // printf("00 %s\n", tmp->file->name);
                // printf("1111 \n");
                if (tmp->file->id != 3)
                {
                    //check be3da if there is a dollar 3ad expandi if not no need to expand !!
                    // if (check_dollar(tmp->file->name) != 0)
                    // {
                        // free(tmp->file->name);//!!
                        ptr = tmp->file->name;
                        tmp->file->name = expand_dollar(tmp->file->name, envp, argv);
                    free(ptr);//!!
                }
                tmp->file = tmp->file->next;
                //printf("222\n");
            }
            expand_cmd(&tmp->tab, envp, argv);
            tmp->file = save;
            tmp = tmp->next;
       }
    //printf("END WHILE \n");
    //return cmd;
}
// << $END cat -e >> $0USER | < $1PATH ls -la > $HOME
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_expand.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmoujan <rmoujan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 21:21:51 by rmoujan           #+#    #+#             */
/*   Updated: 2022/07/28 12:57:21 by rmoujan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "minishell.h"
// #include "libft/libft.h"

// char *get_value(char *str, char *const envp[])
// {
//     int i = 0;
//     char *ptr;
//     char **tab;

//     ptr = (str) + 1;// to give us the pointer a artit mn str[1] not str[0] !!
//     // printf("** {%s}\n", ptr);
//     while (envp[i])
//     {
//         if (strncmp(envp[i], ptr, ft_strlen(ptr))== 0)
//         {
//             tab = ft_split(envp[i], '=');
//             free(tab[0]);
//             // free(str);
//             // printf(" 00 %s\n", tab[1]);
//             return (tab[1]);
//         }
//         i++;
//     }
//     return NULL;
// }

// //cheak the start of token, I think I have just these cases !!!
// int cheak_start(char *str)
// {
//     if (strncmp(str, "\"", 1) == 0)
//     {
//         return 1;
//     } 
//     else if (strncmp(str, "'", 1) == 0)
//     {
//         return 2;
//     }
//     if (strncmp(str, "$", 1) == 0)
//     {
//         return 3;
//     }
//     return 0;
// }

// // char *expand_dollar(char *str, int id, char *const envp[])
// // {
// //     int i ;
// //     char *ptr;
// //     i = 0;
    
// //     if (id == 3)
// //     {
// //         ptr = get_value(str, envp);
// //     }
// //     return ptr;
// // }

// // expand all files except heredoc :
// char * expand_files(t_files *node, char *const envp[])
// {
//     int flag1;
//     int flag2;
//     int  id;
    
//     if (cheak_start(node->name) != 0)
//     {
//         id = cheak_start(node->name);
//         if (id == 3)
//         {
//             return (get_value(node->name, envp));
//             // return (expand_dollar(node->name, id, envp));
//         }
//     }  
//     return NULL;
// }
// void expand_cmd(char ***tab, char *const envp[])
// {
//     char **cmd;
//     int id;
//     cmd = *tab;
//     int i;
//     i = 0;
//     while (cmd[i] != NULL)
//     {
//         if (cheak_start(cmd[i]) != 0)
//         {  
//             id = cheak_start(cmd[i]);
//             if (id == 3)
//             {
//                return (get_value(cmd[i], envp)); 
//             }
            
//         }
//     }
    
// }
// //starting new version of expand!!
// t_cmdfinal * ft_expand(t_cmdfinal *cmd, char *const envp[], char *argv[])
// {
//        //u have 3 cases that any token must be start : soit $ or " or ' 
//        t_cmdfinal *tmp;
//        t_files *save;
//        char *ptr;

//        tmp = cmd;
//        while (tmp)
//        {
//             printf("FIRST WHILE \n");
//             save = tmp->file;
//             while (tmp->file)
//             {
//                 if (tmp->file->id != 3)
//                 {
//                     ptr = tmp->file->name;
//                     tmp->file->name = expand_files(tmp->file, envp);
//                     free(ptr);
//                 }
//                 tmp->file = tmp->file->next;
//             }
//             expand_cmd(&tmp->tab, envp);
//             tmp->file = save;
//             tmp = tmp->next;
//        }
//        printf("END WHILE \n");
//        return cmd;
// }

// // //expand all variables that inside " " ==> old version !!
// char *ft_expand(char *str, char *const envp[], char *argv[])
// {
//     int i;
//     int flag;
//     int start;
//     char *ptr1;
//     char *ptr2;
//     i = 0;
//     ptr1 = ft_strdup("");
//     ptr2 = ft_strdup("");
//     flag = 0;
//     start = 0;
//     while (str[i] != '\0')
//     {
//         if(!flag && (str[i] == '\'' || str[i] == '"'))
//             flag = str[i];
//         else if(flag && str[i] == flag)
//                 flag = 0;
//         if (str[i] == '$' && str[i + 1] != '\0' && str[i + 1] == 48)
//         {
//             ptr2 = ft_strjoin(ptr2, argv[0]);
//             //printf("|%s|\n", ptr2);
//             i = i + 2;
//             start = i;
//             printf("if 1\n");
//             //printf("{%c}\n", str[i]);
//         }
//         else if (str[i] == '$' && str[i + 1] != '\0' && str[i + 1] >= 49 && str[i + 1] <= 57)
//         {
//             // ptr2 = ft_strjoin(ptr2, argv[0]);
//             // printf("|%s|\n", ptr2);==
//             i = i + 2;
//             start = i;
//             printf("if 2\n");
//             // printf("{%c}\n", str[i]);
//         }
//         //exit status ::
//         else if (str[i] == '$' && str[i + 1] != '\0' && str[i + 1] == '?')
//         {
//             ptr2 = ft_strjoin(ptr2, ptr1);
//             // printf("|%s|\n", ptr2);
//             i = i + 2;
//             start = i;
//             printf("if 3\n");
//             // printf("{%c}\n", str[i]);
//         }
//         else if(str[i] == '$' && flag != '\'')
//         {
//             ptr1 = ft_substr(str, start, (i - start));
//             // ptr1 = get_value(&ptr1, envp);
//             // printf("%s\n", ptr1);
//             ptr2 = ft_strjoin(ptr2, ptr1);
//             // printf("%s\n", ptr2);
//             start = i + 1;
//             printf("if 4\n");
//         }
//         if (flag != '\'' && str[i] == '$' && str[i + 1] !=  '\0' && ft_isalpha(str[i + 1]))
//         {
//             //printf("+%c+\n", str[i]);
//             start = i++;
//             while  (str[i] != '\0' && (ft_isalnum(str[i]) || str[i] == '_'))
//             {
//                 i++;
//             }
//             ptr1 = ft_substr(str, start, (i - start));
//             ptr1 = get_value(&ptr1, envp);
//             ptr2 = ft_strjoin(ptr2, ptr1);
//             start = i;
//             printf("if 5\n");
//         }
//         if(str[i + 1] == '\0')
//             ptr2 = ft_strjoin(ptr2, ft_substr(str, start, ((i + 1) - start)));
//         i++;
//     }
//     printf("ptr2 is |%s|\n", ptr2);
//     return (ptr2);
// }
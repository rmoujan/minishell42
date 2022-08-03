/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_space.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmoujan <rmoujan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 17:08:09 by rmoujan           #+#    #+#             */
/*   Updated: 2022/08/03 10:22:49 by rmoujan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "libft/libft.h"

// //old version
// // 3andke had case """""""'''''""""" cat --> had les fctes kay7ydo ta space li bin "  and cat !!!!!
// //check if there are any spaces inside " " to replace them with -2
// //stilll need mora works  fash kankter """"'''  kaykhser kolshi !!!!!
// void replace_space_double(char **ptr)
// {
//     int i;
//     char *str;
    
//     i = 0;
//     str = *ptr;
//     //I replace each | that inside " " with -2 !!!!!
//     printf("before :: REPLACE SPACE DOUBLE |%s|\n", str);
//     while (str[i] != '\0')
//     {
//         if (str[i] == '"')
//         {
//             i++;
//             while (str[i] != '\0' && str[i] != '"')
//             {
//                 if (str[i] == ' ')
//                 {
//                     // printf("IF\n");
//                     str[i] = -2;
//                 }
//                 i++;
//             }
//         }
//         i++;
//     }
//     printf("AFATER ::: REPLACE SPACE DOUBLE |%s|\n", str);
// }


//new version
void replace_space_double(char **ptr)
{
    int i;
    int flag;
    char *str;
    
    i = 0;
    str = *ptr;
    flag = 0;
    //I replace each space that inside " " with -2 !!!!!
    printf("before :: REPLACE SPACE DOUBLE |%s|\n", str);
    while (str[i] != '\0')
    {
        if(!flag && (str[i] == '\'' || str[i] == '"'))
            flag = str[i];
        else if(flag && flag == str[i])
            flag = 0; 
        if (str[i] == ' ' && flag)
            str[i] = -2;
        i++;
    }
    printf("AFATER ::: REPLACE SPACE DOUBLE |%s|\n", str);
}

// //check if there are any space inside ' ' to replace them with -2
// void replace_space_single(char **ptr)
// {
//     int i;
//     char *str;
    
//     i = 0;
//     str = *ptr;
//     //I replace each | that inside " " with -2 !!!!!
//     while (str[i] != '\0')
//     {
//         if (str[i] == '\'')
//         {
//             i++;
//             while (str[i] != '\0' && str[i] != '\'')
//             {
//                 if (str[i] == ' ')
//                 {
//                     // printf("IF\n");
//                     str[i] = -2;
//                 }
//                 i++;
//             }
//         }
//         i++;
//     }
// }


//old version 
//replace -2 inside " " with space
// void return_space_double(char **str1)
// {
//     int i;
//     i = 0;
//     char *str;
//     str = *str1;
//     //I replace each | that inside " " with -2 !!!!!
//     while (str[i] != '\0')
//     {
//         if (str[i] == '"')
//         {
//             i++;
//             while (str[i] != '\0' && str[i] != '"')
//             {
//                 if (str[i] == -2)
//                 {
//                     // printf("return pipe IF\n");
//                     str[i] = ' ';
//                 }
//                 i++;
//             }
//         }
//         i++;
//     }
// }

void return_space_double(char **str1)
{
    int i;
    int flag;
    char *str;
    
    str = *str1;
    flag = 0;
    i = 0;
    //I replace each -2 that inside " " with space !!!!!
    while (str[i] != '\0')
    {
        if(!flag && (str[i] == '\'' || str[i] == '"'))
            flag = str[i];
        else if(flag && flag == str[i])
            flag = 0; 
   
        if (str[i] == -2 && flag)
            str[i] = ' ';
        i++;
    }
}

// //replace -2 inside ' ' with space
// void return_space_single(char **str1)
// {
//     int i;
//     i = 0;
//     char *str;
//     str = *str1;
//     //I replace each | that inside " " with -2 !!!!!
//     while (str[i] != '\0')
//     {
//         if (str[i] == '\'')
//         {
//             i++;
//             while (str[i] != '\0' && str[i] != '\'')
//             {
//                 if (str[i] == -2)
//                 {
//                     // printf("IF\n");
//                     str[i] = ' ';
//                 }
//                 i++;
//             }
//         }
//         i++;
//     }
// }

t_command *split_space(char **cmds)
{
    int i;
    char **data;
    t_command *head;
    t_command *tmp;
    t_command *node;
    // int j;
    i = 0;
    // mn lhena khaski t cree node lkebira t_command !!!!
    while (cmds[i])
    {
        //printf("[%s]\n", cmds[i]);
        replace_space_double(&cmds[i]);//00
        //replace_space_single(&cmds[i]);//00
        // printf("--> %s\n", cmds[i]);
        data = ft_split(cmds[i], ' ');
        // j = 0;
        // while (data[j])
        // {
        //     printf("000 %s\n", data[j]);
        //     j++;
        // }
        //khasni nekhdem 3la la partie deyal linked list !!!!!!
        node = create_cmd(data);
        //linked each node cmd with the next !!!
        if (i == 0)
        {
            head = tmp = node;
        }
        else
        {
            tmp->next = node;
		    tmp = node;
        }
        // printf("i is %d\n", i);
        free_lines(data);
        i++;
    }
    // printf("--> %s\n", data[i]);
    tmp->next = NULL;
    // ft_output(head);
    // while (1); 
    return head;
}
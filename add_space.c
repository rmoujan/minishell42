/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_space.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmoujan <rmoujan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 16:42:59 by rmoujan           #+#    #+#             */
/*   Updated: 2022/08/03 10:25:55 by rmoujan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "libft/libft.h"

int check_redirects(char c)
{
    if (c == '<' || c == '>')
    {
        return 1;
    }
    return 0;
}
//vers1 not working !!
// int ft_counterspace(char *ptr)
// {
//     int i;
//     int counter;
    
//     i = 0;
//     counter = 0;
//     while (ptr[i] != '\0')
//     {
//         if (check_redirects(ptr[i]) && ptr[i + 1] != '\0' && ptr[i + 1] != ' ')
//         {
//             if (check_redirects(ptr[i + 1]) && ptr[i + 2] != '\0' && ptr[i + 2] != ' ')
//             {
//                 printf("++ check\n");
//                 counter++;
//                 i++;
//             }
//             else if (!check_redirects(ptr[i + 1]) && ptr[i + 1] != ' ')
//             {
//                printf("-- check\n"); 
//                 counter++;
//             }
//         }
        
//         i++;
//     }
//     return counter;
// }


//vers 2::
// //counter space in front of < >, seems is working !!!
int ft_counterspace_front(char *ptr)
{
    int i;
    int counter;
    
    i = 0;
    counter = 0;
    // printf("FRONT\n");
    while (ptr[i] != '\0')
    {
        if (check_redirects(ptr[i]))
        {
            printf("counter space front\n");
            if (ptr[i + 1] != '\0' && ptr[i + 1] != ' ' && !check_redirects(ptr[i + 1]))
            {
                counter++;
            }
        }
        i++;
    }
    return counter;
}

//counter space in back of < > 
//vers 1::seems is working !!!
int ft_counterspace_back(char *ptr)
{
    int i;
    int counter;
    
    i = 0;
    counter = 0;
    // printf("BACK \n");
    while (ptr[i] != '\0')
    {
        if (check_redirects(ptr[i]))
        {
            if (i != 0)
            {
                printf("counter space back \n");
                if (ptr[i - 1] != '\0' && ptr[i - 1] != ' ' && !check_redirects(ptr[i - 1]))
                {
                    counter++;
                }
            }
        }
        i++;
    }
    return counter;
}

char  *ft_copy1(char *ptr)
{
    char *new;
    int flag;
    int i;
    int j;
    
    i = 0;
    j = 0;
    flag = 0;
    new = (char *)malloc(sizeof(char) * (ft_strlen(ptr) + ft_counterspace_front(ptr) + 1));
    while (ptr[i] != '\0')
    {
        new[j++] = ptr[i];
        if(!flag && (ptr[i] == '\'' || ptr[i] == '"'))
            flag = ptr[i];
        else if(flag && ptr[i] == flag)
            flag = 0;
        if (check_redirects(ptr[i]) && !flag)
        {
            printf("copy 1 \n");
            if (ptr[i + 1] != '\0' && ptr[i + 1] != ' ' && !check_redirects(ptr[i + 1]))
                {
                    new[j++] = ' ';
                }
        }
        i++;
    }
    new[j] = '\0';
    return new;
}

void ft_copy2(char **str, char *ptr)
{
    char *new;
    int i;
    int j;
    new = *str;
    int flag = 0;
    
    i = 0;
    j = 0;
    while (ptr[i] != '\0')
    {
        if(!flag && (ptr[i] == '\'' || ptr[i] == '"'))
            flag = ptr[i];
        else if(flag && ptr[i] == flag)
            flag = 0;
        if (check_redirects(ptr[i]) && !flag)
        {
            printf("copy 2 \n");
            if (i != 0)
            {
                if (ptr[i - 1] != '\0' && ptr[i - 1] != ' ' && !check_redirects(ptr[i - 1]))
                {
                    new[j++] = ' ';
                }
            }
        }
        new[j++] = ptr[i];
        i++;
    }
    new[j] = '\0';
}

//example : <inf cat -e >out1 | << end ls -la >> out2
char *ft_addspace(char *ptr)
{
    int i;
    int len;
    char *new;
    char *str;
    // char *p;
    
    i = 0;
    len  = 0;
    printf("before add space \n");
    //is how many spaces that I should add in my new input user !!!
    len = ft_counterspace_front(ptr) + ft_counterspace_back(ptr);
    // len = ft_counterspace_front(ptr);
    new = (char *)malloc(sizeof(char) * (ft_strlen(ptr) + len + 1));
    str = ft_copy1(ptr);
    // printf("+++ |%s|\n", str);
    ft_copy2(&new, str);
    free(str);
    printf("after add space \n");
    // printf("NEW : \n");
    // printf("*** |%s|\n", new);
    // while (new[i])
    // {
    //     printf("%c\n", new[i]);
    //     i++;
    // }
    //printf("===> NEW STR : %s\n", new);
    return new;
} 

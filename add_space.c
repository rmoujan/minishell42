/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_space.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmoujan <rmoujan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 16:42:59 by rmoujan           #+#    #+#             */
/*   Updated: 2022/08/07 16:53:33 by rmoujan          ###   ########.fr       */
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

//vers 2::
// //counter space in front of < >, seems its working !!!
int ft_counterspace_front(char *ptr)
{
    int i;
    int counter;
    
    i = 0;
    counter = 0;
    while (ptr[i] != '\0')
    {
        if (check_redirects(ptr[i]))
        {
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
//vers 1::seems its working !!!
int ft_counterspace_back(char *ptr)
{
    int i;
    int counter;
    
    i = 0;
    counter = 0;
    while (ptr[i] != '\0')
    {
        if (check_redirects(ptr[i]))
        {
            if (i != 0)
            {
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

//26 lines !!
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

//29 lines
void ft_copy2(char **str, char *ptr)
{
    char *new;
    int i;
    int j;
    int flag;
    
    i = 0;
    j = 0;
    flag = 0;
    new = *str;
    while (ptr[i] != '\0')
    {
        if(!flag && (ptr[i] == '\'' || ptr[i] == '"'))
            flag = ptr[i];
        else if(flag && ptr[i] == flag)
            flag = 0;
        if (check_redirects(ptr[i]) && !flag)
        {
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

int isredirect_exist(char *ptr)
{
    int i;
    
    i = 0;
    while (ptr[i] != '\0')
    {
        if (check_redirects(ptr[i]) == 1)
            return 1;
    i++;
    }
    return 0;
}

//17 lines !!!!
char *ft_addspace(char *ptr)
{
    int i;
    int len;
    char *new;
    char *str;
    
    i = 0;
    len  = 0;
    // First of all check is the cmd line contain a redirect or not 
    if (isredirect_exist(ptr) == 1)
    {
        // printf(" 123456789   add space \n");
        //is how many spaces that I should add in my new input user !!!
        len = ft_counterspace_front(ptr) + ft_counterspace_back(ptr);
        new = (char *)malloc(sizeof(char) * (ft_strlen(ptr) + len + 1));
        str = ft_copy1(ptr);
        ft_copy2(&new, str);
        free(str);
        return new;
    }
    return ft_strdup(ptr);
} 

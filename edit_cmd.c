/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   edit_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmoujan <rmoujan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 18:43:24 by rmoujan           #+#    #+#             */
/*   Updated: 2022/08/07 18:02:35 by rmoujan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "libft/libft.h"

//all fcts have less or equal to 25 lines !!!!
// check is the tab of cmd contains -1 or not
int ft_check_null(char **tab)
{
    int i;

    i = 0;
    while (tab[i])
    {
        if (strcmp(tab[i], "-1") == 0)
            return 1;
        i++;
    }
    return 0;
}
//19 lines
char **allocate_cmd(int len, char **cmd)
{
    char **tab;
    int i;
    int j;
    
    i = 0;
    j = 0;
    tab = (char **)malloc(sizeof(char *) * (len + 1));
    if (tab ==  NULL)
        printf("NULL\n");
    while (cmd[i])
    {
        if (strcmp(cmd[i], "-1") != 0)
        {
            tab[j++] = ft_strdup(cmd[i]);
        }
        i++;
    }
    tab[j] = NULL;
    return tab;
}

//24 lines
//clacul how many lines in cmd tab without counting lines that contains -1 !!
void  edit_cmd(t_cmdfinal *cmd)
{
    t_cmdfinal *tmp;
    char **ptr;
    int i;
    int count;
    
    tmp = cmd;
    while (tmp)
    {
        i = 0;
        count = 0;
        if (ft_check_null(tmp->tab) == 1)
        {
            while (tmp->tab[i])
            {
                if (strcmp(tmp->tab[i], "-1") != 0)
                    count++;
                i++;
            }
            ptr = tmp->tab;
            tmp->tab = allocate_cmd(count,tmp->tab);
            free_lines(ptr);
        }
        tmp = tmp->next;
    }
}


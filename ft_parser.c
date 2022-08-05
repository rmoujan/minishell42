/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmoujan <rmoujan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 13:11:57 by rmoujan           #+#    #+#             */
/*   Updated: 2022/08/05 12:25:22 by rmoujan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "libft/libft.h"

// give each red an id !!!
int is_redirect(char *str)
{
    if (ft_strcmp(str, "<") == 0)
    {
        return 1;
    }
    else if (ft_strcmp(str, ">") == 0)
    {
        return 2;
    }
    else if (ft_strcmp(str, "<<") == 0)
    {
        return 3;
    }
    else if (ft_strcmp(str, ">>") == 0)
    {
        return 4;
    }
    return 0;
}

int counte_linecmd(t_command *node)
{
    t_command *tmp;
    t_token *save;
    int counter;
    
    counter = 0;
    tmp = node;
    save = tmp->data;
    while (tmp->data)
    {
        //cheak if there is rederict
        if (is_redirect(tmp->data->token) != 0)
        {
            tmp->data = tmp->data->next;
        }
        else
        {
            counter++;
        }
        tmp->data = tmp->data->next;
    }
    node->data = save;
    return counter;
}

//create node final !!!
t_cmdfinal *create_node_final(t_command *node)
{
    t_cmdfinal *head;
    int len;
    
    //create node global !!!
    head = (t_cmdfinal *)malloc(sizeof(t_cmdfinal));
    if (head == NULL)
    {
        printf("the pointer does not allocated properly\n");
        exit(1);
    }
    //allocate for tab that will contains name cmd and its args !!
    len = counte_linecmd(node);
    head->tab = (char **) malloc(sizeof (char *) * (len + 1));
    if (head->tab == NULL)
    {
        printf("the pointer does not allocated properly\n");
        exit(1);
    }
    return head;
}

//create file of node final :
t_files *create_file(char *str, int id)
{
    t_files *node;

    node = (t_files *)malloc(sizeof(t_files));
    if (node == NULL)
    {
         printf("the pointer does not allocated properly\n");
         exit(1);
    }
    node->name = ft_strdup(str);
    node->id = id;
    return node; 
}

//38 lines
void iterate_tokens(t_token *tmp, t_cmdfinal *head)
{
    t_files *file;
    t_files *pointer;
    int i;
    int j;
    int id;
    
    i = 0;
    j = 0;
    while (tmp)
    {
        //check if there is rederict
        if (is_redirect(tmp->token) != 0)
        {
            id = is_redirect(tmp->token);
            if (tmp->next != NULL)
            {
                tmp = tmp->next;
                file = create_file(tmp->token, id);
                if (j == 0)
                {
                    head->file = pointer = file;
                }
                else if (j != 0)
                {
                    pointer->next = file;
                    pointer = file;
                }
                j++;
            }
        }
        else
            head->tab[i++] = ft_strdup(tmp->token);
        tmp = tmp->next;
    }
    if (file != NULL)
        file->next = NULL;
    if (j == 0)
        head->file = NULL;
    head->tab[i] = NULL;
} 


//there are some leaks in this fct !!!!
//preparing token into linked list the send them to executor
//create cmd global .. I think , it will works !!!
//NOTE : te9dery mn lhena t7tafdi b dak tmp->data (head) .. I'll cheak this later !!!
//29 lines
t_cmdfinal *ft_parser(t_command *node)
{
    t_command *tmp;
    t_cmdfinal *head;
    t_cmdfinal *pointer;
    t_cmdfinal *final;
    t_token *save;
    int j;
    
    tmp = node;
    j = 0;
    while (tmp)
    {
        //save the head of tokens of each node 
        save = tmp->data;
        pointer = create_node_final(tmp);
        if (j == 0)
        {
            head = final = pointer;
        }
        else
        {
            final->next = pointer;
            final = pointer;
        }
        printf("before iterate tokens !!! \n");
        iterate_tokens(tmp->data, pointer);
        printf("afeeeeer iterate tokens !!! \n");
        tmp->data = save;
        tmp = tmp->next;
        j++;
    }
    pointer->next = NULL;
    return (head);
}
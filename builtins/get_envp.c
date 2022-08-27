/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_envp.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmoujan <rmoujan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 14:22:19 by lelbakna          #+#    #+#             */
/*   Updated: 2022/08/27 18:53:49 by rmoujan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"
#include "../libft/libft.h"

void	creat_node(t_node **head, char *data)
{
	t_node	*new;
	t_node	*last_node;

	new = (t_node *)malloc(sizeof(t_node));
	if (!new)
		return ;
	new->data = ft_strdup(data);
	new->next = NULL;
	if (*head == NULL)
		*head = new;
	else
	{
		last_node = *head;
		while (last_node->next != NULL)
		{
			last_node = last_node->next;
		}
				last_node->next = new;
	}
	// free(new);//**
}

t_node	*get_envp(char **envp)
{
	int		i;
	t_node	*head;

	head = NULL;
	i = 0;
	while (envp[i] != NULL)
	{
		creat_node(&head, envp[i]);
		i++;
	}
	// cmd_final->envp = head;
	return (head);
}

int	ft_lssize(t_node *lst)
{
	int	i;

	i = 0;
	while (lst != NULL)// segfault
	{
		i++;
		lst = lst->next;
	}
	// if (i == 0)
	// 	perror("env");
	return (i);
}

void ft_env(t_cmdfinal **cmd_final)
{
	t_node	*tmp;
	t_cmdfinal *list;
	int		j;
	int		i;
	i = 0;
	list = (*cmd_final);
	tmp = *(*cmd_final)->envp;//lk
	// if (tmp == NULL)
	// {
	// 	printf("all is done ");
	// 	exit(1);
	// }
	j = ft_lssize(tmp);
	(*cmd_final)->env = (char **)malloc((sizeof(char*) * (j + 1)));// check + 1 if not segfault// here
	if (!(*cmd_final)->env)
		return;
	while (tmp)
	{
		(*cmd_final)->env[i] = tmp->data; //remove strdup ==>(*cmd_final)->env[i] = ft_strdup(tmp->data);
		i++;
		tmp = tmp->next;
	}
	(*cmd_final)->env[i] = NULL;
	while (list)
	{
		list->env = (*cmd_final)->env;
		list = list->next;
	}
	return;
}